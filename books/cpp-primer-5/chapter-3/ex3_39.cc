#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cout; using std::endl;

int main() {
    string s1("hello");
    string s2("world");

    if (s1 == s2)
        cout << "Same string";
    else if (s1 > s2)
        cout << s1 << " > " << s2;
    else
        cout << s1 << " < " << s2;
    cout << endl;

    cout << "================" << endl;

    const char cs1[] = "hello";
    const char cs2[] = "world";

    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "Same string";
    else if (result > 1)
        cout << cs1 << " > " << cs2;
    else
        cout << cs1 << " < " << cs2;
    cout << endl;

    return 0;
}
