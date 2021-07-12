#include "primes.h"

// https://www.programmersought.com/article/24064840329/
// https://www.geeksforgeeks.org/how-to-generate-large-prime-numbers-for-rsa-algorithm/

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

int factorOutPowersOf2(mpz_t number, mpz_t d)
{
    int r = 0;
    mpz_init(d);

    mpz_t zero_mpz;
    mpz_init(zero_mpz);

    while (mpz_congruent_2exp_p(number, zero_mpz, r + 1))
    {
        r++;
    }

    mpz_tdiv_q_2exp(d, number, r);
    return r;
}

int millerRabin(mpz_t number, mpz_t witness, mpz_t number_minus_1, mpz_t d, int r)
{
    mpz_t x;
    mpz_init(x);
    mpz_powm(x, witness, d, number); // x = a^d mod n

    if (mpz_cmp_ui(x, 1) == 0 || mpz_cmp(x, number_minus_1) == 0) // if x = 1 or x = n − 1
    {
        return 0;
    }

    for (int j = 0; j < r - 1; j++)
    {
        mpz_powm_ui(x, x, 2, number);        // x = x^2 mod n
        if (mpz_cmp(x, number_minus_1) == 0) // if x = n-1
        {
            return 0;
        }
    }
    return 1;
}

int multipleMillerRabin(mpz_t number, int k, gmp_randstate_t grt)
{
    mpz_t number_minus_1;
    mpz_init(number_minus_1);
    mpz_sub_ui(number_minus_1, number, 1); // n-1

    mpz_t d;
    int r = factorOutPowersOf2(number_minus_1, d);

    mpz_t witness;
    mpz_init(witness);

    for (int i = 0; i < k; i++)
    {
        /* Pick a random number between 2 and n-2 inclusive */
        mpz_sub_ui(witness, number, 3);
        mpz_urandomm(witness, grt, witness); // [0, n-4]
        mpz_add_ui(witness, witness, 2);     // [2, n-2]

        if (millerRabin(number, witness, number_minus_1, d, r))
        {
            continue;
        }
        return 1; // Not prime
    }
    return 0; // Probably prime
}

void generateLargePrimeNumber(mpz_t number, int n, gmp_randstate_t grt)
{
    while (1)
    {
        generateLargeOddNumber(number, n, grt);

        /* Low level primality test */
        if (is_divisible_by_first_prime(number))
            continue;

        /* high level primality test */
        if (multipleMillerRabin(number, 20, grt))
        {
            continue;
        }

        /* Number passes all the tests -> considered as prime */
        break;
    }
}