
#include <iostream>
class Buffer {
    int* data; int n;
public:
    explicit Buffer(int N): data(new int[N]), n(N){ for(int i=0;i<n;++i) data[i]=0; }
    Buffer(const Buffer& o): data(new int[o.n]), n(o.n){ for(int i=0;i<n;++i) data[i]=o.data[i]; }
    Buffer& operator=(const Buffer& o){
        if(this!=&o){
            int* nd = new int[o.n];
            for(int i=0;i<o.n;++i) nd[i]=o.data[i];
            delete[] data; data=nd; n=o.n;
        }
        return *this;
    }
    ~Buffer(){ delete[] data; }
    int& operator[](int i){ return data[i]; }
    int size() const { return n; }
};
int main(){
    Buffer a(3); a[1]=42; Buffer b=a;
    std::cout<<b[0] << " " << b[1]<<" " << b[2] << "\n";
}