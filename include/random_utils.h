#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

cpp_int getRandomNumber(cpp_int min, cpp_int max);

#endif