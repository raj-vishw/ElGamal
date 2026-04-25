#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <vector>

using namespace boost::multiprecision;

struct PublicKey {
    cpp_int p, g, y;
};

struct PrivateKey {
    cpp_int x;
};

struct CipherText {
    cpp_int c1, c2;
};

void generateKeys(PublicKey &pub, PrivateKey &priv);
CipherText encrypt(cpp_int m, PublicKey pub);
cpp_int decrypt(CipherText cipher, PublicKey pub, PrivateKey priv);
std::vector<CipherText> encryptString(const std::string &msg, PublicKey pub);
std::string decryptString(const std::vector<CipherText> &cipherList, PublicKey pub, PrivateKey priv);

#endif
