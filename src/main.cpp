#include <iostream>
#include "../include/elgamal.h"

int main() {
    PublicKey pub;
    PrivateKey priv;

    generateKeys(pub, priv);

    cpp_int message = 12345;

    std::cout << "Original: " << message << std::endl;

    CipherText cipher = encrypt(message, pub);

    std::cout << "Encrypted: (" << cipher.c1 << ", " << cipher.c2 << ")\n";

    cpp_int decrypted = decrypt(cipher, pub, priv);

    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}