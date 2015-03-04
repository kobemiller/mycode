// =====================================================================================
//
//       Filename:  digui.c
//
//    Description:  递归
//
//        Version:  1.0
//        Created:  2015年03月03日 16时12分04秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

int digui(int x)
{
    if ( x == 1 )
        return 1;
    else
        return x * digui(x-1);
}

int main()
{
    return digui(5);
}
