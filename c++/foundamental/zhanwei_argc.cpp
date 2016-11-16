/*
 * =====================================================================================
 *
 *       Filename:  zhanwei_argc.cpp
 *
 *    Description:  函数占位参数
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 19时39分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>

int func(int a, int b, int)
{
    return a + b;
}

int main()
{
    std::cout << "func(1, 2, 3) = " << func(1, 2, 3) << std::endl;

    return 0;
}
