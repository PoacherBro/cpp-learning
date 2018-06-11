# 第一章  开始

## 练习 1.1  
> 查阅你使用的编译器的文档，确定它所使用的文件命名约定。编译并运行第2页的`main`程序。  

1. 文件命名约定  
* [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/extensions)  
* [File Types Created for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)  

2. 运行`main`程序  
* windows  
![](../images/ex1_1.png)  

## 练习 1.2  
> 改写程序，让它返回-1,。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理`main`返回的错误标识。  

* Windows  
![](../images/ex1_2.png)  

* Linux  
返回**255**，原因查看[这里](http://www.tldp.org/LDP/abs/html/exitcodes.html)。  

## 练习 1.3  
> 编写程序，在标准输出上打印`Hello, World`。  

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## 练习 1.4  
> 我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。  

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```
> 其实我们在使用乘法时，应该是所有数值操作是，特别要注意数值**越界**的情况  
![](../images/ex1_4.png)  

## 练习 1.5
> 我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立语句中。  

```cpp
 #include <iostream>
 
int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2;
    std::cout << std::endl; // Don't forget to add "endl" to flush content
}
```

注意最后的`std::endl`，这是一个被称为 **操作符（manipulator）** 的特殊值。写入`endl`的效果是结束当前行，并将于设备关联的缓冲区（buffer）中的内容刷到设备中。缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅仅停留在内容中等待写入流。  

## 练习 1.6
> 解释下面程序片段是否合法。  
> ```cpp
> std::cout << "The sum of " << v1;
>           << " and " << v2;
>           << " is " << v1 + v2 << std::endl;
> ```
> 如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正？  

此程序不合法，在编译阶段会报出错误：  
```
error: expected primary-expression before ‘<<’ token
```
因为在程序没有结束之前有`;`，只需要移除第一行、第二行末尾的逗号就行。

## 练习 1.7
> 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

源码：
```cpp
#include <iostream>

/* This is a nested test
 * and this comment contains /* */
 */
int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2;
    std::cout << std::endl; // Don't forget to add "endl" to flush content

}
```

编译之后错误是：   
```
ex1_5.cpp:5:3: error: expected unqualified-id before ‘/’ token
  */
   ^
```

## 练习 1.8
> 指出下列哪些输出语句是合法的（如果有的话）：  
> ```cpp
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /* "*/" /* "/*" */;
> ```
> 预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案（编写一个小程序，每次将上述一条语句作为其主体），改成每个编译错误。

编译之后的结果如下：  
![](../images/ex1_8.png)  

修正，在第三条语句中的最后添加一个双引号，整个程序都可以运行：  
```cpp
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```
打印出来结果：  
```cpp
/**/ */ /* 
```

## 练习 1.9
> 编写程序，使用`while`循环将50到100的整数相加。
```cpp
#include <iostream>

int main()
{
    int sum = 0, val = 50;

    while (val <= 100)
    {
        sum += val;
       ++val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
   return 0;
}
```
结果：  
```cpp
Sum of 50 to 100 inclusive is 3825
```

## 练习 1.10
> 除了++运算符将运算对象的值增加1之外，还有一个递减运算符（--）实现将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
```cpp
#include <iostream>

int main()
{
    int val = 10
    while (val >= 0)
    {
        std::cout << val << std::endl;
        --val;   
    }
    return 0;
}
```
## 练习 1.11
> 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
```cpp
#include <iostream>
 
int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Input two numbers:";
    std::cin >> v1 >> v2;
 
    // 确保 v1 <= v2
    if (v1 > v2)
    {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    while (v1 <= v2)
    {
        std::cout << v1 << " ";
        ++v1;
    }
    std::cout << std::endl;
    
    return 0;
}
```

## 练习 1.12
> 下面的`for`循环完成了什么功能？`sum`的终值是多少？
> ```cpp
> int sum = 0;
> for (int i = -100; i <= 100; ++i)
>     sum += i;
> ```

`for`循环实现了-100到100之间整数相加。最后结果为0。

## 练习 1.13
> 使用`for`循环做1.4.1节中的所有练习。

**练习1.9：**  
```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;

    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
   return 0;
}
```

**练习1.10：**  
```cpp
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << " ";
    
    std::cout << std::endl;

    return 0;
}
```

**练习1.11：**  
```cpp
#include <iostream>
 
int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Input two numbers:";
    std::cin >> v1 >> v2;
 
    // 确保 v1 <= v2
    if (v1 > v2)
    {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    for (int i = v1; i <= v2; ++i)
        std::cout << i << " ";

    std::cout << std::endl;
    
    return 0;
}
```

## 练习1.14
> 对比`for`循环和`while`循环，两种形式的优缺点各是什么？  

- `for`相比`while`的优点：  
    - 变量作用域是循环范围内；
    - 对于递增或者递减变化的循环简洁明了，而`while`还需要其他变量控制。
- `while`相比`for`的优点：  
    - 对于只有一个判断条件来说逻辑清晰；
    - 当使用全局变量来递增或者递减时，可读性更好。

一个StackOverflow上相似的问题：[For vs. while in C programming?](https://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)  

## 练习1.15

> 编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。

自行练习就好。  

## 练习1.16
> 编写程序，从`cin`读取一组数，输出其和。

```cpp
#include <iostream>

int main()
{
    int sum = 0, val;
    while(std::cin >> val)
        sum += val;

    std::cout << sum << std::endl;
    return 0;
}
```
此处用`while`是觉得对于`std::cin`的判断条件它看起来更加直观。

## 引用
1. [C++ 编译&运行时遇到的坎](http://www.jianshu.com/p/cc2b98c27f6c)