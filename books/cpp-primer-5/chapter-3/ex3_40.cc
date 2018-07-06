#include <iostream>
#include <cstring>
#include <string>

using std::string;
using std::cout; using std::endl;

int main() {
    const char cstr1[] = "hello";
    const char cstr2[] = "world";

    size_t new_size = strlen(cstr1) + strlen(cstr2) + 1;
    // g++ is allowed to init cstr3 with variable new_size 
    // even it is not a constant. 
    // Below code failed in VS2017!!!
    // 
    // for reason pls see: 
    // https://stackoverflow.com/questions/19340544/gcc-allowing-arrays-to-be-initialized-with-variable-length
    char cstr3[new_size] = {};

    strcpy(cstr3, cstr1);
    strcat(cstr3, cstr2);

    cout << cstr3 << endl;

    return 0;
}
