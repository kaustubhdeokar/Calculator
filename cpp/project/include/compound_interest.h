#ifndef COMPOUND_INTEREST_H
#define COMPOUND_INTEREST_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT double calculateCompoundInterest(double principal, double rate, int times, int years);
}

#endif // COMPOUND_INTEREST_H