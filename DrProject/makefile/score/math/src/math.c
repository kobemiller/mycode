// =====================================================================================
//
//       Filename:  math.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  07/06/2015 10:41:32 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "math.h"

int Maximum(int array[], int n)
{
    int i, max;

    for ( i = 1, max = array[0]; i < n; i++ )
        max = array[i] > max ? array[i] : max;

    return max;
}

int Minimum(int array[], int n)
{
    int i, min;

    for ( i = 1, min = array[0]; i < n; i++ )
        min = array[i] < min ? array[i] : min;

    return min;
}
