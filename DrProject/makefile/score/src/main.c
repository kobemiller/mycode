// =====================================================================================
//
//       Filename:  main.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  07/06/2015 10:33:17 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "average.h"

int main()
{
    int scores[10] = {78, 81, 80, 67, 69, 65, 41, 93, 82, 69};
    printf("the player's score is %d\n", average(scores, 10));

    return 0;
}
