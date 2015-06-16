#include <stdio.h>
#include <string.h>

int main()
{
    struct st
    {
        char *name;
        int age;
    };

    struct st *s1;

    strcpy(s1->name, "km");
    s1->age = 10;

    printf("%s, %d\n", s1->name, s1->age);

    return 0;
}
