#include <iostream>
#include <vector>
int main()
{
    int arr[10];
    for ( int i = 0; i < 10; i++ )
        arr[i] = i;
    for ( int i = 0; i < 10; i++ )
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
    std::vector<int> v;
    for ( int i = 0; i < 10; i++ )
        v.push_back(i);
    for ( int i = 0; i < v.size(); i++ )
        std::cout << v[i] << ", ";
    std::cout << std::endl;

    return 0;
}
