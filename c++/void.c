#include <stdio.h>

int func();

int main()
{
    func(1, 'c', 2.3);
    return 0;
}

int func(int a, char b, float c)
{
    printf("%d, %c, %f\n", a, b, c);

    return 0;
}
