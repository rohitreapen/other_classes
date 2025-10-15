# make_lab_pack.py
import os, json, zipfile
root = "memory_mgmt_lab_pack"
src  = os.path.join(root, "src")
# vsc  = os.path.join(root, ".vscode")
os.makedirs(src, exist_ok=True)
# os.makedirs(vsc, exist_ok=True)

# tasks = {
#   "version": "2.0.0",
#   "tasks": [{
#     "label":"C++98: build active file","type":"shell","command":"g++",
#     "args":["-std=c++98","-O2","-Wall","-Wextra","-pedantic","${file}","-o","${fileDirname}/${fileBasenameNoExtension}.exe"],
#     "group":{"kind":"build","isDefault":True},"problemMatcher":["$gcc"]
#   }]
# }
# open(os.path.join(vsc,"tasks.json"),"w").write(json.dumps(tasks,indent=2))

def W(name, body):
    open(os.path.join(src, name),"w").write(body)

# (For brevity, same 25 sources as in Option A — copy the bodies from the PowerShell script above)
# Paste all W("filename.cpp", """...""") calls here exactly as above.
W ("87_stack_vs_heap.cpp", """
#include <iostream>
int main() {
    int a = 5;
    int* p = new int(5);
    std::cout << a << " " << *p << "\n";
    delete p;
}""")

W ("88_dangling_from_local.cpp","""
#include <iostream>
int* bad() { int x = 5; return &x; }
int main() {
    int* p = bad();
    std::cout << "Dangling demo; do not dereference p!\n";
}""")

