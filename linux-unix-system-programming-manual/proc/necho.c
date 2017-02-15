#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    /*
    int j;

    for (j = 0; j < argc; j++)
        printf("argv[%d] = %s\n", j, argv[j]);
    */

    char **p;

    for (p = argv; *p != NULL; p++)
        puts(*p);

    sleep(30);

    exit(EXIT_SUCCESS);
}
