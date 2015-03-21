/*
 * using md5 with openssl
 * md5 returns a 128-bit hash value from a string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(int argc, char **argv)
{
    MD5_CTX hash_ctx;
    char    input_string[128];
    unsigned char hash_ret[16];
    int i;

    if ( argc != 2 )
    {
        fprintf(stderr, "%s <input string>\n", argv[0]);
        exit(-1);
    }

    snprintf(input_string, sizeof(input_string), argv[1]);

    MD5_Init(&hash_ctx);

    MD5_Update(&hash_ctx, input_string, strlen(input_string));

    MD5_Final(hash_ret, &hash_ctx);

    printf("Input string: %s\n", input_string);
    printf("Output string: ");
    for ( i = 0; i < 32; i++ )
        if ( i % 2 == 0 )
            printf("%x", (hash_ret[i/2] >> 4) & 0xf);
        else
            printf("%x", (hash_ret[i/2]) & 0xf);
    printf("\n");

    return 0;
}
