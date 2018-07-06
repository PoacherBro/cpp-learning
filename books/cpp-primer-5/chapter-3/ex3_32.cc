#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main() {
    int arr[10];
    for (size_t i = 0; i != 10; ++i)
        arr[i] = i;

    // copy array
    constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
    int arr2[size];
    for (size_t i = 0; i != size; ++i)
        arr2[i] = arr[i];

    for(auto i : arr2)
        cout << i << " ";
    cout << endl;

    // rewrite by vector
    vector<int> iv(size);
    for (auto it = iv.begin(); it != iv.end(); ++it)
        *it = it - iv.begin();

    // copy vector
    vector<int> iv2(iv);
    for (auto i : iv2)
        cout << i << " ";
    cout << endl;

    return 0;
}
