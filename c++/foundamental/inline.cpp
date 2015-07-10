#include <iostream>

#define FUNC(a, b) ((a) > (b) ? (a) : (b))

inline int func(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 1;
    int b = 3;
    int c = func(++a, b);

    std::cout<< "a = " << a << std::endl;
    std::cout<< "b = " << b <<std::endl;
    std::cout<< "c = " << c <<std::endl;

    return 0;
}
