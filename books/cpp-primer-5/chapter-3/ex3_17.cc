#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    string input;
    vector<string> vec_str;

    while (cin >> input)
        vec_str.push_back(input);

    for (auto &str : vec_str)
        for (auto &c : str)
            c = toupper(c);

    for (auto s : vec_str)
        cout << s << "\n";
    cout << endl;

    return 0;
}
