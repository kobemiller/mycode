/*
 * 编译：gcc test.c -lssl -lcrypto
 */
#include <stdio.h>
#include <openssl/asn1.h>
#include <openssl/bn.h>

int integer()
{
    int i;
    ASN1_INTEGER *val = NULL;
    int len;
    unsigned char *buf = NULL, *p = NULL;
    int ret = -1;

    if ( !(val = ASN1_INTEGER_new()) )
    {
        printf("out of memory\n");
        return -1;
    }
    if ( ASN1_INTEGER_set(val, 0xa9876543210) != 1 )
    {
        printf("ASN1_INTEGER_set() error\n");
        goto err;
    }
    
    /* 
     * 如果第二个参数为NULL，那么这个函数不编码, 只计算编码后数据的长度
     */
    len = i2d_ASN1_INTEGER(val, NULL);
    p = buf = (unsigned char *)OPENSSL_malloc(len);
    if ( !p )
    {
        printf("out of memory\n");
        goto err;
    }

    len = i2d_ASN1_INTEGER(val, &buf);
    if ( len == -1 )
    {
        printf("i2d_ASN1_INTEGER() error\n");
        goto err;
    }

    for ( i = 0; i < len; i++ )
        printf("%02x", p[i]);
    printf("\n");

    ret = 0;

err:
    OPENSSL_free(p);
    ASN1_INTEGER_free(val);
    return ret;
}

int big_integer()
{
    int i;
    ASN1_INTEGER    *val = NULL;
    int len;
    unsigned char   *buf = NULL, *p = NULL;
    int ret = 1;
    BIGNUM *bn = NULL;
    char *bn_str = "a9876543210";

    if ( !(val = ASN1_INTEGER_new()) )
    {
        printf("out of memory\n");
        return -1;
    }

    bn = BN_new();
    if ( !bn )
    {
        printf("BN_new() error\n");
        goto err;
    }

    if ( !(BN_hex2bn(&bn, bn_str)) )
    {
        printf("BN_hex2bn() error\n");
        goto err;
    }

    if ( !(BN_to_ASN1_INTEGER(bn, val)) )
    {
        printf("BN_to_ASN1_INTEGER() error\n");
        goto err;
    }

    len = i2d_ASN1_INTEGER(val, NULL);
    p = buf = (unsigned char *)OPENSSL_malloc(len);
    if ( !p )
    {
        printf("out of memory\n");
        goto err;
    }

    len = i2d_ASN1_INTEGER(val, &buf);
    if ( len == -1 )
    {
        printf("i2d_ASN1_INTEGER() error\n");
        goto err;
    }

    for ( i = 0; i < len; i++ )
        printf("%02x ", p[i]);
    printf("\n");
    ret = 0;

err:
    OPENSSL_free(p);
    BN_free(bn);
    ASN1_INTEGER_free(val);
    return ret;
}

int main()
{
    integer();

    big_integer();

    return 0;
}
