#include "compound_interest.h"
#include <cmath>

extern "C" {
    DLL_EXPORT double calculateCompoundInterest(double principal, double rate, int times, int years) {
        return principal * std::pow(1 + rate / times, times * years);
    }
}