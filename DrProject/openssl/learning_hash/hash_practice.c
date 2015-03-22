#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/lhash.h>

typedef struct Student_st
{
    char    name[20];
    int     age;
    char    otherinfo[200];
} Student;

static int Student_cmp(const void *a, const void *b)
{
    char *name_a = ((Student *)a)->name;
    char *name_b = ((Student *)b)->name;

    return strcmp(name_a, name_b);
}

static void PrintValue(Student *a)
{
    printf("name: %s\n", a->name);
    printf("age : %d\n", a->age);
    printf("otherinfo: %s\n", a->otherinfo);
}

static void PrintValue_arg(Student *a, void *b)
{
    int flag = 0;

    flag = *(int *)b;
    printf("用户输入参数为：%d\n", flag);
    printf("name: %s\n", a->name);
    printf("age : %d\n", a->age);
    printf("otherinfo: %s\n", a->otherinfo);
}

int main()
{
    int flag = 11;
    _LHASH   *h;
    Student s1 = {"zcp", 28, "hu bei"},
            s2 = {"forxy", 27, "no info"},
            s3 = {"skp", 24, "student"},
            s4 = {"zhao_zcp", 28, "zcp's name"},
            *s5;
    void *data;

    h = lh_new(NULL, Student_cmp);
    if ( h == NULL )
    {
        printf("err.\n");
        return -1;
    }

    data = &s1;
    lh_insert(h, data);
    data = &s2;
    lh_insert(h, data);
    data = &s3;
    lh_insert(h, data);
    data = &s4;
    lh_insert(h, data);

    lh_doall(h, PrintValue);
    lh_doall_arg(h, PrintValue_arg, (void*)(&flag));
    data = lh_retrieve(h, (const void*)"skp");
    if ( data == NULL )
    {
        printf("can not look up skp!\n");
        lh_free(h);
        return -1;
    }

    s5 = data;
    printf("student name : %s\n", s5->name);
    printf("student age  : %d\n", s5->age);
    printf("student otherinfo: %s\n", s5->otherinfo);

    lh_free(h);
    
    return 0;
}
