void func(int) {}

int main()
{
    int i = 0x7fff;
    long l;
    float f;
    //1 typical castless conversions
    l = i;
    f = i;
    //also works:
    l = static_cast<long>(i);
    f = static_cast<float>(i);

    //2 narrowing conversions
    i = l;  //may lose digits
    i = f;  //may lose info
    //says "I know" eliminates warnings:
    i = static_cast<int>(l);
    i = static_cast<int>(f);
    char c = static_cast<char>(i);

    //3 forcing a conversion from void*
    void* vp = &i;
    //old way produces a dangerous conversion
    float* fp = (float*)vp;
    //new way is equally dangerous
    fp = static_cast<float*>(vp);
    //4 inplicit type conversions, normally performed by the compiler
    double d = 0.0;
    int x = d;  //automatic
    x = static_cast<int>(d);
    func(d);
    func(static_cast<int>(d));
    
    //常量转换const_cast
    //const_cast唯一允许的转换：从const转换为非const或从volatile转换为非volatile
    const int i = 0;
    int* j = (int*)&i;
    j = const_cast<int*>(&i);
    volatile int k = 0;
    int* u = const_cast<int*>(&k);

    return 0;
}
