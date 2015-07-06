// c++中的布尔类型
// 	c++中bool可取的值只有true和false。
// 	理论上bool只占用一个字节，如果多个bool变量定义在一起，可能会各占一个bit，取决于编译器的实现。
// 	*true代表真值，编译器内部用1表示；
// 	*false代表非真值，编译器内部用0表示；
// 	C++靠靠靠靠靠靠靠靠true�0靠靠false

#include <iostream>

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

void triple()
{
    int a = 1;
    int b = 2;

    /*
     * c靠靠靠靠靠靠靠靠靠靠靠靠
     * c++靠靠靠靠靠靠靠�
     * 靠縜=3,b = 2
     * 靠縞靠靠靠靠靠靠靠靠靠靠靠靠�
     *      c++靠靠靠靠靠靠靠靠靠靠靠靠
     *      靠靠靠�
     * 靠縞++靠�
     */
    (a < b ? a : b) = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
}

/*
 * 靠靠靠靠靠靠靠靠�
 * Tip� 靠靠靠靠靠靠靠靠靠靠�
 *      靠靠靠靠靠靠靠靠
 * 靠靠靠靠靠靠靠靠靠靠靠靠�
 *
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

int main()
{
    //bool_test();
    //triple();
    quote();

	return 0;
}


