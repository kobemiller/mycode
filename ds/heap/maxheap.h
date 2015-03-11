// =====================================================================================
//
//       Filename:  heap.h
//
//    Description:  堆(大根堆的实现)
//                  二叉堆
//                  一般以顺序表方式存储
//                  性质：1、任意节点小于它的所有后裔，最小元在堆的根上
//                        2、堆总是一棵完全树
//
//        Version:  1.0
//        Created:  2015年03月08日 19时03分02秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
 // =====================================================================================

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a)   ( (sizeof(a)) / (sizeof(a[0])) )

static int m_heap[30];          //数据
static int m_capacity = 30;     //总的容量
static int m_size = 0;          //实际容量

/*
 * 返回data在二叉堆中的索引
 */
int get_index(int data)
{
    int i;
    for ( i = 0; i < m_size; i++ )
        if ( data == m_heap[i] )
            return i;
    return -1;
}

/*
 * 大根堆的向下调整方式
 */
static void maxheap_filterdown(int start, int end)
{
    int c = start;
    int l = 2 * c + 1;
    int tmp = m_heap[c];

    while ( l <= end )
    {
        if ( l < end && m_heap[l] < m_heap[l+1] )
            l++;
        if ( tmp >= m_heap[l] )
            break;
        else
        {
            m_heap[c] = m_heap[l];
            c = l;
            l = 2 * l + 1;
        }
    }
    m_heap[c] = tmp;
}

/*
 * 删除大根堆中的data
 */
int maxheap_remove(int data)
{
    int index;
    if ( m_size == 0 )
        return -1;
    index = get_index(data);
    if ( index == -1 )
        return -1;
    m_heap[index] = m_heap[--m_size];
    maxheap_filterdown(index, m_size - 1);

    return 0;
}

/*
 * 大根堆的向上调整方法
 */
static void maxheap_filterup(int start)
{
    int c = start;
    int p = (c - 1) / 2;
    int tmp = m_heap[c];

    while ( c > 0 )
    {
        if ( m_heap[p] >= tmp )
            break;
        else
        {
            m_heap[c] = m_heap[p];
            c = p;
            p = (p - 1) / 2;
        }
    }
    m_heap[c] = tmp;
}

/*
 * 插入
 */
int maxheap_insert(int data)
{
    if ( m_size == m_capacity )
        return -1;
    m_heap[m_size] = data;
    maxheap_filterup(m_size);
    m_size++;

    return 0;
}

/*
 * 打印
 */
void maxheap_print()
{
    int i;
    for ( i = 0; i < m_size; i++ )
        printf("%d ", m_heap[i]);
}


