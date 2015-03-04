#include <stdio.h>

int main(int argc, char **argv)
{
    printf("main:   0x%08x\n", main);
    printf("argc:   0x%08x\n", &argc);
    printf("argv:   0x%08x\n", argv);
    printf("&argv:  0x%08x\n", &argv);
    return 0;
}
