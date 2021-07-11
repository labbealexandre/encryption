#include "unity.h"
#include "primes.h"

#define N_FIRST_PRIMES 25
#define N_FIRST_NUMBERS 100

/* Test suite for sieveOfEratosthenes method */

void test_sieveOfEratosthenes()
{
    char failure_message[1024];

    int first_primes[N_FIRST_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int numbers[N_FIRST_NUMBERS];
    sieveOfEratosthenes(numbers, N_FIRST_NUMBERS);

    int *prime = first_primes;
    int *number = numbers;
    for (int i = 0; i < N_FIRST_NUMBERS; i++)
    {
        if (i == *prime)
        {
            snprintf(failure_message, sizeof(failure_message), "%d should be a prime number.", i);
            TEST_ASSERT_EQUAL_INT_MESSAGE(*number, 1, failure_message);
            prime++;
        }
        else
        {
            snprintf(failure_message, sizeof(failure_message), "%d should not be a prime number.", i);
            TEST_ASSERT_EQUAL_INT_MESSAGE(*number, 0, failure_message);
        }
        number++;
    }
}

void test_generateLargeNumber()
{
    gmp_randstate_t grt;
    generateRandomSeed(grt);

    mpz_t number;
    generateLargeNumber(number, 8, grt);
    int integer = mpz_get_ui(number);

    TEST_ASSERT_LESS_THAN_INT(256, integer);
    TEST_ASSERT_GREATER_OR_EQUAL_INT(128, integer);
}

void test_generateLargeOddNumber()
{
    gmp_randstate_t grt;
    generateRandomSeed(grt);

    mpz_t number;
    generateLargeOddNumber(number, 8, grt);
    int integer = mpz_get_ui(number);

    TEST_ASSERT_EQUAL_INT(integer % 2, 1);
}