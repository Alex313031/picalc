// Copyright (c) 2025 Alex313031.

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

#include "picalc.h"
#include "picalc_constants.h"

// Function to calculate factorial
static quad factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

// Chudnovsky algorithm for calculating Pi to arbitrary floating point
quad calculatePi(int iterations) {
  quad picalc = 0;
  for (int k = 0; k < iterations; ++k) {
    picalc += (power(-1, k) * factorial(6 * k) * (13591409 + 545140134 * k)) /
          (factorial(3 * k) * power(factorial(k), 3) * power(640320, 3 * k + 1.5));
  }
  picalc = 12.0 * picalc;
  picalc = 1.0 / picalc;
  return picalc;
}

bool handleArgs(int argc, const std::string args) {
  const int numArgs = argc - 1;
  if (argc > 1) {
    LOG() << "Note: Got " << numArgs  << " arguments: ";
    LOG() << args << std::endl;

    const char* _testArgv1 = testString1.c_str();
    const char* _testArgv2 = testString2.c_str();
    const char* _argsChar = args.c_str();

    if (internalTestFlag) {
      LOG() << _testArgv1 << std::endl;
      LOG() << _testArgv2 << std::endl;
      LOG() << _argsChar << std::endl;
    }
    if (args.find(testString1) != std::string::npos
       ||args.find(testString2) != std::string::npos) {
      LOG() << "test string found" << std::endl;
    }
    
    if (strcmp(_argsChar, _testArgv1) == 0
       || strcmp(_argsChar, _testArgv2) == 0) {
      testFlag = true;
    }
  } else {
    testFlag = false;
  }
  return testFlag;
}

// To be used to provide results "externally" through member functions,
// and truly externally via dynlib/DLL support!
bool resultProvider(int iterations, int precision, bool exportPi) {
  if (exportPi) {
    pi = calculatePi(iterations);
    piResult = pi;
    LOG() << std::fixed << std::setprecision(precision);
    LOG() << "\n" << __func__ << "() Pi to " << precision << " : " << piResult << std::endl;
    return true;
  } else {
    LOG() << std::endl;
    return false;
  }
}

void printerImpl(int iterations, int precision) {
  // Calculate Pi
  pi = calculatePi(iterations);
  piResult = pi;
  // Set output precision
  LOG() << std::fixed << std::setprecision(precision);
  LOG() << "\nPi, to " << iterations << " length is: ";
  LOG() << piResult << std::endl;
}

// We all need a main, don't we?
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    commandLineStr.append(argv[i]).append(" ");
  }
  const std::string args = commandLineStr;
  handleArgs(argc, args);

  LOG() << "\nEnter the desired number of digits of Pi: ";
  std::cin >> precision;
  iterations = precision; 

  // Print the output
  printerImpl(iterations, precision);

  if (!resultProvider(defaultIterations, precision, testFlag)) {
    statusCode = picalc::STATUS_ERROR;
    return statusCode;
  } else {
    statusCode = picalc::STATUS_SUCESS;
    return statusCode;
  }
  LOG() << "StatusCode: " << statusCode << std::endl;

  return picalc::STATUS_OOB;
  exit(statusCode);
}
