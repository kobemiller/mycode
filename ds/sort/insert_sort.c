// =====================================================================================
//
//       Filename:  insert_sort.c
//
//    Description:  插入排序
//                  思想：每次将一个待排序的记录，按其关键字大小顺序插入到前面
//                        已经排好序的子序列中
//                  分类：
//                      直接插入排序
//                      折半插入排序
//                      希尔排序
//
//        Version:  1.0
//        Created:  2015年03月06日 23时58分37秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>

#define N 20

/*
 * 直接插入排序：
 * 1、查找出第i个元素的待插入位置k
 * 2、将k到i-1中的所有元素全部后移一位
 * 3、插入
 *
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)（仅用了常数个辅助单元）
 * 稳定性：稳定
 */
void insert_sort(int a[], int n)
{
    int i, j, k;
    for ( i = 1; i < n; i++ )
    {
        for( j = i-1; j >= 0; j-- )
            if ( a[j] < a[i] )
                break;
        if ( j != i-1 )
        {
            int temp = a[i];
            for ( k = i-1; k > j; k-- )
                a[k+1] = a[k];
            a[k+1] = temp;
        }
    }
}

/*
 * 折半插入排序
 * 1、折半查找出元素的待插入位置
 * 2、统一的移动待插入位置之后的所有元素
 * 3、插入
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)（仅用了常数个辅助单元）
 * 稳定性：稳定
 */
void zheban_insert_sort(int a[], int n)
{
    int i, j, low, high, mid;
    for ( i = 2; i <= n; i++ )
    {
        a[0] = a[i];
        low = 1;
        high = i - 1;
        while ( low <= high )
        {
            mid = (low + high) / 2;
            if ( a[mid] > a[0] )
                high = mid - 1;
            else
                low = mid + 1;
        }
        for ( j = i-1; j >= high+1; j-- )
            a[j+1] = a[j];
        a[high+1] = a[0];
    }
}

/*
 * 希尔排序：
 * 1、先将待排序表分割为若干个特殊子表，分别进行直接插入排序
 * 2、当整个表中元素基本有序时，再对全体记录进行一次直接插入排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 * 仅适用于顺序存储的线性表
 */
void shell_sort(int a[], int n)
{
    int i, j, gap;
    for ( gap = n / 2; gap > 0; gap /= 2 )
    {
        for ( i = 0; i < gap; i++ )
        {
            for ( j = i + gap; j < n; j++ )
            {
                if ( a[j] < a[j-gap] )
                {
                    int tmp = a[j];
                    int k = j - gap;
                    while ( k >= 0 && a[k] > tmp )
                    {
                        a[k+gap] = a[k];
                        k -= gap;
                    }
                    a[k+gap] = tmp;
                }
           
            }
        }
    }
}

/*
 * 冒泡排序：
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 */
#define swap(a, b)  (a ^= b, b ^= a, a^= b)

void bubble_sort(int a[], int n)
{
    int i, j;
    for ( i = n-1; i > 0; i-- )
        for ( j = 0; j < i; j++ )
            if ( a[j] > a[j+1] )
                swap(a[j], a[j+1]);
}

void bubble_sort_beta(int a[], int n)
{
    int i, j;
    int flag;
    for ( i = n-1; i > 0; i-- )
    {
        flag = 0;
        for ( j = 0; j < i; j++ )
        {
            if ( a[j] > a[j+1] )
            {
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }

        if ( flag == 0 )
            break;
    }
}

/*
 * 快速排序：
 * 1、从数列中挑出一个基准值
 * 2、将所有比基准值小的摆放在基准前面，所有比基准值大的摆在基准的后面
 * 3、递归的把基准值前面的子数列和基准值后面的子序列进行排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(log2 n)
 * 稳定性：不稳定
 */
void quick_sort(int a[], int low, int high)
{
    if ( low < high )
    {
        int i, j, x;
        i = low;
        j = high;
        x = a[i];
        while ( i < j )
        {
            while ( i < j && a[j] > x )
                j--;
            if ( i < j )
                a[i++] = a[j];
            while ( i < j && a[i] < x )
                i++;
            if ( i < j )
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, low, i-1);
        quick_sort(a, i+1, high);
    }
}

/*
 * 选择排序：
 * 1、在未排序的数列中找到最小（或最大）元素，然后将其存放到数列的起始位置
 * 2、再从剩余未排序的数列中找到最小（或最大）元素，然后放到已排序序列的末尾
 * 3、以此类推，直到所有元素均排序完毕
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 */
void select_sort(int a[], int n)
{
    int i, j, min;
    for ( i = 0; i < n; i++ )
    {
        min = i;
        for ( j = i+1; j < n; j++ )
            if ( a[j] < a[min] )
                min = j;
        if ( min != i )
            swap(a[i], a[min]);
    }
}

void print(int a[], int n)
{
    int i;
    for ( i = 0; i < n; i++ )
        printf("%4d ", a[i]);
    printf("\n");
}

int main()
{
    int i, j, a[N];
        
    do 
    {
        for ( i = 0; i < N; i++ )
        {
            a[i] = rand() % 100;
            printf("%4d ", a[i]);
        }
        printf("\n");

        printf("选择菜单：\n");
        printf("1、直接插入排序\n");
        printf("2、折半插入排序\n");
        printf("3、希尔排序\n");
        printf("4、冒泡排序\n");
        printf("5、快速排序\n");
        printf("6、简单选择排序\n");
        printf("7、堆排序\n");
        printf("8、归并排序\n");
        printf("9、基数排序\n");
        printf("0、退出\n");
        scanf("%d", &j);
        switch ( j )
        {
            case 1:
                printf("直接插入排序的结果为：");
                insert_sort(a, N);
                print(a, N);
                break;
            case 2:
                printf("折半插入排序的结果为：");
                zheban_insert_sort(a, N);
                print(a, N);
                break;
            case 3:
                printf("希尔排序的结果为：");
                shell_sort(a, N);
                print(a, N);
                break;
            case 4:
                printf("冒泡排序的结果为：");
                bubble_sort_beta(a, N);
                print(a, N);
                break;
            case 5:
                printf("快速排序的结果为：");
                quick_sort(a, 0, N-1);
                print(a, N);
                break;
            case 6:
                printf("简单选择排序的结果为：");
                select_sort(a, N);
                print(a, N);
                break;
            case 7:
                printf("堆排序的结果为：");
                print(a, N);
                break;
            case 8:
                printf("归并排序的结果为：");
                print(a, N);
                break;
            case 9:
                printf("基数排序的结果为：");
                break;
            case 0:
                exit(0);
                break;
        }
    } while ( 1 );

    return 0;
}
