#include <gmp.h>

#include "primes.h"
#include "utils.h"

void phi(mpz_t res, mpz_t a, mpz_t b);
void generatePublicKey(mpz_t n, mpz_t e, mpz_t a, mpz_t b, mpz_t phi_n, gmp_randstate_t grt);
void generatePrivateKey(mpz_t d, mpz_t phi_n, mpz_t e);
void rsa_encrypt(mpz_t code, mpz_t input, mpz_t n, mpz_t e);
void rsa_decrypt(mpz_t decode, mpz_t input, mpz_t n, mpz_t d);
void rsa(mpz_t n, mpz_t e, mpz_t d, int n_bits);
