#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main() {
    vector<int> v(10, 2);

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= 2;
    }

    for (auto i : v)
        cout << i << " ";

    cout << endl;

    return 0;
}
