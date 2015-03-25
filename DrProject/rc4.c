/*
 * RC4流密码
 */

#include <stdio.h>
#define MAX_CHAR_LEN 10000

void produce_key_stream(int textlength, unsigned char key[], 
                        int keylength, unsigned char keystream[])
{
    unsigned int s[256];
    int i, j = 0, k;
    unsigned char tmp;

    for ( i = 0; i < 256; i++ )
        s[i] = i;
    for ( i = 0; i < 256; i++ )
    {
        j = (j + s[i] + key[i % keylength]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    i = j = k = 0;
    while ( k < textlength )
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        keystream[k++] = s[(s[i] + s[j]) % 256];
    }
}

void encrypt(int textlength, unsigned char plaintext[], 
            unsigned char keystream[], unsigned char ciphertext[])
{
    int i;
    for ( i = 0; i < textlength; i++ )
        ciphertext[i] = keystream[i] ^ plaintext[i];
}

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        printf("Please use one and only one filename as a parameter\n");
        return 0;
    }

    unsigned char plaintext[MAX_CHAR_LEN];
    unsigned char key[32];
    unsigned char keystream[MAX_CHAR_LEN];
    unsigned char ciphertext[MAX_CHAR_LEN];
    unsigned c;
    int i = 0, textlength, keylength;
    FILE* fp;

    if ( (fp = fopen(*++argv, "r")) == NULL )
    {
        printf("file \"%s\" not found!\n", *argv);
        return 0;
    }

    while ( (c = getc(fp)) != EOF )
        plaintext[i++] = c;
    textlength = i;
    fclose(fp);

    printf("passwd: ");
    for ( i = 0; (c = getchar()) != '\n'; i++ )
        key[i] = c;
    keylength = i;

    produce_key_stream(textlength, key, keylength, keystream);

    encrypt(textlength, plaintext, keystream, ciphertext);

    fp = fopen(*argv, "w");
    for ( i = 0; i < textlength; i++ )
        putc(ciphertext[i], fp);
    fclose(fp);

    return 0;
}
