#include "utils.h"

void generateRandomSeed(gmp_randstate_t grt)
{
    /* Generate a seed based on the time */
    clock_t time = clock();
    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time);
}
