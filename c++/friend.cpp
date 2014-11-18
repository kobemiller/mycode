#include <iostream>

class A
{
public:
    void print();
    friend void fprint();
private:
    int i;
};
void fprint()
{
    std::cout << "fprint: A::i = " << A::i << std::endl;
}
void A::print()
{
    std::cout << "print: A::i = " << i << std::endl;
}
int main()
{
    A a;
    a.i = 4;
    a.print();
    fprint();
    return 0;
}
