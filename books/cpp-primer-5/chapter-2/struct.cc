#include <iostream>

int main()
{
    struct Readout {
        int value; // 4byte
        char hour; // 1byte
        char seq;  // 1byte
    };

    std::cout << sizeof(Readout) << std::endl; // 8,因为会内存对齐

    return 0;
}
