#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout; using std::cin; using std::endl;

typedef vector<string> vec_str;

int main() {
    cout << "Please input string: " << endl;

    vec_str v;
    string input;
    while (cin >> input) {
        v.push_back(input);
    }

    cout << "Print input: " << endl;
    for (auto i : v)
        cout << i << endl;

    return 0;
}
