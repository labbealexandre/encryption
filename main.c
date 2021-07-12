#include <stdio.h>

#include "primes.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("You need to provide the number of bits\n");
        return -1;
    }

    int n_bits = atoi(argv[1]);

    gmp_randstate_t grt;
    generateRandomSeed(grt);

    mpz_t number;
    generateLargePrimeNumber(number, n_bits, grt);

    gmp_printf("%Zd\n", number);

    mpz_clear(number);
}