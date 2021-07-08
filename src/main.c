#include "main.h"

int main()
{
    mpz_t number;
    generateLargeNumber(number, 1024);

    gmp_printf("%Zd\n", number);

    mpz_clear(number);
}