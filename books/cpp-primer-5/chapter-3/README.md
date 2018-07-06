# 第三章 - 字符串、向量和数组

## 练习 3.21  

> 请使用迭代器重做 3.3.3 节的第一个练习

[ex3_21.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_21.cc)  



## 练习 3.22

> 修改之前那个输出 text 第一段的程序，首先把 text 的第一段全部改成大写形式，然后再输出它。

[ex3_22.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_22.cc)  



## 练习 3.23

> 编写一段程序，创建一个含有 10 个整数的 `vector` 对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出 `vector` 对象的内容，校验程序是否正确。

[ex3_23.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_23.cc)



## 练习 3.24 

> 请使用迭代器重做 3.3.3 节的最后一个练习。

[ex3_24.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_24.cc)

## 练习 3.25

> 3.3.3 节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写程序并实现完全相同的功能。

[ex3_25.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_25.cc)

## 练习 3.26

> 在 100 页的二分搜索程序中，为什么用的是 `mid = beg + (end - beg) / 2`，而非 `mid = (beg + end) / 2`？

因为在`vector`的迭代器中没有定义 `+` 操作符，`beg + end`是非法的。我们只能用减法。 

## 练习 3.27

> 假设 txt_size 是一个无参数的函数，它的返回值是`int`。请回答下列哪个定义是非法的？为什么？  
>
> ```cpp
> unsigned buf_size = 1024;
> (a) int ia[buf_size];          (b) int ia[4 * 7 - 14];
> (c) int ia[txt_size()];        (d) char st[11] = "fundamental";
> ```

- (a) 错误，变量`buf_size`不是常量表达式，如果声明`buf_size`为`const`或`constexpr`则可以  
- (b) 可以
- (c) 错误，除非是`constexpr int txt_size()`
- (d) 错误，没有位置存放空字符

## 练习 3.28

> 下列数组中元素的值是什么？
>
> ```cpp
> string sa[10];    // 都是空字符串""
> int ia[10];       // 都是 0
> int main() {
>     string sa2[10];  // string不是内置类型，会默认初始化，值都是空字符串
>     int    ia2[10];  // int是内置类型，在函数内没有默认初始值。所有值都是undefined
> }
> ```

参考 2.2.1 节变量的定义 -> 默认初始化。

## 练习 3.29

> 相比于`vector`来说，数组有哪些缺点，请列举一些。

- 大小是固定的，不能随意增加元素  

## 练习 3.30

> 指出下列代码中的索引错误。  
>
> ```cpp
> constexpr size_t array_size = 10;
> int ia[array_size];
> for (size_t ix = 1; ix <= array_size; ++ix)
>     ia[ix] = ix;
> ```

数组`ia`的大小是10，但是下标最大是 9，索引必须是小于10。这里`ix`不能等于`array_size`。

## 练习 3.31

> 编写一段程序，定义一个含有 10 个`int`的数组，令每个元素的值就是其下标值。

[ex3_31.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_31.cc)

## 练习 3.32

> 将上一题刚刚创建的数组拷贝给另外一个数组。利用`vector`重写程序，实现类是的功能。

[ex3_32.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_32.cc)

## 练习 3.33

> 对于 104 页的程序来说，如果不初始化 `scores`将发生什么？

`scores`是一个数组，如果不初始化它，那么这个数组就是 undefined，它的元素的值是未知。

## 练习 3.34

> 假定 p1 和 p2 指向同一个数组中的元素，则下面程序的功能是什么？什么情况下改程序是非法的？
>
> ```cpp
> p1 += p2 - p1;
> ```

程序相当于 `p1 = p2`。

如果 `p1` 和 `p2` 是合法的，则这段程序一直都是合法的。

## 练习 3.35

> 编写一段程序，利用指针将数组中的元素置为 0

[ex3_35.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_35.cc)

## 练习 3.36

> 编写一段程序，比较两个数组是否相等。再编写一段程序，比较两个 `vector` 对象是否相等。

[ex3_36.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_36.cc)

## 练习 3.37

> 下面的程序是何意义，程序的输出结果是什么？
>
> ```cpp
> const char ca[] = {'h', 'e', 'l', 'l', 'o'};
> const char *cp = ca;
> while (*cp) {
>     cout << *cp << endl;
>     ++cp;
> }
> ```

输出字符数组 `ca` 的所有字符，但是因为没有空字符结尾，在VS2017中会打印其他乱码字符，并且在遇到 `'\0'` 后才停止输出。不过在 g++ 8.1 版本中，会正确输出所有字符，没有多余字符，可能是 `ca` 所在内存下一个刚好有一个结束的空字符。

**注意！！！** 当用到字符串时，编译器会把值放到一个`.rodata`区域。上面代码用到C风格字符串但是没有在末尾加上空字符，所以当我们写这样的代码时：

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char s[] = "world";
const char *cp = ca;
while (*cp) {
    cout << *cp;
    ++cp;
}
```

会打印出 "helloworld"。因为在`.rodata`区域，字符列表会存储成这样

```
h e l l o w o r l d \0
```

`while (*cp)` 只是判断 `*cp` 是否为0。当 `*cp` 不为 0 时，会打印出 `cp` 所指对象的值。如果把代码改成这样：

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
```

在`.rodata`区域字符列表就是这样：

```
h e l l o \0 w o r l d \0
```

这样程序才会运行正确。**在用到C风格字符串的时候一定要小心！！！**

> 可以通过命令 ` hexdump -C a.out` 查看 `.rodata`。



## 练习 3.38

> 在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没什么意义？

两个指针可以相减，表示两者之间在内存位置的距离。指针与一个整型数相加或相减表示指针向上或向下移动多少距离。而位置与位置相加，语义上来讲都是毫无意义的。

参考：[Why can't I add pointers](https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)



## 练习 3.39

> 编写一段程序，比较两个 `string` 对象。再编写一段程序，比较两个C风格字符串的内容。

[ex3_39.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_39.cc)



## 练习 3.40

> 编写一段程序，定义两个字符数组并且用字符串字面值初始化它们；接着再定义一个字符数组存放前两个数组连接后的结果。使用 `strcpy` 和 `strcat` 把前两个数组的内容拷贝到第三个数组中。

[ex3_40.cc](https://github.com/PoacherBro/cpp-learning/blob/master/books/cpp-primer-5/chapter-3/ex3_40.cc)

**注意**：代码在g++ 8.1下可以运行，但是在VS2017有问题，因为g++允许不是常量表达式的变量声明数组维度，但是在VS2017不行。

并且在VS2017里不允许`strcpy`和`strcat`，必须用`strcpy_s`和`strcat_s`或者用`_CRT_SECURE_NO_WARNING`屏蔽错误，而这两个方法在g++是没有实现的。所以在VS2017需要修改代码如下：

```cpp
const char cstr1[] = "hello";
const char cstr2[] = "world";

size_t new_size = strlen(cstr1) + strlen(cstr2) + 1;
char *cstr3 = new char[new_size];

strcpy_s(cstr3, new_size, cstr1);
strcat_s(cstr3, new_size, cstr2);

cout << cstr3 << endl;
// 一定要delete掉new分配的内存，否则会出现内存泄露
delete[] cstr3;
```

