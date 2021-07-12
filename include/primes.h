#include <gmp.h>
#include <stdlib.h>

#define FIRST_PRIMES 100

void generateLargeNumber(mpz_t number, int n, gmp_randstate_t grt);
void generateLargeOddNumber(mpz_t number, int n, gmp_randstate_t grt);
void sieveOfEratosthenes(int primes[], int n);
int is_divisible_by_first_prime(mpz_t number);
int factorOutPowersOf2(mpz_t number, mpz_t d);
int millerRabin(mpz_t number, mpz_t witness, mpz_t number_minus_1, mpz_t d, int r);
int multipleMillerRabin(mpz_t number, int k, gmp_randstate_t grt);
void generateLargePrimeNumber(mpz_t number, int n, gmp_randstate_t grt);