W ("89_heap_return_ok.cpp", """
#include <iostream>
int* make_five() { int* p = new int(5); return p; }
int main() {
    int* p = make_five();
    std::cout << *p << "\n";
    delete p;
}""")
W ("90_new_array.cpp", """
#include <iostream>
int main() {
    int n = 5;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) { a[i] = i * i; }
    for (int i = 0; i < n; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
    delete[] a;
}""")
W ("91_leak_demo.cpp", """
int main() {
    int* a = new int[1000000];
    // forgot: delete[] a;
    return 0;
}""")
W ("92_double_delete.cpp", """
#include <iostream>
int main() {
    int* p = new int(7);
    delete p;
    // delete p; // UB if uncommented
    std::cout << "Freed once; second delete would be UB.\n";
}""")
W ("93_delete_mismatch.cpp", """
int main() {
    int* a = new int[3];
    // delete a; // WRONG
    delete[] a; // RIGHT
}""")
W ("94_new_uninit_then_set.cpp", """
#include <iostream>
int main() {
    int* p = new int;
    *p = 42;
    std::cout << *p << "\n";
    delete p;
}""")
W ("95_ctor_on_new.cpp", """
#include <iostream>
class X { public: X(){ std::cout << "X()\n"; } };
int main() {
    X* p = new X; delete p;
    X* a = new X[3]; delete[] a;
}""")
W ("96_dangling_after_delete.cpp", """
#include <iostream>
int main() {
    int* p = new int(9);
    delete p;
    // std::cout << *p << "\n"; // would be dangling
    p = 0;
}""")
W ("97_raii_int.cpp", """
#include <iostream>
class IntOwner {
    int* p;
public:
    explicit IntOwner(int v) : p(new int(v)) {}
    ~IntOwner(){ delete p; }
    int get() const { return *p; }
};
int main() {
    IntOwner x(10);
    std::cout << x.get() << "\n";
}""")
W ("98_rule_of_three.cpp", """
#include <iostream>
#include <cstring>
class Name {
    char* s;
public:
    Name(): s(0) {}
    explicit Name(const char* t){ s=new char[std::strlen(t)+1]; std::strcpy(s,t); }
    Name(const Name& o){ if(o.s){ s=new char[std::strlen(o.s)+1]; std::strcpy(s,o.s);} else s=0; }
    Name& operator=(const Name& o){
        if(this!=&o){
            char* ns=0;
            if(o.s){ ns=new char[std::strlen(o.s)+1]; std::strcpy(ns,o.s); }
            delete[] s; s=ns;
        }
        return *this;
    }
    ~Name(){ delete[] s; }
    const char* c_str() const { return s? s : ""; }
};
int main() {
    Name a("Alice"), b=a;
    std::cout << b.c_str() << "\n";
}""")
W ("99_shallow_copy_pitfall.cpp", """
#include <iostream>
class Bad { public: char* s; };
int main() {
    char buf[] = "hi";
    Bad a; a.s = buf;
    Bad b = a;
    b.s[0] = 'b';
    std::cout << a.s << "\n";
}""")
W ("100_return_heap_array.cpp", """
#include <iostream>
int* make_arr(int n){
    int* a = new int[n];
    for(int i=0;i<n;++i) a[i]=i;
    return a;
}
int main(){
    int* a = make_arr(5);
    for(int i=0;i<5;++i) std::cout<<a[i]<<" ";
    std::cout<<"\n";
    delete[] a;
}""")
W ("101_transfer_ownership.cpp", """
#include <iostream>
int* make_val(){ return new int(7); }
void take_ownership(int* p){ std::cout<<*p<<"\n"; delete p; }
int main(){
    int* p = make_val();
    take_ownership(p);
    p = 0;
}""")
W ("102_copy_owned_buffer.cpp", """
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
    std::cout<<b[1]<<"\n";
}""")
W ("103_try_delete.cpp", """
#include <iostream>
void might_throw(bool t){ if(t) throw 42; }
int main(){
    int* p = new int(5);
    try{ might_throw(true); }
    catch(...){ delete p; p=0; }
}""")
W ("104_raii_beats_try.cpp", """
#include <iostream>
class Holder{ int* p; public: Holder():p(new int(5)){} ~Holder(){ delete p; } };
void might_throw(){ throw 1; }
int main(){
    try{ Holder h; might_throw(); }
    catch(...){ std::cout<<"no leak\n"; }
}""")
W ("105_nothrow_new.cpp", """
#include <iostream>
#include <new>
int main(){
    int* p = new (std::nothrow) int[1000000000];
    if(!p) std::cout<<"allocation failed\n";
    else delete[] p;
}""")
W ("106_delete_null_safe.cpp", """
int main(){
    int* p = 0;
    delete p;
    delete[] p;
}""")
W ("107_composition_owns.cpp", """
#include <iostream>
#include <cstring>
class Person{
    char* name;
public:
    Person(): name(0) {}
    explicit Person(const char* n){ name=new char[std::strlen(n)+1]; std::strcpy(name,n); }
    ~Person(){ delete[] name; }
    const char* get() const { return name? name : ""; }
};
class Team{
    Person lead;
public:
    explicit Team(const char* n): lead(n) {}
    void print() const { std::cout << lead.get() << "\n"; }
};
int main(){ Team t("Ada"); t.print(); }""")
W ("108_class_new_delete.cpp", """
#include <iostream>
#include <new>
class Tracked{
public:
    static void* operator new(std::size_t sz){ std::cout<<"new "<<sz<<" bytes\n"; return ::operator new(sz); }
    static void operator delete(void* p){ std::cout<<"delete\n"; ::operator delete(p); }
};
int main(){ Tracked* t = new Tracked; delete t; }""")
W ("109_mini_string.cpp", """
#include <iostream>
#include <cstring>
class MiniStr{
    char* s;
public:
    MiniStr(): s(0) {}
    explicit MiniStr(const char* t){ s=new char[std::strlen(t)+1]; std::strcpy(s,t); }
    MiniStr(const MiniStr& o){ if(o.s){ s=new char[std::strlen(o.s)+1]; std::strcpy(s,o.s);} else s=0; }
    MiniStr& operator=(const MiniStr& o){
        if(this!=&o){
            char* ns=0;
            if(o.s){ ns=new char[std::strlen(o.s)+1]; std::strcpy(ns,o.s); }
            delete[] s; s=ns;
        }
        return *this;
    }
    ~MiniStr(){ delete[] s; }
    const char* c_str() const { return s? s : ""; }
};
int main(){ MiniStr a("hi"), b=a; std::cout<<b.c_str()<<"\n"; }""")
W ("110_delete_non_owned.cpp", """
#include <iostream>
class Bad{ public: const char* s; /* ~Bad(){ delete[] s; } */ };
int main(){ Bad b; b.s = "literal"; std::cout << b.s << "\n"; }""")
W ("111_alloc_init_free.cpp", """
#include <iostream>
void alloc(int*& p, int n){ p = new int[n]; }
void init (int* p, int n){ for(int i=0;i<n;++i) p[i]=i; }
void free_(int*& p){ delete[] p; p=0; }
int main(){
    int* a = 0;
    alloc(a,5);
    init(a,5);
    for(int i=0;i<5;++i) std::cout<<a[i]<<" ";
    std::cout<<"\n";
    free_(a);
}""")


# Finally zip it
# zip_path = "memory_mgmt_lab_pack.zip"
# with zipfile.ZipFile(zip_path,"w",zipfile.ZIP_DEFLATED) as z:
#     for base,_,files in os.walk(root):
#         for fn in files:
#             full = os.path.join(base, fn)
#             rel  = os.path.relpath(full, root)
#             z.write(full, arcname=rel)
# print("Created:", zip_path)
