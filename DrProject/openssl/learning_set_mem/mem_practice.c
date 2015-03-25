/*
 * openssl内存分配练习
 * gcc mem_practice.c -lssl -lcrypto
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/bio.h>

int practice_1()
{
    char *p;
    int  i;

    p = OPENSSL_malloc(4);
    p = OPENSSL_remalloc(p, 40);
    p = OPENSSL_realloc(p, 32);

    for ( i = 0; i < 32; i++ )
        memset(&p[i], i, 1);

    p = OPENSSL_realloc_clean(p, 32, 77);
    p = OPENSSL_remalloc(p, 40);
    OPENSSL_malloc_locked(3);
    OPENSSL_free(p);

    return 0;
}

int practice_2()
{
    char *p;
    BIO  *b;
    CRYPTO_malloc_debug_init();
    CRYPTO_set_mem_debug_options(V_CRYPTO_MDEBUG_ALL);
    CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
    p = OPENSSL_malloc(4);
    CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_OFF);
    b = BIO_new_file("leak.log", "w");
    CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
    CRYPTO_mem_leaks(b);
    OPENSSL_free(p);
    BIO_free(b);

    return 0;
}

int main()
{
    printf("\npractice_1:\n");
    printf("*******************************************\n");
    practice_1();
    printf("*******************************************\n");

    printf("\npractice_2:\n");
    printf("*******************************************\n");
    practice_2();
    printf("*******************************************\n");

    return 0;
}
