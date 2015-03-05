/*
 * 二维数组名可以理解为指向数组的指针
 *
 * 声明指向二维数组的指针：
 * int  matrix[3][10];
 * int  (*mp)[10] = matrix;
 * 不能写作 int *mp = matrix;
 * 这样mp是指向整形的指针，但需要的是指向数组的指针
 * int *mp = &matrix[0][0];
 * int *mp = matrix[0];
 * 这两种声明都创建了一个简单的指向整形的指针，可以逐个访问数据元素
 * 而不是逐行在数组中移动
 * 不能声明为如下形式：
 * int (*p)[] = matrix;
 *
 * 数组指针&&指针数组
 */
#include <stdio.h>

int main()
{
    int matrix[3][10];
    int i, j;

    for ( i = 0; i < 3; i++ )
        for ( j = 0; j < 10; j++ )
            matrix[i][j] = (i+1) * (j+1);
    for ( i = 0; i < 3; i++ )
    {
        for ( j = 0; j < 10; j++ )
            printf("%d      ", matrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
    printf("*matrix + 1 =       %d\n", *matrix + 1);
    printf("*(*matrix+1) =      %d\n", *(*matrix + 1));
    printf("*(matrix + 1) =     %d\n", *(matrix + 1));
    printf("*(*(matrix + 1)) =  %d\n", *(*(matrix + 1)));
    printf("*(matrix + 1) + 5 = %d\n", *(matrix + 1) + 5);
    printf("*(*(matrix+1)+5) =  %d\n", *(*(matrix + 1) + 5));
 
    return 0;
}
