// Copyright (c) 2025 Alex313031.

#ifndef PICALC_H_
#define PICALC_H_

#include <cmath>
#include <string>

#ifndef power
 #define power pow
#endif // #ifndef power

#ifndef LOG
 #define LOG() std::cout
#endif // #ifndef power

#ifndef quad
 typedef __float128 quad;
#endif // #ifndef quad

namespace picalc {
 class PiCalc;
}

// Universal reference to Pi
quad pi;

// string-able result from pi
long double piResult;
// How many places to print Pi to
int precision;
// How many times to run the algorithm recursively. Affects accuracy.
int iterations;
// Status Code for main(void) to return
int statusCode;
// Bool storing whether --test or -t was provided at the cmdline
bool testFlag;
// For toggling tests internally
constexpr bool internalTestFlag = false;
// String containing space-delimited cmdline args list
std::string commandLineStr = "";

// Our own factorial function
//quad factorial(int n);
// Where the magic happens
quad calculatePi(int iterations);
// Parse args, and dispatch correct function
bool handleArgs(int argc, const std::string args);
// External function for usage in other C++ files, or as a dynamic library
bool resultProvider(int iterations, int precision, bool exportPi);
// Handles low level printing to the console
void printerImpl(int iterations, int precision);

// Class for future usage
class PiCalc {

 public:

 private:
  // Shouldn't be used outside this file
  //quad factorial(int n);
};

//}

// int main(void);

#endif // PICALC_H_
