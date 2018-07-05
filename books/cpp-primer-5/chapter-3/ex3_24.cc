#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main() {
    vector<int> v_i;
    int input;

    while (cin >> input)
        v_i.push_back(input);

    if (v_i.empty()) {
        cout << "Input at least one integer." << endl;
        return -1;
    } else if (v_i.size() == 1) {
        cout << *v_i.cbegin() << " don't have any adjacent elements.";
    }

    // 打印每对相邻整数的和
    for (auto it = v_i.cbegin(); it + 1 != v_i.cend(); ++it) {
        cout << (*it + *(it + 1)) << " ";
    }
    
    cout << "\n";

    // 打印首尾对应整数之和
    for (auto beg = v_i.cbegin(), end = v_i.cend() - 1; beg <= end;
            ++beg, --end)
        cout << (*beg + *end) << " ";

    cout << endl;

    return 0;
}
