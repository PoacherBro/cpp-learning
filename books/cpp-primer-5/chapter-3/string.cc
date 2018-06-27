#include <iostream>
#include <string>

using std::string;

int main()
{
    string s1; // 默认初始化，s1是一个空字符串；直接初始化
    string s2 = s1; // s2是s1的副本；拷贝初始化
    string s3 = "hiya";  // s3是该字符串字面值的副本；拷贝初始化
    string s4(10, 'c');  // s4的内容是 cccccccccc；直接初始化

    return 0;
}
