
#include <dlfcn.h>

int main()
{
    void* handle = dlopen("./libdemo2.so", RTLD_LAZY);
    void (*func)(int) = dlsym(handle, "diamond");
    func(5);
    dlclose(handle);
    return 0;
}
