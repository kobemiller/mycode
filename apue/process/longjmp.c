// =====================================================================================
//
//       Filename:  longjmp.c
//
//    Description:  longjmp对各类变量的影响
//
//        Version:  1.0
//        Created:  12/09/2014 05:03:06 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "../apue.h"
#include "../myerr.h"
int log_to_stderr = 1;

#include <setjmp.h>

static void f1(int, int, int, int);
static void f2();

static jmp_buf      jmpbuffer;
static int          globval;

int main()
{
    int             autoval;
    register int    regival;
    volatile int    volaval;
    static int      statval;

    globval = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;

    if ( setjmp(jmpbuffer) != 0 )
    {
        printf("after longjmp:\n");
        printf("globalval = %d,     autoval = %d,   regival = %d,    volaval = %d,   statval = %d\n",
                globval, autoval, regival, volaval, statval);
        exit(0);
    }

    //change variables after setjmp, but before longjmp
    globval = 95; autoval = 96; regival = 97; volaval = 98; statval = 99;
    f1(autoval, regival, volaval, statval);     //never returns

    exit(0);
}

static void f1(int i, int j, int k, int l)
{
    printf("in f1():\n");
    printf("globalval = %d,     autoval = %d,   regival = %d,    volaval = %d,   statval = %d\n",
            globval, i, j, k, l);
    f2();
}
static void f2()
{
    longjmp(jmpbuffer, 1);
}
