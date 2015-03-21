/*
 * show the usage of RSA encryption and decryption
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>

int main(int argc, char **argv)
{
    RSA* rsa;
    unsigned char* input_string;
    unsigned char* encrypt_string;
    unsigned char* decrypt_string;
    int i;

    if ( argc != 2 )
    {
        fprintf(stderr, "%s <plain text>\n", argv[0]);
        exit(-1);
    }

    input_string = (unsigned char *)calloc(strlen(argv[1]) + 1, sizeof(unsigned char));
    if ( input_string == NULL )
    {
        fprintf(stderr, "Unable to allocate memory for input_string\n");
        exit(-1);
    }
    strncpy((char*)input_string, argv[1], strlen(argv[1]));

    rsa = RSA_generate_key(1024, 3, NULL, NULL);

    unsigned char *n_b = (unsigned char *)calloc(RSA_size(rsa), sizeof(unsigned char));
    unsigned char *e_b = (unsigned char *)calloc(RSA_size(rsa), sizeof(unsigned char));

    int n_size = BN_bn2bin(rsa->n, n_b);
    int b_size = BN_bn2bin(rsa->e, e_b);

    RSA* encrypt_rsa = RSA_new();
    encrypt_rsa->n = BN_bin2bn(n_b, n_size, NULL);
    encrypt_rsa->e = BN_bin2bn(e_b, b_size, NULL);

    encrypt_string = (unsigned char *)calloc(RSA_size(encrypt_rsa), sizeof(unsigned char));
    if ( encrypt_string == NULL )
    {
        fprintf(stderr, "Unable to allocate memory for encrypt_string\n");
        exit(-1);
    }

    int encrypt_size = RSA_public_encrypt(strlen((char *)input_string), input_string, encrypt_string, encrypt_rsa, RSA_PKCS1_OAEP_PADDING);

    decrypt_string = (unsigned char *)calloc(RSA_size(rsa), sizeof(unsigned char));
    if ( decrypt_string == NULL )
    {
        fprintf(stderr, "Unable to allocate memory for decrypt_string\n");
        exit(-1);
    }

    int decrypt_size = RSA_private_decrypt(encrypt_size, encrypt_string, decrypt_string, rsa, RSA_PKCS1_OAEP_PADDING);

    printf("input_string = %s\n", input_string);
    printf("encrypt string = ");
    for ( i = 0; i < encrypt_size; i++ )
        printf("%x%x", (encrypt_string[i] >> 4) & 0xf, encrypt_string[i] & 0xf);
    printf("\n");

    printf("decrypted string (%d) = %s\n", decrypt_size, decrypt_string);

    return 0;
}
