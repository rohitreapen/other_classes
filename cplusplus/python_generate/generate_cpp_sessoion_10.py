# make_stl_1_30.py
import os, json

ROOT = "stl_1_30_pack"
SRC  = os.path.join(ROOT, "src")
VSC  = os.path.join(ROOT, ".vscode")
os.makedirs(SRC, exist_ok=True)
os.makedirs(VSC, exist_ok=True)

def W(idx, name, body):
    fname = "%03d_%s.cpp" % (idx, name)
    path = os.path.join(SRC, fname)
    with open(path, "w") as f:
        f.write(body.strip() + "\n")
    print("Wrote", fname)

# VS Code build task (C++98, MSYS2 g++)
tasks = {
  "version": "2.0.0",
  "tasks": [
    {
      "label": "C++98: build active file",
      "type": "shell",
      "command": "g++",
      "args": [
        "-std=c++98", "-O2", "-Wall", "-Wextra", "-pedantic",
        "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}.exe"
      ],
      "group": {"kind": "build", "isDefault": True},
      "problemMatcher": ["$gcc"]
    }
  ]
}
with open(os.path.join(VSC, "tasks.json"), "w") as f:
    json.dump(tasks, f, indent=2)

i = 112

# 1) vector basics
W(i, "vector_basics", r"""
#include <iostream>
#include <vector>
int main() {
    std::vector<int> v;
    v.push_back(3); v.push_back(1); v.push_back(4);
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 2) vector + sort
W(i, "vector_sort", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {5,2,9,1};
    std::vector<int> v(a, a+4);
    std::sort(v.begin(), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 3) list basics
W(i, "list_iterate", r"""
#include <iostream>
#include <list>
int main() {
    std::list<int> L;
    L.push_back(2); L.push_front(1); L.push_back(3);
    for (std::list<int>::iterator it=L.begin(); it!=L.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 4) deque basics
W(i, "deque_double_ended", r"""
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(2); d.push_back(3); d.push_front(1);
    for (std::size_t i=0;i<d.size();++i) std::cout<<d[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 5) set (ordered unique)
W(i, "set_ordered_unique", r"""
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(3); s.insert(1); s.insert(3);
    for (std::set<int>::iterator it=s.begin(); it!=s.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 6) multiset (ordered duplicates)
W(i, "multiset_duplicates", r"""
#include <iostream>
#include <set>
int main() {
    std::multiset<int> ms;
    ms.insert(3); ms.insert(1); ms.insert(3);
    std::cout<<"count(3)="<<ms.count(3)<<"\n";
}
"""); i+=1

# 7) map (key->value)
W(i, "map_freq", r"""
#include <iostream>
#include <map>
#include <string>
int main() {
    std::map<std::string,int> freq;
    ++freq["apple"]; ++freq["banana"]; ++freq["apple"];
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
        std::cout<<it->first<<": "<<it->second<<"\n";
}
"""); i+=1

# 8) multimap equal_range
W(i, "multimap_equal_range", r"""
#include <iostream>
#include <map>
#include <string>
#include <utility>
int main() {
    std::multimap<std::string,int> mm;
    mm.insert(std::make_pair("grp",1));
    mm.insert(std::make_pair("grp",2));
    mm.insert(std::make_pair("other",9));
    std::pair<std::multimap<std::string,int>::iterator,
              std::multimap<std::string,int>::iterator> r = mm.equal_range("grp");
    for (std::multimap<std::string,int>::iterator it=r.first; it!=r.second; ++it)
        std::cout<<it->second<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 9) pair / make_pair
W(i, "pair_make_pair", r"""
#include <iostream>
#include <utility>
#include <string>
int main() {
    std::pair<std::string,int> p = std::make_pair(std::string("id"), 42);
    std::cout<<p.first<<" "<<p.second<<"\n";
}
"""); i+=1

# 10) stack (LIFO)
W(i, "stack_lifo", r"""
#include <iostream>
#include <stack>
int main() {
    std::stack<int> st;
    st.push(10); st.push(20);
    std::cout<<st.top()<<"\n";
    st.pop();
    std::cout<<st.top()<<"\n";
}
"""); i+=1

# 11) queue (FIFO)
W(i, "queue_fifo", r"""
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(1); q.push(2); q.push(3);
    std::cout<<q.front()<<" "<<q.back()<<"\n";
    q.pop();
    std::cout<<q.front()<<"\n";
}
"""); i+=1

# 12) priority_queue (max-heap)
W(i, "priority_queue_maxheap", r"""
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(5); pq.push(1); pq.push(9);
    while(!pq.empty()){ std::cout<<pq.top()<<" "; pq.pop(); }
    std::cout<<"\n";
}
"""); i+=1

# 13) bitset
W(i, "bitset_8bits", r"""
#include <iostream>
#include <bitset>
#include <string>
int main() {
    std::bitset<8> b(std::string("00010110"));
    std::cout<<"bits set = "<<b.count()<<"\n";
    std::cout<<"b[1] = "<<b[1]<<"\n";
    b.flip(2);
    std::cout<<b<<"\n";
}
"""); i+=1

# 14) iterators begin/end
W(i, "iterators_begin_end", r"""
#include <iostream>
#include <vector>
int main() {
    int a[] = {3,1,4};
    std::vector<int> v(a,a+3);
    for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 15) back_inserter + copy
W(i, "back_inserter_copy", r"""
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
    int a[] = {1,2,3};
    std::vector<int> v;
    std::copy(a, a+3, std::back_inserter(v));
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 16) find + count
W(i, "find_count", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,3,3,7};
    std::vector<int> v(a,a+4);
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
    if (it!=v.end()) std::cout<<"first 3 at index "<<(it - v.begin())<<"\n";
    std::cout<<"count(3) = "<<std::count(v.begin(), v.end(), 3)<<"\n";
}
"""); i+=1

# 17) erase-remove
W(i, "erase_remove", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,2,3,2,4};
    std::vector<int> v(a,a+5);
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 18) unique after sort
W(i, "unique_after_sort", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {3,1,3,2,2,1};
    std::vector<int> v(a,a+6);
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 19) equal_range
W(i, "equal_range_binary_search", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,2,2,2,5};
    std::vector<int> v(a,a+5);
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> r =
        std::equal_range(v.begin(), v.end(), 2);
    std::cout<<"2s in ["<<(r.first - v.begin())<<", "<<(r.second - v.begin())<<")\n";
}
"""); i+=1

# 20) stable_sort with comparator
W(i, "stable_sort_by_length", r"""
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
struct ByLen {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    }
};
int main() {
    std::string a[] = {"bb","a","ccc","aa"};
    std::vector<std::string> v(a,a+4);
    std::stable_sort(v.begin(), v.end(), ByLen());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 21) transform + toupper
