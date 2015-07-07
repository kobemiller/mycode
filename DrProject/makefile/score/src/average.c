// =====================================================================================
//
//       Filename:  average.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  07/06/2015 10:31:19 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "average.h"

int average(int array[], int n)
{
    int i, sum = 0;

    for ( i = 0; i < n; i++ )
        sum += array[i];

    return (sum - Maximum(array, n) - Minimum(array, n)) / (n - 2);
}

