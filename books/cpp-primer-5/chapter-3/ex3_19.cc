/**
 * List three ways to define a vector and give it 10 elements,
 * each with the value 42.
 * Indicate whether there is a preferred way to do so and why.
 */

#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> iv1(10, 42);
    vector<int> iv2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    
    vector<int> iv3;
    for (int i = 0; i < 10; ++i)
        iv3.push_back(42);

    std::cout << "vector<int> iv1(10, 42) is better way!" << std::endl;
    return 0;
}
