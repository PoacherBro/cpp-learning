#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout; using std::cin; using std::endl;

template<typename T>
static void print_vec(const vector<T> &v) {
    cout << "\n\tSize: " << v.size() << endl;

    cout << "\t";
    // change to use Iterator
    for (auto it = v.cbegin(); it != v.cend(); ++ it)
        cout << *it << " ";

    cout << "\n" << endl;
}

int main() {
    vector<int> v1;
    cout << "Print vector<int> v1: ";
    print_vec(v1);

    vector<int> v2(10);
    cout << "Print vector<int> v2(10): ";
    print_vec(v2);

    vector<int> v3(10, 42);
    cout << "Print vector<int> v3(10, 42): ";
    print_vec(v3);

    vector<int> v4{10};
    cout << "Print vector<int> v4{10}: ";
    print_vec(v4);

    vector<int> v5{10, 42};
    cout << "Print vector<int> v5{10, 42}: ";
    print_vec(v5);

    vector<string> v6{10};
    cout << "Print vector<string> v6{10}: ";
    print_vec(v6);

    vector<string> v7{10, "hi"};
    cout << "Print vector<string> v7{10, \"hi\"}: ";
    print_vec(v7);

    return 0;
}
