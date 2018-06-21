#include <iostream>

int main()
{
    int errNumb = 0;
    // 指向可变对象的常量指针 top-level const
    int *const curErr = &errNumb;
    const double pi = 3.14159;
    // 指向常量的常量指针 top-level const
    const double *const pip = &pi;

    const int e = 0;
    // 指向对象是一个常量 low-level const
    const int *pe = &e;
}
