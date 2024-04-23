#pragma once

#include <iostream>
#include <random>

// #include "lcg.hpp"

class MonteCarlo {
  private:
    uint64_t numRandomValues;
    uint64_t decimalPrecision;
    bool usingPrecision = false;
    
    double target = 3.14159'26535'89793'23846'26433'83279'50288;
  public:
    MonteCarlo();
    void run();
    
    void setParams(uint64_t numRnd, uint64_t prec, bool usingPrec);
  
  private:
    bool validateDistance(double x, double y, double criteria = 1.0f);
    uint16_t checkPrecision(double a, double b);
    bool hasFinished(double currentResult);
};