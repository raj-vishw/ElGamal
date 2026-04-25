#include <iostream>
#include "../include/elgamal.h"
#include <vector>

int main() {
    PublicKey pub;
    PrivateKey priv;

    generateKeys(pub, priv);

    std::string message;
    std::cout << "Enter message: ";
    std::getline(std::cin, message);

    std::cout << "\n--- KEY INFO ---\n";
    std::cout << "p: " << pub.p << "\n";
    std::cout << "g: " << pub.g << "\n";
    std::cout << "y: " << pub.y << "\n";
    std::cout << "Private x: " << priv.x << "\n";

    std::cout << "\n--- ENCRYPTION ---\n";

    auto encrypted = encryptString(message, pub);

    for (int i = 0; i < encrypted.size(); i++) {
        std::cout << "Block " << i << ": ("
                  << encrypted[i].c1 << ", "
                  << encrypted[i].c2 << ")\n";
    }

    std::cout << "\n--- DECRYPTION ---\n";

    std::string decrypted = decryptString(encrypted, pub, priv);
    
    std::cout << "Recovered Message: " << decrypted << "\n";

    return 0;
}