// Copyright (c) 2025 Alex313031.

#ifndef PICALC_CONSTANTS_H_
#define PICALC_CONSTANTS_H_

constexpr int defaultIterations = 255;

const std::string testString1 = "--test ";
const std::string testString2 = "-t ";

const std::string helpString1 = "--help ";
const std::string helpString2 = "-h ";

const std::string blah = "blah";

namespace picalc {
 constexpr int STATUS_SUCESS = 0;
 constexpr int STATUS_ERROR  = 1;
 constexpr int STATUS_OOB    = 2;
}

#endif // PICALC_CONSTANTS_H_
