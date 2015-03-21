/*
 * show the usage of DSA sign/verify
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/dsa.h>

int main(int argc, char **argv)
{
    DSA *dsa;
    unsigned char*  input_string;
    unsigned char*  sign_string;
    unsigned int    sig_len;
    unsigned int    i;

    if ( argc != 2 )
    {
        fprintf(stderr, "%s <plain text>\n", argv[0]);
        exit(-1);
    }

    input_string = (unsigned char*)calloc(strlen(argv[1]) + 1, sizeof(unsigned char));
    if ( input_string == NULL )
    {
        fprintf(stderr, "Unable to allocate memory for input_string\n");
        exit(-1);
    }
    strncpy((char *)input_string, argv[1], strlen(argv[1]));

    dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);

    DSA_generate_key(dsa);

    sign_string = (unsigned char *)calloc(DSA_size(dsa), sizeof(unsigned char));
    if ( sign_string == NULL )
    {
        fprintf(stderr, "Unable to allocate memory for sign_string\n");
        exit(-1);
    }

    if ( DSA_sign(0, input_string, strlen((char *)input_string), sign_string, &sig_len, dsa) == 0 )
    {
        fprintf(stderr, "Sign error\n");
        exit(-1);
    }

    int is_valid_signature = DSA_verify(0, input_string, strlen((char*)input_string), sign_string, sig_len, dsa);

    DSAparams_print_fp(stdout, dsa);
    printf("input_string = %s\n", input_string);
    printf("signed string = ");
    for ( i = 0; i < sig_len; i++ )
        printf("%x%x", (sign_string[i] >> 4) & 0xf, sign_string[i] & 0xf);
    printf("\n");
    printf("is_valid_signature? = %d\n", is_valid_signature);

    return 0;
}
