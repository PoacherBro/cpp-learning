#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::begin; using std::end;
using std::cout; using std::endl;

/**
 * Compare array based on its iterator pointer
 * @pb1 point to begin of the first array
 * @pe1 point to end of the first array
 * @pb2 
 * @pe2
 */
template<typename T>
bool compare(T* const pb1, T* const pe1, T* const pb2, T* const pe2) {
    if ((pe1 - pb1) != (pe2 - pb2)) // have diff size
        return false;
    else {
        for (auto i = pb1, j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
            if (*i != *j)
                return false;
    }
    return true;
}

int main() {
    int arr1[] = {0, 1, 2};
    int arr2[] = {0, 1, 2, 3};

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are NOT equal." << endl;

    cout << "=========================" << endl;

    vector<int> vec1 = {0, 1, 2};
    vector<int> vec2 = {0, 1, 2};

    if (vec1 == vec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are NOT equal." << endl;

    return 0;
}
