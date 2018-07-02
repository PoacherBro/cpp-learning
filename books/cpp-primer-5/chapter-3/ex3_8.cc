#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    cout << "Please input a string: " << endl;

    string s;
    getline(cin, s);

    decltype(s.size()) i = 0;
    while (i < s.size()) {
        s[i] = 'X';
        ++i;
    }
    cout << "Convert to 'X' (while method): " << s << endl;

    for (i = 0; i < s.size(); ++i) {
        s[i] = 'Y';
    }
    cout << "Conver to 'Y' (for method): " << s << endl;

    return 0;
}
