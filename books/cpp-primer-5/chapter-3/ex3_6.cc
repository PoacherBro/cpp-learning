#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    cout << "Please input a string: " << endl;
    string s;
    getline(cin, s);
    if (!s.empty()) {
        // for (auto &c : s) {
        for (char &c : s) {
            c = 'X';
        }
    }

    cout << "Convert to 'X': " << s << endl;

    return 0;
}
