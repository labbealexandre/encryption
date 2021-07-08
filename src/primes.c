#include "primes.h"

// https://www.programmersought.com/article/24064840329/

void generateLargeNumber(mpz_t number, int n)
{

    // Generate a seed based on the time
    clock_t time = clock();
    gmp_randstate_t grt;
    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time);

    mpz_init(number);

    mpz_urandomb(number, grt, n);
}