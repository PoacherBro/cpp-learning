#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;  
// using std::cout, std::cin; 使用逗号分隔来一行声明所有，需要C++17才支持

int main()
{
    string s1; // 默认初始化，s1是一个空字符串；直接初始化
    string s2 = s1; // s2是s1的副本；拷贝初始化
    string s3 = "hiya";  // s3是该字符串字面值的副本；拷贝初始化
    string s4(10, 'c');  // s4的内容是 cccccccccc；直接初始化

    string s;
    cin >> s; // 遇到空白停止
    cout << s << endl;

    cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;

   // string word;
   // while (cin >> word)
   //     cout << word << endl;

    string line;
    while (getline(cin, line))
    {
        size_t size = line.size();
        if (!line.empty())
            cout << line << ", size: " << size << endl;
    }

    return 0;
}
