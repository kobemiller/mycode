/*
 * =====================================================================================
 *
 *       Filename:  default_argc.cpp
 *
 *    Description:  c++里面函数默认参数
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 19时29分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>

/*
 * 一旦在函数参数中使用默认参数值，那么其之后的所有参数都需使用默认参数值
 */
int add(int a, int b = 0, int c = 0)
{
    return a + b + c;
}

int main()
{
    std::cout << "add(2) = " << add(2) << std::endl;
    std::cout << "add(1, 2) = " << add(1, 2) << std::endl;
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << std::endl;

    return 0;
}
