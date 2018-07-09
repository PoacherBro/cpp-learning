#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::begin; using std::end;
using std::cout; using std::endl;

int main() {
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    int arr[6];
    
    for (auto i = begin(arr); i != end(arr); ++i)
        *i = ivec[i - begin(arr)];

    cout << "Print initialized int array: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
