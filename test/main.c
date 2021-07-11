#include "unity.h"

#include "test_primes.h"
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
    return UNITY_END();
}