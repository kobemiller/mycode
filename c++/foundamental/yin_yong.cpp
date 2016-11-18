#include <iostream>

/*
 * 1、c++中的bool可取的值只有true和false
 * 2、理论上bool只占用一个字节，如果多个bool变量定义在一起，
 * 可能会各占一个bit，这取决于编译器的实现
 * 3、true代表真，编译器内部用1表示
 *      false代表非真，编译器内部用0表示
 * 4、c++编译器会在赋值时将非0值转化为true，0值转化为false
 */
void bool_test()
{
    int a;
	bool b = true;

	//打印bool类型所占的字节
	std::cout << "b = " << b << ", sizeof(b) = " << sizeof(b) << std::endl;

	b = 3;
	a = b;
	std::cout << "a = " << a << "b = " << b << std::endl;

	b = 0;
	std::cout << "b = " << b << std::endl;

    b = false;
    b++; 
	std::cout << "b = " << b << std::endl;

    b += 1;
	std::cout << "b = " << b << std::endl;
}

/*
 * c语言中三目运算符返回的是变量值，不能作为左值使用
 * c++中的三目运算符可直接返回变量本身，因此可以出现在程序的任何地方
 * tips：三目运算符可能返回的值中如果有一个是常量值，则不能作为左值使用
 * c++对三目运算符的处理：
 *      当三目运算符的可能返回都是变量时，返回的是变量引用
 *      当三目运算符的可能返回中有常量时，返回的是值
 */
void triple()
{
    int a = 1;
    int b = 2;

    (a < b ? a : b) = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
}

/*
 * 引用：本质是一个指针常量
 * 变量：一段实际连续存储空间的别名
 * 引用可看作一个已定义变量的别名
 * tips：普通引用在声明时必须用其他的变量进行初始化
 * 引用作为其他变量的别名而存在，因此在一些场合中可以替代指针
 * tips：引用作为函数参数声明时不进行初始化
 * const引用让变量拥有只读属性
 *
 * 当使用常量对const引用进行初始化时，c++编译器会为常量值分配空间，
 * 并将引用名作为这段空间的别名
 * tips：使用常量对const引用初始化后将生成一个只读变量
 */

/*
 * 引用在c++中的内部实现是一个常指针
 * Type &name <==> Type *const name
 * c++编译器在编译过程中使用常指针作为引用的内部实现，因此引用所占的空间
 * 大小与指针相同。
 */
void quote()
{
    int a = 4;
    int &b = a;

    b = 5;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "&a = " << &a << std::endl;
    std::cout << "&b = " << &b << std::endl;
}

/*
 * 当函数返回值为引用时：
 *      若返回栈变量：不能成为其他引用的初始值，不能作为左值使用
 *      若返回静态或全局变量：可以作为其他引用的初始值，既可作左值也可做右值
 */
int &return_static()
{
    static int a = 0;
    return a;
}

int &return_local()
{
    int a = 0;
    return a;
}

int test_return()
{
    int a = return_local();
    int &b = return_local();

    return_static() = 10;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "return_static() = " << return_static() << std::endl;
    
    return 0;
}

int yin_yong_storage()
{
    struct TRef
    {
        int &a;
        int &b;
        int &c;
    };

    int a = 1;
    int b = 2;
    int c = 3;
    TRef rA = {a, b, c};

    std::cout << "&a = " << &a << std::endl;
    std::cout << "&b = " << &b << std::endl;
    std::cout << "&c = " << &c << std::endl;
    std::cout << "&rA = " << &rA << std::endl;
    std::cout << "sizeof(rA) = " << sizeof(rA) << std::endl;

    return 0;
}

int test_yin_yong()
{
    struct SV
    {
        int x;
        int y;
        int z;
    };

    struct SR
    {
        int& x;
        int& y;
        int& z;
    };

    SV sv = {1, 2, 3};
    SR sr = {sv.x, sv.y, sv.z};

    std::cout << "&sv = " << &sv << std::endl;
    std::cout << "&sv.x = " << &sv.x << std::endl;
    std::cout << "&sv.y = " << &sv.y << std::endl;
    std::cout << "&sv.z = " << &sv.z << std::endl;

    std::cout << "&sr = " << &sr << std::endl;
    std::cout << "&sr.x = " << &sr.x << std::endl;
    std::cout << "&sr.y = " << &sr.y << std::endl;
    std::cout << "&sr.z = " << &sr.z << std::endl;

    SV& rsv = sv;

    rsv.x = 4;
    rsv.y = 5;
    rsv.z = 6;

    std::cout << "sv.x = " << sv.x << std::endl;
    std::cout << "sv.y = " << sv.y << std::endl;
    std::cout << "sv.z = " << sv.z << std::endl;

    return 0;
}

int main()
{
    bool_test();
    triple();
    quote();
    test_return();
    yin_yong_storage();
    test_yin_yong();

    return 0;
}
