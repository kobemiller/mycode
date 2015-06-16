#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;

    unsigned char **pp = malloc(sizeof(char *) * 5);
    for ( i = 0; i < 5; i++ )
        pp[i] = malloc(48);
    strcpy(pp[0], "30 82 03 d9 30 82 02 c1 a0 03 02 01 02 02 03 02");
    strcpy(pp[1], "36 d0 30 0d 06 09 2a 86 48 86 f7 0d 01 01 05 05");
    strcpy(pp[2], "00 30 42 31 0b 30 09 06 03 55 04 06 13 02 55 53");
    strcpy(pp[3], "jordan");
    strcpy(pp[4], "no");

    printf("pp = %d\n", pp);
    for ( i = 0; i < 5; i++ )
        printf("addr of pp[%d] : %d\n", i, &pp[i]);
    char *ptr = *pp;
    printf("*ptr = %x\n", *ptr);
    printf("ptr[-1] = %x, addr = %d\n", ptr[-1], &ptr[-1]);
    printf("ptr[-2] = %x, addr = %d\n", ptr[-2], &ptr[-2]);
    printf("ptr[-3] = %x, addr = %d\n", ptr[-3], &ptr[-3]);
    printf("ptr[-4] = %x, addr = %d\n", ptr[-4], &ptr[-4]);

    for ( i = 0; i < 5; i++ )
        printf("%s\n",pp[i] );

    unsigned char *p = pp[1];
    printf("ptr[-1] = %x, addr = %d\n", ptr[-1], &ptr[-1]);
    printf("ptr[-2] = %x, addr = %d\n", ptr[-2], &ptr[-2]);
    printf("ptr[-3] = %x, addr = %d\n", ptr[-3], &ptr[-3]);
    printf("ptr[-4] = %x, addr = %d\n", ptr[-4], &ptr[-4]);
    printf("ptr[-5] = %x, addr = %d\n", ptr[-5], &ptr[-5]);
    printf("ptr[-6] = %x, addr = %d\n", ptr[-6], &ptr[-6]);
    printf("ptr[-7] = %x, addr = %d\n", ptr[-7], &ptr[-7]);
    printf("ptr[-8] = %x, addr = %d\n", ptr[-8], &ptr[-8]);


    int ret0 = *p & 0x20;
    int ret1 = (*p & 0x20);
	int xclass = *p & 0xc0;
    i = *p & 0x1f;
    printf("%s\n", *pp);
    printf("*p = %d, *p = %c, ret0 = %d, ret1 = %d, xclass = %d, i = %d\n",  *p, *p,  ret0, ret1, xclass, i);

    for ( i = 0; i < 5; i++ )
        printf("%s\n",pp[i] );

    return 0;

    free(pp);
    for ( i = 0; i < 5; i++ )
        free(pp[i]);
}
