# 第二章 变量和基本类型  

## 练习2.1
> 类型`int`、`long`、`long long`和`short`的区别是什么？无符号类型和带符号类型的区别是什么？`float`和`double`的区别是什么？  

C++ 保证`short`和`int`**至少有**16位，`long`**至少有**32位，`long long`**至少有**64位。  

有符号类型可以表示正数、负数和0，而无符号类型只能表示不小于0的数（正数和0）。  

C和C++的标准没有指定`float`、`double`和`long double`的表示方法，这三种类型都可以实现IEEE的双精度表示。然而，对于大多数架构来说（GCC，MSVC；x86，x64，ARM），`float`必然是IEEE**单精度**浮点数（binary32），`double`是IEEE**双精度**浮点数（binary64）。  

**使用上：**  
- 当明确数值不可能为负时，选用无符号类型。  
- 使用`int`做整数运算，`short`常常显得太小而`long`一般和`int`有一样的尺寸。如果数值超过了`int`的表示范围，选用`long long`。  
- 在算术表达式中不要使用`char`或`bool`，只有在存放字符或布尔值时才使用它们。因为类型`char`在一些机器上是有符号的，而在另一些机器上又是无符号的，所以如果使用`char`进行运算特别容易出问题。如果需要使用一个不大的整数，那么明确指定它的类型是`signed char`或者`unsigned char`。  
- 执行浮点数运算选用`double`，这是因为`float`通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。事实上，对于某些机器来说，双精度运算甚至比单精度还快。`long double`提供的精度在一般情况下是没有必要的，况且它带来的运行时消耗也不容忽视。  

参考：  
- [SO - What is the difference between float and double?](https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double)  
- [阮一峰 - 浮点数的二进制表示](http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html)  
- [Binary Floating Point](https://ryanstutorials.net/binary-tutorial/binary-floating-point.php)  
- 本书2.1.1节，**建议：如何选择类型**  
