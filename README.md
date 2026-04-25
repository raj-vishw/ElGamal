# ElGamal C++ Implementation

A robust, simple C++ implementation of the ElGamal public-key encryption and decryption system. 
This project demonstrates the core mathematical concepts behind ElGamal cryptography, including key generation, message encryption, and decryption, with support for arbitrary length strings.

## Features

- **Key Generation:** Generates public and private keys using large prime numbers.
- **String Encryption & Decryption:** Supports encrypting and decrypting full strings by splitting them into numerical blocks.
- **Large Integer Arithmetic:** Utilizes `Boost.Multiprecision` to safely handle the extremely large integers required for cryptographic operations.

## Prerequisites

To build and run this project, you will need:

- **C++ Compiler:** A compiler that supports C++11 or later (e.g., `g++` or `clang++`).
- **Boost Library:** The Boost C++ Libraries are required for the `boost::multiprecision` library.
  - On Ubuntu/Debian: `sudo apt-get install libboost-all-dev`
  - On macOS (using Homebrew): `brew install boost`
  - On Windows: Download from the [Boost website](https://www.boost.org/) and configure your compiler appropriately.



## Build Instructions

You can compile the project using `g++` directly from the command line:

```bash
# Compile the source code
g++ -Iinclude src/*.cpp -o elgamal
```

## Usage

After compiling, run the executable:

```bash
./elgamal
```
