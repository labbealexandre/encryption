#include <stdio.h>

#include "primes.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("You need to provide the number of bits\n");
        return -1;
    }

    int n = atoi(argv[1]);

    mpz_t number;
    generateLargePrimeNumber(number, n);

    gmp_printf("%Zd\n", number);

    mpz_clear(number);
}