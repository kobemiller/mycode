/* 
 * http://dog250.blog.51cto.com/2466061/1271116
 * 多级指针本质就是一个链表
 */
#include <stdio.h>
#include <stdlib.h>

void test_1()
{
    int *l1, *l2, *l3, *l4;
    int ba = 0x1234;

    l4 = &ba;
    l3 = &l4;
    l2 = &l3;
    l1 = &l2;
    int *p = l1;

    printf("test_1:\n");
    printf("******************************************\n");
    printf("value: %x\n", (*(int *)p));
    printf("value: %x\n", (**(int **)p));
    printf("value: %x\n", (***(int ***)p));
    printf("value: %x\n", (****(int ****)p));
    printf("******************************************\n");
}

void test_2()
{
    int ba = 0x1234;
    int *l1 = &ba;
    int **l2 = &l1;
    int ***l3 = &l2;
    int ****l4 = &l3;

    int *p = l4;
    printf("test_2:\n");
    printf("******************************************\n");
    printf("value: %x\n", (*(int *)p));
    printf("value: %x\n", (**(int **)p));
    printf("value: %x\n", (***(int ***)p));
    printf("value: %x\n", (****(int ****)p));
    printf("******************************************\n");
}

void test_3()
{
    struct lst
    {
        struct lst *func;
        int value;
    };

    struct lst *l1 = (struct lst*)calloc(1, sizeof(struct lst));
    struct lst *l2 = (struct lst*)calloc(1, sizeof(struct lst));
    struct lst *l3 = (struct lst*)calloc(1, sizeof(struct lst));
    struct lst *l4 = (struct lst*)calloc(1, sizeof(struct lst));

    l1->func = l2;
    l1->value = 0x111;
    l2->func = l3;
    l2->value = 0x222;
    l3->func = l4;
    l3->value = 0x333;
    l4->func = NULL;
    l4->value = 0x444;

    struct lst *p = l1;
    printf("test_3:\n");
    printf("******************************************\n");
    printf("value: %x\n", ((*(struct lst *)p).value));
    printf("value: %x\n", (struct lst*)(**(struct lst **)p).value);
    printf("value: %x\n", (struct lst*)(***(struct lst ***)p).value);
    printf("value: %x\n", (struct lst*)(****(struct lst ****)p).value);
    printf("******************************************\n");
}

/*
 * linus:利用二级指针删除单项链表
 */
void remove_if(node **head, remove_fn rm)
{
    for ( node **curr = head; *curr; )
    {
        node *entry = *curr;
        if ( rm(entry) )
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}

int main()
{
    test_1();
    test_2();
    test_3();

    return 0;
}
