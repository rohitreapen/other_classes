# make_files_142_171.py
# Creates 30 C++ source files, numbered 142..171, each demonstrating
# a different file-handling technique (text/binary, modes, seeking, etc.).

programs = [
    (142, "write_trunc", r'''#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out1.txt", std::ios::out | std::ios::trunc);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "Hello file!\n";
}'''),

    (143, "write_append", r'''#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out2.txt", std::ios::out | std::ios::app);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "Appending a new line.\n";
}'''),

    (144, "read_tokens", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in3.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string word;
    while (in >> word) std::cout << word << "\n";
}'''),

    (145, "read_lines", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in4.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) std::cout << line << "\n";
}'''),

    (146, "copy_text", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("src5.txt");
    if (!in) { std::cerr << "open src fail\n"; return 1; }
    std::ofstream out("dst5.txt");
    if (!out) { std::cerr << "open dst fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) out << line << "\n";
}'''),

    (147, "fstream_update", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::fstream f("up6.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "Line A\nLine B\n";
    f.flush();
    f.seekg(0);
    std::string s;
    while (std::getline(f, s)) std::cout << s << "\n";
}'''),

    (148, "bin_write", r'''#include <fstream>
#include <iostream>
int main() {
    int a[5] = {1,2,3,4,5};
    std::ofstream out("data7.bin", std::ios::binary);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out.write(reinterpret_cast<const char*>(a), sizeof(a));
}'''),

    (149, "bin_read", r'''#include <fstream>
#include <iostream>
int main() {
    int a[5] = {0};
    std::ifstream in("data7.bin", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    in.read(reinterpret_cast<char*>(a), sizeof(a));
    for (int i=0;i<5;++i) std::cout << a[i] << " ";
    std::cout << "\n";
}'''),

    (150, "bin_append_record", r'''#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    Rec r = {42, 3.14};
    std::ofstream out("log9.bin", std::ios::binary | std::ios::app);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out.write(reinterpret_cast<const char*>(&r), sizeof(r));
}'''),

    (151, "state_bits", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in10.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string s;
    while (true) {
        if (!(in >> s)) break;
        std::cout << s << "\n";
    }
    std::cerr << "eof=" << in.eof() << " fail=" << in.fail() << " bad=" << in.bad() << "\n";
}'''),

    (152, "tell_seek_text", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in11.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::streampos p0 = in.tellg();
    std::string first;
    std::getline(in, first);
    std::cout << "First line: " << first << "\n";
    in.seekg(p0);
    std::string again;
    std::getline(in, again);
    std::cout << "Again: " << again << "\n";
}'''),

    (153, "tell_seek_write", r'''#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out12.txt", std::ios::out | std::ios::trunc);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "XXXXXXXXXX\n";
    out.seekp(0);
    out << "HELLO";
}'''),

    (154, "bin_random_access", r'''#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    std::fstream f("db13.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    Rec r[3] = {{1,1.1},{2,2.2},{3,3.3}};
    f.write(reinterpret_cast<const char*>(r), sizeof(r));
    Rec upd = {2, 9.9};
    f.seekp(sizeof(Rec) * 1, std::ios::beg);
    f.write(reinterpret_cast<const char*>(&upd), sizeof(upd));
}'''),

    (155, "getline_delim", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in14.csv");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string field;
    while (std::getline(in, field, ',')) std::cout << "[" << field << "]\n";
}'''),

    (156, "unformatted_ops", r'''#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("in15.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    int c = in.peek();
    if (c != EOF) std::cout << "peek:" << char(c) << "\n";
    in.ignore(1);
    char ch;
    if (in.get(ch)) std::cout << "get:" << ch << "\n";
    in.putback(ch);
    if (in.get(ch)) std::cout << "get again:" << ch << "\n";
}'''),

    (157, "count_lwc", r'''#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
