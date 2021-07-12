#include "test_rsa.h"

/* Test suite for phi method */

void test_phi()
{
    mpz_t a;
    mpz_t b;
    mpz_t res;

    mpz_init_set_ui(a, 53);
    mpz_init_set_ui(b, 59);

    phi(res, a, b);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(res), 3016);
}

void test_encrypt()
{
    mpz_t code;
    mpz_t input;
    mpz_t n;
    mpz_t e;

    mpz_init_set_ui(input, 89);
    mpz_init_set_ui(n, 3127);
    mpz_init_set_ui(e, 3);

    rsa_encrypt(code, input, n, e);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(code), 1394);
}

void test_decrypt()
{
    mpz_t decode;
    mpz_t input;
    mpz_t n;
    mpz_t d;

    mpz_init_set_ui(input, 1394);
    mpz_init_set_ui(n, 3127);
    mpz_init_set_ui(d, 2011);

    rsa_decrypt(decode, input, n, d);
    TEST_ASSERT_EQUAL_INT(mpz_get_ui(decode), 89);
}