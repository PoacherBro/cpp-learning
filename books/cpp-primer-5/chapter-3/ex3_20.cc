#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main() {
    vector<int> v_i;
    int input;

    while (cin >> input)
        v_i.push_back(input);

    // 打印每对相邻整数的和
    if (v_i.empty()) {
        cout << "Input at least one integer." << endl;
        return -1;
    } else if (v_i.size() == 1) {
        cout << v_i[0] << " don't have any adjacent elements.";
    } else {
        for (decltype(v_i.size()) i = 0; i < (v_i.size() - 1); ++i) {
            cout << (v_i[i] + v_i[i + 1]) << " ";
        }
    }
    cout << endl;

    // 打印首尾对应整数之和
    decltype(v_i.size()) size = v_i.size();
    if (size % 2 == 0)
        size /= 2;
    else
        size = size / 2 + 1;

    for (decltype(v_i.size()) i = 0; i != size; ++i)
        cout << (v_i[i] + v_i[v_i.size() - i - 1]) << " ";

    cout << endl;

    return 0;
}
