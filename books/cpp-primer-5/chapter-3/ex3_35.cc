#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout; using std::cin; using std::endl;

int main() {
    int arr[10];
    int *b = begin(arr);
    int *e = end(arr);

    cout << typeid(b).name() << endl;

    for (auto i = b; i != e; ++i)
        *i = 0;

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
