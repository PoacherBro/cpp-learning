#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    const vector<string> vs{"hi", "world"};

    for (auto &s : vs) {
        cout << s << endl;
    }
    
    // vector<const string> vcs{ "hi", "const world"}; // ERROR: const string is not destructible
    // const vector<const string> cvcs; // ERROR

    return 0;
}
