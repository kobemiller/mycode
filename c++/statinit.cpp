#include <iostream>

int x = 100;

class WithStatic
{
    static int x;
    static int y;
public:
    void print() const
    {
        std::cout << "withstatic::x = " << x << std::endl;
        std::cout << "withstatic::y = " << y << std::endl;
    }
};

int WithStatic::x = 1;
int WithStatic::y = x + 1;

int main()
{
    WithStatic ws;
    ws.print();
}
