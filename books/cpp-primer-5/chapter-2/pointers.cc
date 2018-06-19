#include <iostream>

int main()
{
    int errNumb = 0;
    // 指向常量的指针 low-level const
    int *const curErr = &errNumb;
    const double pi = 3.14159;
    // 指向常量的常量指针 top-level const
    const double *const pip = &pi;
}