int main() {
    std::ifstream in("in16.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line; long lines=0, words=0, chars=0;
    while (std::getline(in, line)) {
        ++lines; chars += line.size() + 1;
        std::string w; std::istringstream iss(line);
        while (iss >> w) ++words;
    }
    std::cout << "L="<<lines<<" W="<<words<<" C~="<<chars<<"\n";
}'''),

    (158, "filter_upper", r'''#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::ifstream in("src17.txt");
    std::ofstream out("dst17.txt");
    if (!in || !out) { std::cerr << "open fail\n"; return 1; }
    char ch;
    while (in.get(ch)) out << char(std::toupper((unsigned char)ch));
}'''),

    (159, "merge_sorted", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream a("a18.txt"), b("b18.txt");
    std::ofstream out("m18.txt");
    if (!a || !b || !out) { std::cerr << "open fail\n"; return 1; }
    std::string s, t;
    bool ha = bool(std::getline(a, s)), hb = bool(std::getline(b, t));
    while (ha || hb) {
        if (!hb || (ha && s <= t)) { out << s << "\n"; ha = bool(std::getline(a, s)); }
        else                        { out << t << "\n"; hb = bool(std::getline(b, t)); }
    }
}'''),

    (160, "csv_parse_simple", r'''#include <fstream>
#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ifstream in("data19.csv");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::string> fields;
        std::string cur;
        for (std::size_t i=0;i<line.size();++i) {
            if (line[i]==','){ fields.push_back(cur); cur.clear(); }
            else cur += line[i];
        }
        fields.push_back(cur);
        for (std::size_t i=0;i<fields.size();++i)
            std::cout << "[" << fields[i] << "]";
        std::cout << "\n";
    }
}'''),

    (161, "is_open_close", r'''#include <fstream>
#include <iostream>
int main() {
    std::ofstream out;
    out.open("out20.txt");
    if (!out.is_open()) { std::cerr << "open fail\n"; return 1; }
    out << "OK\n";
    out.close();
    if (out.is_open()) std::cerr << "still open?\n";
}'''),

    (162, "bin_size", r'''#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("data7.bin", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    in.seekg(0, std::ios::end);
    std::streampos sz = in.tellg();
    std::cout << "bytes=" << sz << "\n";
}'''),

    (163, "chunk_copy_bin", r'''#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("big22.bin", std::ios::binary);
    std::ofstream out("copy22.bin", std::ios::binary);
    if (!in || !out) { std::cerr << "open fail\n"; return 1; }
    const std::size_t BUFSZ = 4096;
    char buf[BUFSZ];
    while (in) {
        in.read(buf, BUFSZ);
        std::streamsize n = in.gcount();
        if (n > 0) out.write(buf, n);
    }
}'''),

    (164, "flags_combo", r'''#include <fstream>
#include <iostream>
int main() {
    std::fstream f("combo23.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "Appended line\n";
}'''),

    (165, "create_then_read", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    { std::ofstream out("maybe24.txt", std::ios::app); }
    std::ifstream in("maybe24.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string s; while (std::getline(in, s)) std::cout << s << "\n";
}'''),

    (166, "sum_avg", r'''#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("nums25.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    long long sum = 0; long long n = 0; long long x;
    while (in >> x) { sum += x; ++n; }
    if (n) std::cout << "sum="<<sum<<" avg="<<(double)sum/n<<"\n";
}'''),

    (167, "write_then_append", r'''#include <fstream>
#include <iostream>
int main() {
    { std::ofstream a("log26.txt"); a << "First\n"; }
    { std::ofstream b("log26.txt", std::ios::app); b << "Second\n"; }
}'''),

    (168, "overwrite_prefix", r'''#include <fstream>
#include <iostream>
int main() {
    std::fstream f("x27.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "ABCDEFGHIJ\n";
    f.seekp(3);
    f << "xyz";
}'''),

    (169, "read_record_n", r'''#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    std::ifstream in("db13.bin", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    Rec r;
    std::size_t n = 2;
    in.seekg(sizeof(Rec)*n, std::ios::beg);
    if (in.read(reinterpret_cast<char*>(&r), sizeof(r)))
        std::cout << "id="<<r.id<<" x="<<r.x<<"\n";
}'''),

    (170, "split_lines", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("in29.txt");
    std::ofstream odd("odd29.txt"), even("even29.txt");
    if (!in || !odd || !even) { std::cerr << "open fail\n"; return 1; }
    std::string line; long i=0;
    while (std::getline(in, line)) {
        (++i % 2 ? odd : even) << line << "\n";
    }
}'''),

    (171, "rotate_log", r'''#include <fstream>
#include <iostream>
#include <string>
int main() {
    {   std::ifstream in("app30.log");
        std::ofstream out("app30.bak");
        if (in && out) {
            std::string line;
            while (std::getline(in, line)) out << line << "\n";
        }
    }
    {   std::ofstream trunc("app30.log", std::ios::trunc);
        if (trunc) trunc << "Log rotated.\n";
    }
}'''),
]

import os

def main():
    for num, slug, code in programs:
        fname = f"{num}_{slug}.cpp"
        with open(fname, "w", newline="\n") as f:
            f.write(code.strip() + "\n")
        print("wrote", fname, f"({len(code.splitlines())} lines)")

if __name__ == "__main__":
    main()
