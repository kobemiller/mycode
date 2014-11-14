#include <iostream>

int main()
{
    int i[10];
    double d[10];
    int* ip = i;
    double* dp = d;
    typedef struct
    {
        char c;
        short s;
        int i;
        long l;
        float f;
        double d;
        long double ld;
    }primitives;
    primitives p[10];
    primitives* pp = p;
    std::cout << "sizeof(primitives) = "
                << sizeof(primitives) << std::endl;
    std::cout << "pp = " << (long)pp << std::endl;
    pp++;
    std::cout << "pp = " << (long)pp << std::endl;
    std::cout << "ip = " << (long)ip << std::endl;
    ip++;
    std::cout << "ip = " << (long)ip << std::endl;
    std::cout << "dp = " << (long)dp << std::endl;
    dp++;
    std::cout << "dp = " << (long)dp << std::endl;

    return 0;
}
