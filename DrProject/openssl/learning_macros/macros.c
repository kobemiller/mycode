/*
 * c语言的宏嵌套后，一般的展开规律像函数的参数一样，先展开参数，再分析函数，所以展开顺序是由内而外的
 * 但是当宏中有#则不再展开参数了，如果宏中有##，则先展开函数，再展开里面的参数
 * #把一个符号直接转换为字符串，加""
 */
#include <stdio.h>

#define TO_STRING3(x)   a_##x
#define TO_STRING2(x)   #x
#define TO_STRING(x)    TO_STRING1(x)
#define TO_STRING1(x)   #x
#define PARAM(x)        #x
#define ADDPARAM(x)     INT_##x
/*
 * 当一个宏遇到自己的时候，就停止展开
 */
//#define TEST(x)         (x + TEST(x))
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

int main()
{

    typedef struct student
    {
        int age;
        char *name;
        char *info;
    } Student;
    Student a;
    printf("%d\n", offsetof(Student, age));

    const char *str = TO_STRING(PARAM(ADDPARAM(1)));
    printf("%s\n", str); 	//输出："ADDPARAM(1)"

    str = TO_STRING2(PARAM(ADDPARAM(1)));
    printf("%s\n", str); 	//输出：PARAM(ADDPARAM(1))

    str = TO_STRING(TO_STRING3(PARAM(ADDPARAM(1))));
    printf("%s\n", str); 	//输出：a_PARAM(INT_1)

//    int test = TEST(2);
//    printf("%d\n", test);

    return 0;
}


