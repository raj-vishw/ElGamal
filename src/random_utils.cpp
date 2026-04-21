#include "../include/random_utils.h"
#include <random>

cpp_int getRandomNumber(cpp_int min, cpp_int max){
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    std::uniform_int_distribution<unsigned long long> dist;

    cpp_int range = max - min + 1;
    cpp_int result = 0;

    for(int i=0;i<4;i++){
        result <<= 64;
        result += dist(gen);
    }
    return min+(result % range);
}