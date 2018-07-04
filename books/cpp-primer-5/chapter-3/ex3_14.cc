#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

typedef vector<int> vec_int;

int main() {
    cout << "Please input integer: " << endl;

    vec_int v;
    int input;
    while (cin >> input) {
        v.push_back(input);
    }

    cout << "Print input: " << endl;
    for (auto i : v)
        cout << i << endl;

    return 0;
}
