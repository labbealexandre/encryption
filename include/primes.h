#include <gmp.h>
#include <time.h>
#include <stdlib.h>

void generateLargeNumber(mpz_t number, int n);
void generateLargeOddNumber(mpz_t number, int n);
void sieveOfEratosthenes(int primes[], int n);
int is_divisible_by_first_prime(mpz_t number);
void generateLargePrimeNumber(mpz_t number, int n);
