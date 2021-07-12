#include "unity.h"

#include "test_primes.h"
#include "test_rsa.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_sieveOfEratosthenes);
    RUN_TEST(test_generateLargeNumber);
    RUN_TEST(test_generateLargeOddNumber);
    RUN_TEST(test_factorOutPowersOf2);
    RUN_TEST(test_millerRabin);
    RUN_TEST(test_phi);
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);
    return UNITY_END();
}