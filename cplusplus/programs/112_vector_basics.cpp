#include <iostream>
#include <vector>
int main() {
    std::vector<int> v;

    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;

    v.push_back(3);

    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;

    v.push_back(1);
    
    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;

    v.push_back(4);

    for (std::size_t i=0;i<v.size();++i)
        std::cout<<v[i]<<" ";

    std::cout<<"\n";

    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;

    v.push_back(5);

    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;


    v.push_back(10);
    
    std::cout << "Number of elements that can be fit " <<
        "before the vector re-allocates " << v.capacity() << std::endl;


}
