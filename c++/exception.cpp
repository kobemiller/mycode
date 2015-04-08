#include <iostream>

int main()
{
    try
    {
        throw 20;
    }
    catch (int e)
    {
        std::cout << "an exception occurred. exception number: " << e << std::endl;
    }

    return 0;
}
