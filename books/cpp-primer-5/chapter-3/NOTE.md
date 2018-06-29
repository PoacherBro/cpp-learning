# 3.1 命名空间的`using`声明   

域操作符（::）：编译器应从操作符左侧名字所显示的作用域中寻找右侧那个名字。  

使用`using`声明，则可以省略命名空间。  
```cpp
using namespace::name
```
例如`using std::cout;`。  
一旦声明了上述语句，就可以直接访问命名空间中的名字。  

**注意**：使用逗号，并且用一行声明所有命名空间名字，需要C++17才行。  

- 每个名字都需要独立的`using`声明  
- 头文件不应该包含`using`声明  


# 3.2 标准库类型 `string`  

```cpp
#include <string>
using std::string;
```

## 3.2.1 定义和初始化`string`对象  

| 初始化`string`对象的方式 |                                                             |
| ------------------------ | ----------------------------------------------------------- |
| `string s1`              | 默认初始化，`s1`是一个空串                                  |
| `string s2(s1)`          | `s2`是`s1`的副本                                            |
| `string s2 = s1`         | 等价于`s2(s1)`，`s2`是`s1`的副本                            |
| `string s3("value")`     | `s3`是字面值`"value"`的副本，除了字面值最后的那个空支字符外 |
| `string s3 = "value"`    | 等价于`s3("value")`，`s3`是字面值`"value"`的副本            |
| `string s4(n, c)`        | 把`s4`初始化为连续`n`个字符`c`组成的串                      |

### 直接初始化和拷贝初始化  

如果使用等号初始化一个变量，实际上执行的**拷贝初始化（copy initialization）**，编译器把等号右侧的初始值拷贝到新创建的对象中去。  
与之相反，如果不使用等号，则执行的是**直接初始化（direct initialization）**。  

## 3.2.2 `string`对象上的操作  

| `string`的操作   |                                                              |
| ---------------- | ------------------------------------------------------------ |
| `os << s`        | 将`s`写到输出流`os`当中，返回`os`                            |
| `is >> s`        | 从`is`中读取字符串赋给`s`，字符串以空白分隔，返回`is`        |
| `getline(is, s)` | 从`is`中读取一行赋给`s`，返回`is`                            |
| `s.empty()`      | `s`为空返回`true`，否则返回`false`                           |
| `s.size()`       | 返回`s`中字符的个数，类型是`size_type`                       |
| `s[n]`           | 返回`s`中第`n`个字符的**引用**，位置`n`从0计起               |
| `s1 + s2`        | 返回`s1`和`s2`连接后的结果                                   |
| `s1 = s2`        | 用`s2`的副本代替`s1`中原来的字符                             |
| `s1 == s2`       | 如果`s1`和`s2`中所含的字符完全一样，则它们相等；`string`对象的相等性判断对字母的大小写敏感 |
| `s1 != s2`       |                                                              |
| `<, <=, >, >=`   | 利用字符在字典中的顺序进行比较，且对字母的大小写敏感         |