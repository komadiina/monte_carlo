#include <iostream>

#include "./libs/montecarlo.hpp"

int main() {
  int numRandValues = -1, precisionThreshold = -1;
  
  std::cout << "[1] - Define the amount of (pseudo) random-generated values" << "\n[2] - Define the decimal precision threshold" << "\n > ";
  
  int sel;
  std::cin >> sel;
  std::cin.ignore();
  
  if (sel == 1) {
    std::cout << "Num. of PRNG values: ";
    std::cin >> numRandValues;
    std::cin.ignore();
  } 
  else if (sel == 2) {
    std::cout << "Precision threshold: ";
    std::cin >> precisionThreshold;
    std::cin.ignore();
  }
  else {
    std::cerr << "Invalid input, exiting...";
    return 1;
  }
  
  MonteCarlo sim;
  sim.setParams(
    numRandValues == -1 ? 0 : numRandValues,
    precisionThreshold == -1 ? 0 : precisionThreshold,
    numRandValues == -1 ? true : false
  );
  
  std::cout << "Running simulation..." << std::endl;
  sim.run();
  return 0;
}