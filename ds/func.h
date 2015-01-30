// =====================================================================================
//
//       Filename:  func.h
//
//    Description:  几个常用的函数
//
//        Version:  1.0
//        Created:  2015年01月30日 01时14分39秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

/*
 * 判断是否相等
 */
Status equal(ElemType c1, ElemType c2)
{
    if ( c1 == c2 )
        return TRUE;
    else
        return FALSE;
}

/*
 * 根据a < , = > b， 分别返回-1，0，1
 */
int comp(ElemType a, ElemType b)
{
    if ( a == b )
        return 0;
    else if ( a < b )
        return -1;
    else
        return 1;
    /*
     * if (a == b )
     *      return 0;
     * else
     *      return (a-b)/abs(a-b);
     */
}

void print(ElemType c)
{
    printf("%d ", c);
}
void print2(ElemType c)
{
    printf("%c ", c);
}
void print1(ElemType &c)
{
    printf("%d ", c);
}