W(i, "transform_toupper", r"""
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
int up(int c){ return std::toupper((unsigned char)c); }
int main() {
    std::string s="MiT";
    std::transform(s.begin(), s.end(), s.begin(), up);
    std::cout<<s<<"\n";
}
"""); i+=1

# 22) accumulate sum/product
W(i, "accumulate_sum_product", r"""
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
int main() {
    int a[] = {1,2,3,4};
    std::vector<int> v(a,a+4);
    int sum  = std::accumulate(v.begin(), v.end(), 0);
    int prod = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout<<sum<<" "<<prod<<"\n";
}
"""); i+=1

# 23) set_union & set_intersection
W(i, "set_union_intersection", r"""
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
    int A[] = {1,2,4}, B[] = {2,3,4};
    std::vector<int> a(A,A+3), b(B,B+3), out;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    for (std::size_t i=0;i<out.size();++i) std::cout<<out[i]<<" "; std::cout<<"\n";
    out.clear();
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    for (std::size_t i=0;i<out.size();++i) std::cout<<out[i]<<" "; std::cout<<"\n";
}
"""); i+=1

# 24) partition (not stable)
W(i, "partition_even_first", r"""
#include <iostream>
#include <vector>
#include <algorithm>
struct IsEven{ bool operator()(int x) const { return x%2==0; } };
int main() {
    int A[] = {1,2,3,4,5,6};
    std::vector<int> v(A,A+6);
    std::partition(v.begin(), v.end(), IsEven());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 25) remove_if + erase
W(i, "remove_if_less_than_3", r"""
#include <iostream>
#include <vector>
#include <algorithm>
struct LessThan3{ bool operator()(int x) const { return x<3; } };
int main() {
    int A[] = {1,2,3,4};
    std::vector<int> v(A,A+4);
    v.erase(std::remove_if(v.begin(), v.end(), LessThan3()), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 26) map with custom comparator (descending)
W(i, "map_descending_keys", r"""
#include <iostream>
#include <map>
#include <string>
#include <functional>
int main() {
    std::map<int,std::string, std::greater<int> > m;
    m[2]="two"; m[1]="one"; m[3]="three";
    for (std::map<int,std::string,std::greater<int> >::iterator it=m.begin(); it!=m.end(); ++it)
        std::cout<<it->first<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 27) stable_partition (keep order)
W(i, "stable_partition_uppercase", r"""
#include <iostream>
#include <algorithm>
#include <string>
struct IsUpper{ bool operator()(char c) const { return c>='A' && c<='Z'; } };
int main() {
    std::string s="aAbBcC";
    std::stable_partition(s.begin(), s.end(), IsUpper());
    std::cout<<s<<"\n"; // "ABCabc"
}
"""); i+=1

# 28) rotate (cyclic shift)
W(i, "rotate_cyclic_shift", r"""
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int A[] = {1,2,3,4,5};
    std::vector<int> v(A,A+5);
    std::rotate(v.begin(), v.begin()+2, v.end()); // [1,2|3,4,5] -> [3,4,5,1,2]
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 29) replace / replace_if
W(i, "replace_and_replace_if", r"""
#include <iostream>
#include <vector>
#include <algorithm>
struct IsOdd{ bool operator()(int x) const { return x%2==1; } };
int main() {
    int A[] = {1,2,3,4,5};
    std::vector<int> v(A,A+5);
    std::replace(v.begin(), v.end(), 2, 20);
    std::replace_if(v.begin(), v.end(), IsOdd(), 99);
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
"""); i+=1

# 30) stream iterators + map (word count)
W(i, "istream_iterators_wordcount", r"""
#include <iostream>
#include <iterator>
#include <string>
#include <map>
int main() {
    std::istream_iterator<std::string> in(std::cin), end;
    std::map<std::string,int> freq;
    while (in != end) { ++freq[*in]; ++in; }
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
        std::cout<<it->first<<": "<<it->second<<"\n";
}
""")

print("\nAll files written to:", SRC)
print("VS Code task written to:", os.path.join(VSC, "tasks.json"))
