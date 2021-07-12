#include <stdio.h>

#include "rsa.h"
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

    mpz_t n;
    mpz_t e;
    mpz_t d;

    rsa(n, e, d, n_bits);

    gmp_printf("n = %Zd\n\n", n);
    gmp_printf("e = %Zd\n\n", e);
    gmp_printf("d = %Zd\n\n", d);

    mpz_clear(n);
}