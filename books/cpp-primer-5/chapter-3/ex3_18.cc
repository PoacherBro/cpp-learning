#include <vector>

using std::vector;

int main() {
    // Question: below code is right?
    vector<int> ivec;
    // ivec[0] = 42; // ERROR, access not-exist location

    // OK
    vector<int> ivec1{ 0 };
    ivec1[0] = 42;
    // OR
    ivec1.push_back(42);

    return 0;
}
