#include <iostream>
#include <typeinfo>

int main()
{
    // 推测变量类型
    const int ti = 42;
    
    auto tj = ti; // int类型
    std::cout << typeid(tj).name() << std::endl;

    const auto &tk = ti; // const int引用类型
    std::cout << typeid(tk).name() << std::endl;
 
    auto *tp = &ti; // 指向const int的指针，顶层const
    std::cout << typeid(tp).name() << std::endl;
 
    const auto tj2 = ti, &tk2 = ti; // j2是const int类型，k2是绑定const int的常量引用
    std::cout << typeid(tj2).name() << " " << typeid(tk2).name() << std::endl;
 
}
