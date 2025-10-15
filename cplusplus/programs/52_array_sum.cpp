#include <iostream>

int sum(const int* a, int n)
{
    int s=0;
    
    for(int i=0;i<n;++i)
        s+=a[i];

    return s;
}

int main()
{
    int a[5]={1,2,3,4,5};

    std::cout << sum(a,5) << std::endl;

    return 0;
}