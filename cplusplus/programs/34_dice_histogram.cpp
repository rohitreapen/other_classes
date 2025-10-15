#include <iostream>

int main()
{
    int n;
    
    std::cout << "Enter number of rolls: ";
    std::cin >> n;
    if(n <= 0)
        return 0;

    int cnt[7];
    for(int i=0; i<7; ++i)
        cnt[i]=0;

    for(int i=0;i<n;++i)
    {
        int x;
        std::cin>>x; 
        
        if(x>=1 && x<=6)
            ++cnt[x];
    }

    for(int face=1; face<=6; ++face)
    {
        std::cout << face << ": ";
        for(int k=0; k<cnt[face]; ++k)
            std::cout << '*';
        std::cout<<" (" << cnt[face] << ")\n";
    }

    return 0;
}