#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin; using std::endl;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
        cout << "Same string!" << endl;
    else
        cout << "Bigger one: " << (s1 > s2 ? s1 : s2) << endl;

    auto size1 = s1.size();
    auto size2 = s2.size();
    if (size1 != size2)
        cout << "Longger one: " << (size1 > size2 ? s1 : s2) << endl;
    else
        cout << "Same size!" << endl;

    return 0;
}
