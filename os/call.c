
int func1(int *n, int *m)
{
    return (*n) + (*m);
}

int func2(int c)
{
    return c++;
}

int main()
{
    int a = 3;
    int b = 4;
    int c = 8;

    func1(&a, &b);
    func2(c);

    return 0;
}
