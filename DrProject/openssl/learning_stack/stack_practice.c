#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/safestack.h>
#include <openssl/crypto.h>

#define sk_Student_new(st) SKM_sk_new(Student, (st))
#define sk_Student_new_null() SKM_sk_new_null(Student)
#define sk_Student_free(st) SKM_sk_free(Student, (st))
#define sk_Student_num(st) SKM_sk_num(Student, (st))
#define sk_Student_value(st, i) SKM_sk_value(Student, (st), (i))
#define sk_Student_set(st, i, val) SKM_sk_set(Student, (st), (i), (val))
#define sk_Student_zero(st) SKM_sk_zero(Student, (st))
#define sk_Student_push(st, val) SKM_sk_push(Student, (st), (val))
#define sk_Student_unshift(st, val) SKM_sk_unshift(Student, (st), (val))
#define sk_Student_find(st, val) SKM_sk_find(Student, (st), (val))
#define sk_Student_delete(st, i) SKM_sk_delete(Student, (st), (i))
#define sk_Student_delete_ptr(st, ptr) SKM_sk_delete_ptr(Student, (st), (ptr))
#define sk_Student_insert(st, val, i) SKM_sk_insert(Student, (st), (val), (i))
#define sk_Student_set_cmp_func(st, cmp) SKM_sk_set_cmp_func(Student, (st), (cmp))
#define sk_Student_dup(st) SKM_sk_dup(Student, st)
#define sk_Student_pop_free(st, free_func) SKM_sk_pop_free(Student, (st),(free_func))
#define sk_Student_shift(st) SKM_sk_shift(Student, (st))
#define sk_Student_pop(st) SKM_sk_pop(Student, (st))
#define sk_Student_sort(st) SKM_sk_sort(Student, (st))

typedef struct Student_st
{
    char    *name;
    int     age;
    char    *otherinfo;
} Student;
typedef STACK_OF(Student)   Students;
DECLARE_STACK_OF(Student);

Student *Student_Malloc()
{
    Student *a = malloc(sizeof(Student));
    a->name = malloc(20);
    a->otherinfo = malloc(20);

    return a;
}

void student_set(Student *s, char *n, int a, char *o)
{
    strcpy(s->name, n);
    s->age = a;
    strcpy(s->otherinfo, o);

    printf("name: %s\n", s->name);
}

void Student_Free(Student *a)
{
    free(a->name);
    free(a->otherinfo);
    free(a);
}

static int Student_cmp(Student **a, Student **b)
{
    int     ret;

    ret = strcmp((*a)->name, (*b)->name);

    return ret;
}

void print(Students *s)
{
    int i;
    Student *temp = NULL;

    printf("遍历:\n");
    printf("%d\n", sk_Student_num(s));
    for ( i = 0; i < sk_Student_num(s); i++ )
    {
        temp = (Students *)sk_value(s, i);
        printf("%d:     name -- %s\n", i+1, temp->name);
        printf("        age --- %d\n", temp->age);
        printf("        otherinfo - %s\n", temp->otherinfo);
    }
}

int main()
{
    Students     *s = NULL, *snew = NULL;
    Student     *s1 = NULL, *s2 = NULL, *s3 = NULL, *s4 = NULL, *s5 = NULL;
    Student     *one = NULL;
    int         i, num;

    s = sk_Student_new(Student_cmp);
    s1 = Student_Malloc();
    student_set(s1, "km", 24, "kobe");
    s2 = Student_Malloc();
    student_set(s2, "kai", 24, "miller");
    s3 = Student_Malloc();
    student_set(s3, "lin", 23, "l");
    s4 = Student_Malloc();
    student_set(s4, "ting", 25, "x");
    s5 = Student_Malloc();
    student_set(s5, "chen", 50, "tes");

    sk_Student_push(s, s1);
    sk_Student_push(s, s2);
    sk_Student_push(s, s3);
    sk_Student_push(s, s4);
    sk_Student_push(s, s5);

    print(s);

    printf("%d\n", sk_Student_find(s, s3));

    print(s);

    return 0;
}
