#include <iostream>
class A
{
public:
    A()
    {
        x = new int;
        *x = 5;
    }
    ~A()
    {
        delete x;
        x = NULL;
    }
    A(const A &a)
    {
        std::cout << "复制构造函数执行。。。" << std::endl;
        x = a.x;
    }
    void print() const
    {
        std::cout << *x << std::endl;
    }
    void set(int i)
    {
        *x = i;
    }
private:
    int *x;
};

int main()
{
    A *a = new A();
    std::cout << "a: ";
    a->print();
    A b = (*a);
    a->set(32);
    std::cout << "b: ";
    b.print();
    delete a;

    return 0;
}