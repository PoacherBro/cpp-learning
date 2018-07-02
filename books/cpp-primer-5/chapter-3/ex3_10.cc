#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    cout << "Please input a string: " << endl;
    string s;
    getline(cin, s);

    cout << "Remove punct: ";
    for (auto c : s)
        if (!ispunct(c))
            cout << c;

    cout << endl;

    return 0;
}
