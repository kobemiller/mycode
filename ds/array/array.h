// =====================================================================================
//
//       Filename:  array.h
//
//    Description:  数组的顺序表示和实现
//
//        Version:  1.0
//        Created:  2015年03月04日 23时40分05秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdarg.h>         //标准头文件，提供a_start，va_arg，va_end，用于存取变长参数表
#define MAX_ARRAY_DIM   8   //假设数组维数的最大值为8

struct Array
{
    ElemType    *base;      //数组元素基址
    int         dim;        //数组维数
    int         *bounds;    //数组维界基址
    int         *constants; //数组映像函数常量基址
};

Status InitArray(Array &A, int dim, ...)
{
    int elemtotal = 1, i;   //elemtotal是数组元素总数，初值为1
    va_list ap;
    if ( dim < 1 || dim > MAX_ARRAY_DIM )
        return ERROR;
    A.dim = dim;
    A.bounds = (int *)malloc(dim * sizeof(int));
    if ( !A.bounds )
        exit(OVERFLOW);
    va_start(ap, dim);
    for ( i = 0; i < dim; i++ )
    {
        A.bounds[i] = va_arg(ap, int); 
        if ( A.bounds[i] < 0 )
            return UNDERFLOW;
        elemtotal *= A.bounds[i];
    }
    va_end(ap);
    A.base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if ( !A.base )
        exit(OVERFLOW);
    A.constants = (int *)malloc(dim * sizeof(int));
    if ( !A.constants )
        exit(OVERFLOW);
    A.constants[dim - 1] = 1;
    for ( i = dim - 2; i >= 0; i-- )
        A.constants[i] = A.bounds[i+1] * A.constants[i+1];
    return OK;
}

void DestroyArray(Array &A)
{
    if ( A.base )
        free(A.base);
    if ( A.bounds )
        free(A.bounds);
    if ( A.constants )
        free(A.constants);
    A.base = A.bounds = A.constants = NULL;
    A.dim = 0;
}

Status Locate(Array A, va_list ap, int &off)
{
    int i, ind;
    off = 0;
    for ( i = 0; i < A.dim; i++ )
    {
        ind = va_arg(ap, int);
        if ( ind < 0 || ind >= A.bounds[i] )
            return OVERFLOW;
        off += A.constants[i] * ind;
    }
    return OK;
}

Status Value(ElemType &e, Array A, ...)
{
    va_list     ap;
    int         off;
    va_start(ap, A);
    if ( Locate(A, ap, off) == OVERFLOW )
        return ERROR;
    e = *(A.base + off);
    return OK;
}

Status Assign(Array A, ElemType e, ...)
{
    va_list ap;
    int     off;
    va_start(ap, e);
    if ( Locate(A, ap, off) == OVERFLOW )
        return ERROR;
    *(A.base + off) = e;
    return OK;
}

ElemType Max(int num, ...)
{
    va_list ap;
    int     i;
    ElemType m, n;
    if ( num < 1 )
        exit(ERROR);
    va_start(ap, num);
    m = va_arg(ap, ElemType);
    for ( i = 1; i < num; i++ )
    {
        n = va_arg(ap, ElemType);
        if ( m < n )
            m = n;
    }
    va_end(ap);
    return m;
}


