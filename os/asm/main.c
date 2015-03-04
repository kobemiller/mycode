// =====================================================================================
//
//       Filename:  main.c
//
//    Description:  练习汇编代码 
//
//        Version:  1.0
//        Created:  2015年03月03日 10时09分28秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

int g(int x)
{
    return x + 3;
}

int f(int x)
{
    return g(x);
}

int main()
{
    return f(8) + 1;
}
