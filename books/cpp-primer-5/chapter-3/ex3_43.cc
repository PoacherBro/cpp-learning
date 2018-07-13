#include <iostream>
#include <iterator>

using std::begin; using std::end;
using std::cout; using std::endl;

int main() {
    int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 };

    cout << "Print array with range for: \n";
    for (int (&p)[4] : ia)
        for (int q : p)
            cout << q << " ";
    cout << "\n";

    cout << "Print array with traditional loop and []: \n";
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << "\n";

    cout << "Print array with traditional loop and pointer: \n";
    for (int (*p)[4] = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}