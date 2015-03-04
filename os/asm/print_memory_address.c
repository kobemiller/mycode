#include <stdio.h>

int g1 = 0, g2, g3 = 0;

int max(int i)
{
    int m1 = 0, m2, m3 = 0, *p_max;
    static n1_max = 0, n2_max, n3_max = 0;
    p_max = (int*)malloc(10);

    printf("打印max程序地址\n");
    printf("in max:     0x%08x\n\n", max);
    printf("打印max传入参数的地址\n");
    printf("in max, i:  0x%08x\n\n", &i);
    printf("打印max函数中静态变量地址\n");
    printf("n1_max:     0x%08x\n", &n1_max);
    printf("n2_max:     0x%08x\n", &n2_max);
    printf("n3_max:     0x%08x\n\n", &n3_max);
    printf("打印max函数中局部变量地址\n");
    printf("m1:         0x%08x\n", &m1);
    printf("m2:         0x%08x\n", &m2);
    printf("m3:         0x%08x\n\n", &m3);
    printf("打印max函数中malloc分配的地址\n");
    printf("p_max:      0x%08x\n\n", p_max);

    if ( i )
        return 1;
    else
        return 0;
}

int main(int argc, char **argv)
{
    static int s1 = 0, s2, s3 = 0;
    int v1 = 0, v2, v3 = 0;
    int *p;
    p = (int *)malloc(10);

    printf("打印各全局变量（已初始化）的内存地址\n");
    printf("g1:         0x%08x\n", &g1);
    printf("g2:         0x%08x\n", &g2);
    printf("g3:         0x%08x\n\n", &g3);
    printf("=================================================\n");
    printf("打印程序初始程序main地址\n");
    printf("main:       0x%08x\n\n", main);
    printf("打印主参数地址\n");
    printf("argc:       0x%08x\n\n", &argc);
    printf("argv:       0x%08x\n\n", argv);
    printf("打印各静态变量的内存地址\n");
    printf("s1:         0x%08x\n", &s1);
    printf("s2:         0x%08x\n", &s2);
    printf("s3:         0x%08x\n\n", &s3);
    printf("打印各局部变量的内存地址\n");
    printf("v1:         0x%08x\n", &v1);
    printf("v2:         0x%08x\n", &v2);
    printf("v3:         0x%08x\n\n", &v3);
    printf("打印malloc分配的堆内存地址\n");
    printf("p:          0x%08x\n\n", p);
    printf("=================================================\n");
    max(v1);
    printf("=================================================\n");
    printf("打印子函数起始地址\n");
    printf("max:        0x%08x\n\n", max);

    return 0;
}
