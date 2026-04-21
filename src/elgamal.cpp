#include "../include/elgamal.h"
#include "../include/math_utils.h"
#include "../include/random_utils.h"

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