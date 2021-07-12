#include "test_primes.h"

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

void test_factorOutPowersOf2()
{
    mpz_t number;
    mpz_init_set_ui(number, 256);

    mpz_t d;

    int r = factorOutPowersOf2(number, d);

    TEST_ASSERT_EQUAL_INT(r, 8);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(d), 1);

    mpz_set_ui(number, 36);

    r = factorOutPowersOf2(number, d);

    TEST_ASSERT_EQUAL_INT(r, 2);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(d), 9);

    mpz_set_ui(number, 97);

    r = factorOutPowersOf2(number, d);

    TEST_ASSERT_EQUAL_INT(r, 0);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(d), 97);
}

void test_millerRabin()
{
    mpz_t number;
    mpz_init_set_ui(number, 221);

    mpz_t number_minus_1;
    mpz_init_set_ui(number_minus_1, 220);

    int r = 2;

    mpz_t d;
    mpz_init_set_ui(d, 55);

    mpz_t witness;
    mpz_init_set_ui(witness, 174);

    TEST_ASSERT_EQUAL_INT_MESSAGE(millerRabin(number, witness, number_minus_1, d, r), 0, "The millerRabin should not say that the number is not prime");

    mpz_set_ui(witness, 137);
    TEST_ASSERT_EQUAL_INT_MESSAGE(millerRabin(number, witness, number_minus_1, d, r), 1, "The millerRabin should say that the number is not prime");
}
