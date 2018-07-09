#include <iostream>

using std::cout; using std::endl;

void test_dimentional_array() {
    int ia[3][2] = {0, 1, 3};

    // 如果不把 a 声明成引用类型，则a的类型是int *，自动转成指针，
    // 然后在使用 a（第二层循环）时，编译不通过
    for (auto &a : ia) {
        for (auto b : a)
            cout << b << " ";

        cout << "\n";
    }

    cout << endl;
}

int main() {
    test_dimentional_array();

    return 0;
}
