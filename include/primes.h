#include <gmp.h>
#include <time.h>
#include <stdlib.h>

void generateRandomSeed(gmp_randstate_t grt);
void generateLargeNumber(mpz_t number, int n, gmp_randstate_t grt);
void generateLargeOddNumber(mpz_t number, int n, gmp_randstate_t grt);
void sieveOfEratosthenes(int primes[], int n);
int is_divisible_by_first_prime(mpz_t number);
void generateLargePrimeNumber(mpz_t number, int n);
