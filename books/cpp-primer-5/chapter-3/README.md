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