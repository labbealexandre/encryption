#include "rsa.h"

// https://www.geeksforgeeks.org/rsa-algorithm-cryptography

void phi(mpz_t res, mpz_t a, mpz_t b)
{
    mpz_t aux;

    mpz_init(res);
    mpz_init(aux);
    mpz_sub_ui(res, a, 1);
    mpz_sub_ui(aux, b, 1);
    mpz_mul(res, res, aux);

    mpz_clear(aux);
}

void generatePublicKey(mpz_t n, mpz_t e, mpz_t a, mpz_t b, mpz_t phi_n, gmp_randstate_t grt)
{
    mpz_init(n);
    mpz_init(e);

    mpz_mul(n, a, b);
    mpz_urandomm(e, grt, phi_n);
    mpz_add_ui(e, e, 1);
}

void generatePrivateKey(mpz_t d, mpz_t phi_n, mpz_t e)
{
    mpz_init(d);

    int k = 2;

    mpz_mul_ui(d, phi_n, k);
    mpz_add_ui(d, d, 1);
    mpz_divexact(d, d, e);
}

void rsa_encrypt(mpz_t code, mpz_t input, mpz_t n, mpz_t e)
{
    mpz_init(code);
    mpz_powm(code, input, e, n);
}

void rsa_decrypt(mpz_t decode, mpz_t input, mpz_t n, mpz_t d)
{
    mpz_init(decode);
    mpz_powm(decode, input, d, n);
}

void rsa(mpz_t n, mpz_t e, mpz_t d, int n_bits)
{
    mpz_t a;
    mpz_t b;
    mpz_t phi_n;

    gmp_randstate_t grt;
    generateRandomSeed(grt);

    /* Generate two large prime numbers of n/2 bits */
    generateLargePrimeNumber(a, n_bits / 2, grt);
    generateLargePrimeNumber(b, n_bits / 2, grt);

    /* Generate phi(n) */
    phi(phi_n, a, b);

    /* Generate public key */
    generatePublicKey(n, e, a, b, phi_n, grt);

    /* Generate private key */
    generatePrivateKey(d, n, e);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(phi_n);
}