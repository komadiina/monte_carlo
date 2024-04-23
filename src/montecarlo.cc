#include "../libs/montecarlo.hpp"

MonteCarlo::MonteCarlo() {}

void MonteCarlo::run() {
  std::cout << (usingPrecision ? "[SIM] Using precision" : "[MC] Using limited amount of PRNG values") << std::endl;
  
  double result = 0.0f;
  uint64_t nHit = 0ULL, nMiss = 0ULL;
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(0.0, 1.0);
  
  // pi = 4 * r
  while (!hasFinished(result)) {
    validateDistance(dist(gen), dist(gen), 1.0f) ? nHit++ : nMiss++;
    result = 4 * (double)(nHit) / (double)(nHit + nMiss);
    numRandomValues--;
    
    // std::printf(
    //   "nHit: %u, nMiss: %u, nTotal: %u, result: %lf\n", 
    //   nHit, nMiss, nMiss + nHit, result);
  }
  
  std::cout << "Result: " << result << std::endl;
  std::cout << "Iterations taken: " << nMiss + nHit << std::endl;
}

void MonteCarlo::setParams(uint64_t numRnd, uint64_t prec, bool usingPrec) {
  numRandomValues = numRnd;
  decimalPrecision = prec;
  usingPrecision = prec;
}

bool MonteCarlo::validateDistance(double x, double y, double criteria) {
  return std::sqrt(x*x + y*y) < criteria;
}  

uint16_t MonteCarlo::checkPrecision(double a, double b) {
  uint16_t decimals = 0U;
  bool differs =  static_cast<int64_t>(a * 10) 
                  != static_cast<int64_t>(b * 10); 
  
  while (!differs) {
    decimals++;
    a *= 10;
    b *= 10;
    
    differs = static_cast<int64_t>(a * 10) 
              != static_cast<int64_t>(b * 10); 
  }
  
  return decimals;
}

bool MonteCarlo::hasFinished(double currentResult) {
  return usingPrecision ? 
    checkPrecision(currentResult, target) >= decimalPrecision 
    : numRandomValues <= 0;
}