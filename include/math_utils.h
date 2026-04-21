#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

cpp_int modExp(cpp_int base, cpp_int exp, cpp_int mod);
cpp_int modInverse(cpp_int a, cpp_int b);

#endif