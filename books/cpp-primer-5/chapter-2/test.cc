#include <iostream>

class TestClass
{
private:
    int age;
    std::string name;

public:
    TestClass() {}
    ~TestClass() {}

    void setAge(int v) { this->age = v; }
    int getAge() { return this->age; }

    void setName(std::string v) { this->name = v; }
    std::string getName() { return this->name; }
};

const int& func()
{
    const int i = 0;
    return i;
}

int main()
{
    bool b = true;
    int i = 0;
    short s = 0;
    long l = 0;
    char c = 'a';
    float f = 2.0f;
    double d = 2.0;
    long long ll = 23;
    long double ld = 2.3;

    std::cout << "bool size: " << sizeof(b) << std::endl;
    std::cout << "int size: " << sizeof(i) << std::endl;
    std::cout << "short size: " << sizeof(s) << std::endl;
    std::cout << "long size: " << sizeof(l) << std::endl;
    std::cout << "char size: " << sizeof(c) << std::endl;
    std::cout << "float size: " << sizeof(f) << std::endl;
    std::cout << "double size: " << sizeof(d) << std::endl;
    std::cout << "long long size: " << sizeof(ll) << std::endl;
    std::cout << "long double size: " << sizeof(ld) << std::endl;

    c = true;
    std::cout << "char, value is true: " << c << std::endl;

    i = -1 % 256;
    std::cout << "-1 % 256 = " << i << std::endl;

//    const TestClass tc;
//    tc.setAge(23);

//    std::cout << "Age: " << tc.getAge() << std::endl;

    // 测试返回局部变量的引用 - 会报错
    const int& ri = func();
    std::cout << "ri: " << ri << std::endl;
    
}
