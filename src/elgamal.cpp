#include "../include/elgamal.h"
#include "../include/math_utils.h"
#include "../include/random_utils.h"

#include <vector>
#include <string>

static cpp_int p = 98101;
static cpp_int g = 2;

void generateKeys(PublicKey &pub, PrivateKey &priv){
    priv.x = getRandomNumber(2, p-2);
    cpp_int y = modExp(g, priv.x, p);

    pub.p = p;
    pub.g = g;
    pub.y = y;
}

CipherText encrypt(cpp_int m, PublicKey pub){
    cpp_int k = getRandomNumber(2, pub.p -2);

    cpp_int c1 = modExp(pub.g, k, pub.p);
    cpp_int c2 = (m* modExp(pub.y, k, pub.p)) % pub.p;

    return {c1,c2};
}

cpp_int decrypt(CipherText cipher, PublicKey pub, PrivateKey priv){
    cpp_int s = modExp(cipher.c1, priv.x, pub.p);
    cpp_int s_inv = modInverse(s, pub.p);

    cpp_int m = (cipher.c2 * s_inv) % pub.p;
    return m;
}

std::vector<cpp_int> stringToBlocks(const std::string &msg, cpp_int p) {
    std::vector<cpp_int> blocks;
    cpp_int current = 0;
    cpp_int base = 256;

    for (char c : msg) {
        current = current * base + (unsigned char)c;

        if (current >= p) {
            blocks.push_back(current / base);
            current = (unsigned char)c;
        }
    }

    if (current > 0)
        blocks.push_back(current);

    return blocks;
}

std::string blocksToString(const std::vector<cpp_int> &blocks) {
    std::string result;
    cpp_int base = 256;

    for (auto block : blocks) {
        std::string temp;

        while (block > 0) {
            char c = (char)(block % base);
            temp = c + temp;
            block /= base;
        }

        result += temp;
    }

    return result;
}

std::vector<CipherText> encryptString(const std::string &msg, PublicKey pub) {
    std::vector<cpp_int> blocks = stringToBlocks(msg, pub.p);
    std::vector<CipherText> encrypted;
    
    for (auto m : blocks) {
        encrypted.push_back(encrypt(m, pub));
    }
    return encrypted;
}

std::string decryptString(const std::vector<CipherText> &cipherList,
                          PublicKey pub, PrivateKey priv) {

    std::vector<cpp_int> blocks;

    for (auto c : cipherList) {
        blocks.push_back(decrypt(c, pub, priv));
    }
    return blocksToString(blocks);
}