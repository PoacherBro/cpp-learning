#include <iostream>
#include <typeinfo>

int f()
{
    return 0;
}

int main()
{
    int xi = 0;
    decltype(f()) sum = xi; // sum类型就是函数f的返回值，在编译器决定
    std::cout << typeid(sum).name() << std::endl;
    
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x is const int
    decltype(cj) y = x; // y is const int&, and bind to x
    decltype(cj) z; // ERROR, z is a reference, must be initialized

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // OK, b is int, not initilized
    decltype(*p) c; // ERROR, c is int&

    decltype((i)) d; // ERROR, d is int&
    decltype(i) e; // OK, e is int

    return 0;
}
