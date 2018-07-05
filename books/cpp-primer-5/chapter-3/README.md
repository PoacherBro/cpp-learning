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

