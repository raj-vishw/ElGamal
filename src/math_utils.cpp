#include "../include/math_utils.h"

// Fast Module exponentiation
cpp_int modExp(cpp_int base, cpp_int exp, cpp_int mod){
    cpp_int result = 1;
    base %= mod;

    while(exp > 0){
        if(exp % 2 == 1) result = (result * base)%mod;
        
        base = (base * base) %mod;
        exp /= 2;
    }
    return result;
}

//EEA
cpp_int modInverse(cpp_int a, cpp_int mod){
    cpp_int m0 = mod, t, q;
    cpp_int x0 = 0, x1 = 1;

    if(mod==1) return 0;
    while(a>1){
        q = a/mod;
        t = mod;

        mod = a % mod;
        a = t;
        t = x0;

        x0 = x1-q*x0;
        x1 = t;
    }
    if(x1 < 0){
        x1 += m0;
    }
    return x1;
}