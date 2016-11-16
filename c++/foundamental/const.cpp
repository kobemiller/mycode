/*
 * =====================================================================================
 *
 *       Filename:  const.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月15日 20时48分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>

int main()
{
    const int x = 1;
    int& rx = const_cast<int&>(x);

    rx = 5;

    std::cout << "x = " << x << std::endl;
    std::cout << "rx = " << rx << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "&rx = " << &rx << std::endl;

    volatile const int y = 2;
    int *p = NULL;

    p = const_cast<int*>(&y);
    *p = 6;

    std::cout << "y = " << y << std::endl;
    std::cout << "*p = " << *p << std::endl;

    const int z = y;
    p = const_cast<int*>(&z);
    *p = 7;
    
    std::cout << "z = " << z << std::endl;
    std::cout << "*p = " << *p << std::endl;

    char c = 'c';
    char& rc = c;
    const int& trc = c;
    rc = 'a';

    std::cout << "c = " << c << std::endl;
    std::cout << "rc = " << rc << std::endl;
    std::cout << "trc = " << trc << std::endl;

    return 0;
}
