#include "unity.h"

#include "test_sieve_of_eratosthenes.h"

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
    return UNITY_END();
}