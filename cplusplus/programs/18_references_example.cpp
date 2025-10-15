#include <iostream>
#include <string>

// by value: does NOT affect variable given as input at called location
void bump_by_value(int x) 
{ 
    x += 10; 
}

// by reference: DOES affect variable given as input at called location
void bump_by_ref(int& x) 
{ 
    x += 10;
}

// returns a temporary string (rvalue)
std::string make_message() 
{ 
    return std::string("hello, temporary");
}

int main() 
{
    // 1) A reference is an ALIAS for an existing object
    std::cout << "\n==== " << "Alias behavior" << " ====\n";
    int a = 5;
    int& r = a;      // r MUST be initialized; r refers to 'a'
    std::cout << "a=" << a << ", r=" << r << "\n";
    r = 7;           // writing via r modifies 'a'
    std::cout << "after r=7 -> a=" << a << ", r=" << r << "\n";
    std::cout << "&a=" << &a << ", &r=" << &r << " (same address)\n";

    // 2) References are NOT reseatable
    std::cout << "\n==== " << "Not reseatable (assignment changes the referent)" << " ====\n";
    int b = 42;
    r = b;          // This does NOT rebind r to b;
                    //  r is still bound to a;
                    // instead, r = b assigns b's value into a
    std::cout << "after r=b -> a=" << a << " (now 42), b=" << b
              << ", &r still=" << &r << ", &a=" << &a << " &b=" << &b
              << "\n";

    // 3) Pass-by-value vs pass-by-reference
    std::cout << "\n==== " << "Pass-by-value vs pass-by-reference" << " ====\n";
    int v = 10;
    bump_by_value(v);
    std::cout << "after bump_by_value(v): v=" << v << " (unchanged)\n";
    bump_by_ref(v);
    std::cout << "after bump_by_ref(v):   v=" << v << " (modified)\n";

    // 4) Const reference can bind to temporaries; lifetime is extended
    std::cout << "\n==== " << "Const reference to a temporary (lifetime extension)" << " ====\n";
    const std::string& msg = make_message(); // binds to temporary string
    std::cout << "msg = " << msg << "\n";    // valid:lifetime of temporary variable is extended to end of scope
    // msg[0] = 'H'; // ERROR if uncommented: const reference is read-only

    // 5) Const reference can also bind to lvalues (still an alias)
    std::cout << "\n==== " << "Const reference to an lvalue" << " ====\n";
    const int& cr = a;     // cr refers to 'a' (read-only view)
    std::cout << "a=" << a << ", cr=" << cr << "\n";
    a = 99;                // change the original...
    std::cout << "after a=99 -> cr sees " << cr << " (still refers to a)\n";

    // 6) Reference to an array element
    std::cout << "\n==== " << "Reference to an array element" << " ====\n";
    int arr[3] = {1, 2, 3};
    int& mid = arr[1];     // alias the middle element
    mid = 20;              // modifies arr[1]
    std::cout << "arr: " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";

    // 7) Const reference can bind to a literal (temporary int)
    std::cout << "\n==== " << "Const reference binding to a literal" << " ====\n";
    const int& k = 123;    // binds to a temporary; lifetime extended
    std::cout << "k=" << k << "\n";

    return 0;
}