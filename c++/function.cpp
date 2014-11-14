#include <iostream>
/*
void func(int n = 0, int m = 0)
{
    std::cout << "n = " << n << ",\tm = " << m << std::endl;
}

int main()
{
    func();
    func(1, 2);
    return 0;
}
*/

/* 构造函数和析构函数的顺序问题
 * 程序执行结果：
 * demo的带一个参数的构造函数300
 * demo的带一个参数的构造函数200
 * rectangle的带三个参数的构造函数300200
 * rectangle的默认析构函数
 * demo的默认析构函数200
 * demo的默认析构函数300
class demo
{
    public:
        demo()
        {
            x = 0;
            std::cout << "demo的默认构造函数" << x << std::endl;
        }
        demo(int i)
        {
            x = i;
            std::cout << "demo的带一个参数的构造函数" << x << std::endl;
        }
        ~demo()
        {
            std::cout << "demo的默认析构函数" << x << std::endl;
        }
        void set(int i)
        {
            x = i;
        }
        int get()
        {
            return x;
        }
    private:
        int x;
};

class rectangle
{
    public:
        rectangle()
        {
            x = 1000;
            std::cout << "rectangle的默认构造函数" << x << std::endl;
        }
        rectangle(int i, int j, int k) : x(i), width(j), length(k)
        {
            std::cout << "rectangle的带三个参数的构造函数" 
                << length.get() << width.get() << std::endl;
        }
        ~rectangle()
        {
            std::cout << "rectangle的默认析构函数" << std::endl;
        }
        int area()
        {
            return length.get() * width.get();
        }
    private:
        int x;
        demo length;
        demo width;
};

int main()
{
    rectangle a(100, 200, 300);

    return 0;
}
*/
