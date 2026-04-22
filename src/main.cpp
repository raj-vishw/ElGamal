#include <iostream>
#include "../include/elgamal.h"

int main() {
    PublicKey pub;
    PrivateKey priv;

    generateKeys(pub, priv);
    std::cout<<"Enter a message(number):";
    cpp_int message;
    std::cin>>message;
    std::cout << "Original: " << message << std::endl;
    CipherText cipher = encrypt(message, pub);

    std::cout << "Encrypted: (" << cipher.c1 << ", " << cipher.c2 << ")\n";
    cpp_int decrypted = decrypt(cipher, pub, priv);

    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}