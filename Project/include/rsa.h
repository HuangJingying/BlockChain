#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <mutex>
#include <utility>
#include <tuple>
#include "bigInt.h"
using namespace std;

/* class KeyPair
{
public:
    KeyPair(BigInt _exponent, BigInt _mod) : exponent(_exponent), mod(_mod){};

private:
    BigInt exponent, mod;
};
 */
class RSA
{
public:
    RSA() {}
    ~RSA() {}
    void Init(int worker);          //prime & euler & product
    BigInt CreatePrime(int worker); //create two prime numbers p and q
    BigInt CreateRandom(int);
    void Extgcd(BigInt, BigInt, BigInt &);
    void CreateKeys(); //use ext gcd to create public and private key
    tuple<BigInt, BigInt, BigInt> GetKey()
    {
        return make_tuple(publicKey, privateKey, product);
    }
    BigInt CreateRandomSmaller(const BigInt &); //for the private key and the prime test
    BigInt EncryptByPublic(const BigInt &);
    BigInt EncryptByPrivate(const BigInt &);
    BigInt DecryptByPublic(const BigInt &);
    BigInt DecryptByPrivate(const BigInt &);
    static BigInt EncryptAndDecrypt(const BigInt &, const BigInt &, const BigInt &);
    bool IsPrime(const BigInt &, int k = 4);
    int Sieve(vector<BigInt> &, const BigInt &, int);

private:
    BigInt publicKey, privateKey, Euler, product, p, q;
};

#endif
