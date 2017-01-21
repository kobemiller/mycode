/*
 * =====================================================================================
 *       Filename:  simplesection.c
 *
 *    Description:  
 *
 *        Created:  2016年11月18日 18时41分30秒
 *       Compiler:  gcc
 * =====================================================================================
 */
int printf(const char *format, ...);

int global_init_var = 84;
int global_uninit_var;

void func1(int i)
{
    printf("%d\n", i);
}

int main()
{
    static int static_var = 85;
    static int static_var2;
    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);

    return a;
}
