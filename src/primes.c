#include "primes.h"

#define FIRST_PRIMES 100

// https://www.programmersought.com/article/24064840329/
// https://www.geeksforgeeks.org/how-to-generate-large-prime-numbers-for-rsa-algorithm/

void generateRandomSeed(gmp_randstate_t grt)
{
    /* Generate a seed based on the time */
    clock_t time = clock();
    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time);
}

void generateLargeNumber(mpz_t number, int n, gmp_randstate_t grt)
{
    /* Generate a number from 0 to 2^(n-1)-1 */
    mpz_init(number);
    mpz_rrandomb(number, grt, n);
}

void generateLargeOddNumber(mpz_t number, int n, gmp_randstate_t grt)
{
    /* Generate a large odd number */
    generateLargeNumber(number, n - 1, grt);
    mpz_mul_ui(number, number, 2);
    mpz_add_ui(number, number, 1);
}

void sieveOfEratosthenes(int primes[], int n)
{
    /* 0 and 1 are not prime */
    primes[0] = 0;
    primes[1] = 0;

    /* Init all numbers > 1 to True */
    for (int k = 2; k < n; k++)
    {
        primes[k] = 1;
    }

    /* Remove multiples to the list of primes */
    for (int p = 2; p * p <= n; p++)
    {
        for (int k = p * p; k < n; k += p)
        {
            primes[k] = 0;
        }
    }
}

int is_divisible_by_first_prime(mpz_t number)
{
    int primes[FIRST_PRIMES];
    sieveOfEratosthenes(primes, FIRST_PRIMES);

    for (int i = 0; i < FIRST_PRIMES; i++)
    {
        if (primes[i] && mpz_divisible_ui_p(number, i) != 0)
            return -1;
    }
    return 0;
}

void millerRabin(mpz_t number, mpz_t witness)
{
    /* write number as d*2^r+1 */
}

void generateLargePrimeNumber(mpz_t number, int n)
{
    gmp_randstate_t grt;
    generateRandomSeed(grt);

    while (1)
    {
        generateLargeOddNumber(number, n, grt);

        /* Low level primality test */
        if (is_divisible_by_first_prime(number))
            continue;

        // TODO: Implement high level primality test

        /* Number passes all the tests -> considered as prime */
        break;
    }
}