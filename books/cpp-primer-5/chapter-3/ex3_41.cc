#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::begin; using std::end;
using std::cout; using std::endl;

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(arr), end(arr));

    cout << "Print initialized vector<int>: \n";
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
