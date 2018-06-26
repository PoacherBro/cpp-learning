#include <iostream>
#include <typeinfo>

int main()
{
    // 练习2.36
    int a = 3, b = 4;
    decltype(a) c = a; // int, initilized to 3
    decltype((b)) d = a; // int&, bind to a
    ++c; // 4
    ++d; // 4, means a = 4

    std::cout << "decltype(a) is " <<  typeid(c).name() << "\n";
    std::cout << "decltype((b)) is " << typeid(d).name() << "\n";
    std::cout << "++c is " << c << "\n";
    std::cout << "++d is " << d << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << std::endl;

    // 练习2.37
    // current a = 4, b = 4
    b = 5;
    decltype(a = b) d1 = a; // int&, bind to a, and (a=b) will not executed
    std::cout << "decltype(a = b) is " << typeid(d1).name() << "\n";
    std::cout << "a = " << a << "\n"; // a still is 4
    std::cout << std::endl;

    return 0;
}
