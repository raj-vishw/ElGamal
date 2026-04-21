#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <boost/multiprecision/cpp_int.hpp>
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

#endif