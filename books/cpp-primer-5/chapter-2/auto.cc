#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;  // a is int

    // auto类型会去掉右值的顶层const，而保持底层const，但是对于auto引用来说，则会保持原对象的顶层const属性
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    const auto f = ci; // ci的推演类型是int, f是const int

    auto &g = ci; // g是const int引用
    auto &h = 42; // 错误：不能为非常量引用绑定字面值
    const auto &j = 42; // 正确：可以为常量引用绑定字面值

    a = 42; // OK
    b = 42; // OK, b去掉了顶层const，是int类型
    c = 42; // OK
    d = 42; // ERROR, d是int指针
    e = 42; // ERROR, e是指向const int的指针
    g = 42; // ERROR, g是整型常量引用
}
