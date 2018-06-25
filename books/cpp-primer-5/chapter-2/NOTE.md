# 2.1 基本内置类型

C++定义了一套包括 **算术类型（arithmetic type）** 和 **空类型（void）** 在内的基本数据类型。  

算术类型包括：  
- 字符 - `char`  
- 整型数 - `int`, `short`, `long`, `long long`  
- 布尔值 - `bool`  
- 浮点数 - `float`, `double`, `long double`  

空类型不对应具体的值，仅用于一些特殊的场合，例如常见的是，当函数不返回任何值事使用空类型作为返回类型。  

## 2.1.1 算术类型

算术类型分为两类：  
- 整型（integral type，包括字符和布尔类型在内）  
- 浮点型  

算术类型的尺寸（也就是该类型数据所占的比特数）在不同机器上有所差别。C++标准没有规定每种类型一定占用多少字节，而是规定了最小值，同时允许**编译器**赋予这些类型个更大的尺寸。   

- 布尔类型取值为：`true`和`false`  
- C++提供了几种字符类型：  
    - 基本的字符类型`char`，尺寸大小和机器字节一样  
    - 扩展字符集：`wchar_t` - 用于确保可以存放机器最大扩展字符集中的任意一个字符；`char16_t`和`char32_t`是Unicode字符集  
- 其他整型用于表示（可能）不同尺寸的整数。C++ 规定：**一个`int`至少和一个`short`一样大，一个`long`至少和一个`int`一样大，一个`long long`至少和一个`long`一样大**  
  `long long`是在C++11中新定义的。 

> **字符集**，可以参考《Windows程序设计》讲解的字符集概念，包括ASCII编码、Unicode字符集和UTF-8编码。另外一篇笔记有总结。  

> 机器存放数据是以比特（bit）序列存储的。可寻址的最小内存块成为“字节（byte）”，存储的基本单位成为“字（word）”。  
> 1 word = 4 byte (32bit) / 8 byte (64bit)  
> 我们常说的多少位系统，代表当前系统的字是多少比特。  

譬如在ArchLinux x64位机器，GCC-8.1.1版本中，各个类型的尺寸如下（单位：字节）： 
```
// sizeof()
bool  size: 1
char  size: 1
short size: 2
int   size: 4
long  size: 8

float       size: 4
double      size: 8
long long   size: 8
long double size: 16
```

浮点型可以表示：单精度、双精度和扩展精度。  
- C++标准制定了一个浮点数有效位数的最小值，然而大部分编译器都实现了更高的精度  
- 一般来说，`float`和`double`分别有7和16个有效位  
- `long double`常被用于特殊浮点需求的硬件，具体实现不同，精度不同  

> [单精度与双精度是什么意思，有什么区别？ - 涛了个帅的回答 - 知乎](https://www.zhihu.com/question/26022206/answer/81573345)  
> - 含义：  
>   表明单精度和双精度精确的范围不一样，单精度，也即`float`，一般在计算机中存储占用4字节，也32位，有效位数为7位；双精度（`double`）在计算机中存储占用8字节，64位，有效位数为16位。  
> - 原因：  
>   不管`float`还是`double`在计算机上的存储都遵循IEEE规范，使用二进制科学计数法，都包含三个部分：**符号位**，**指数位**和**尾数部分**。  
>   其中float的符号位，指数位，尾数部分分别为1,  8,  23。  
>   ![](https://pic4.zhimg.com/v2-749cc641eb4d5dafd085e8c23f8826aa_r.jpg)
>   双精度分别为1,  11, 52。  
>   ![](https://pic2.zhimg.com/v2-48240f0e1e0dd33ec89100cbe2d30707_r.jpg)
>   精度主要取决于尾数部分的位数，float为23位，除去全部为0的情况以外，最小为2的-23次方，约等于1.19乘以10的-7次方，所以float小数部分只能精确到后面6位，加上小数点前的一位，即有效数字为7位。  类似，double 尾数部分52位，最小为2的-52次方，约为2.22乘以10的-16次方，所以精确到小数点后15位，有效位数为16位。

关于浮点数在计算机如何存储，可以参考：  
- [浮点数在计算机中存储方式](http://www.cnblogs.com/jillzhang/archive/2007/06/24/793901.html)  
- [浮点数的二进制表示](http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html)  

**疑问：** 既然有了双精度，为什么还需要有单精度？编码时如何选择？  
回答：  
1. 为什么还需要单精度计算？  
    - 单精度占用存储空间比双精度小了一半；  
    - 对于轻量级计算，单精度和双精度速度一样快，但是对于浮点密集型计算，特别是打算上GPU，或者CPU一侧上SSE/AVX这些SIMD操作，单精度的计算速度是双精度的一倍。  
    - 参考：  
      a. [Why would you use float over double, or double over long double?](https://stackoverflow.com/questions/17603940/why-would-you-use-float-over-double-or-double-over-long-double)  
      b. [Should I use double or float?](https://stackoverflow.com/questions/1074474/should-i-use-double-or-float)  
      c. [能不能用double去取代float？](https://www.zhihu.com/question/66347905)

2. 编码时如何选择？  
    - 现如今大部分编码都可以使用`double`，安全，速度和`float`相差无几；  
    - 如1所述，如果确定当前系统计算类型，可以选择合适类型。


### 带符号类型和无符号类型

除了布尔类型和扩展的字符类型，**其他整型**可以划分带符号（signed）和无符号（unsigned）两种。  
- signed => 表示正数、负数或0  
- unsigned => 表示正数或0  

字符型有三种类型：  
- char  
- signed char  
- unsigned char  

**注意：**  
- 类型`char`和类型`signed char`不一样；  
- 虽然有三种类型，但是表现形式只有两种：带符号和无符号，其中 **类型`char`实际上会表现上述两种形式的一种，具体哪种由编译器决定。**  

无符号类型所有的比特都用来存储**值**，有符号有一位用来存储符号。  
C++标准没有规定带符号类型应该如何表示，但是约定了在表示范围内正值和负值的量应该平衡。  


## 2.1.2 类型转换  

当在程序的某处使用了一种算术类型的值而其实所需的是另一种类型的值时，编译器会执行类型转换。  

| 源                 | 目标       | 结果                                                         |
| ------------------ | ---------- | ------------------------------------------------------------ |
| bool               | 非bool     | 0 -> false，否则为true                                       |
| 非bool             | bool       | false -> 0， true -> 1                                       |
| 浮点数             | 整数       | 近似处理，只保留浮点数中小数点之前部分                       |
| 整数               | 浮点数     | 小数部分记为0。如果该整数所占空间超过浮点类型的容量，精度可能缺失 |
| 小于0整数          | 无符号类型 | 初始值对无符号类型表示数值总数取模后的余数，例如：-1对应`unsigned char`（取值范围是0-255，总数256）是 -1%256 = 255 |
| 超出带符号类型范围 | 带符号类型 | **未定义（undefined）**，程序可能继续运行，可能崩溃，也可能生成垃圾数据 |

**注意：** 避免下面这种写法：  
```cpp
// 错误！！变量u永远也不会小于0，循环条件一直成立
for (unsigned u = 10; u >= 0, --u)
    std::cout << u << std::endl;
```

尝试把`bool`转换成`char`类型，然后用`std::cout`打印出来，结果打印为空。才知道有些ASCII字符是不能打印的，可以用`std::isprint`来判断。参考[SO - cout not printing unsigned char](https://stackoverflow.com/questions/15585267/cout-not-printing-unsigned-char)

**切勿混用带符号类型和无符号类型进行计算！！** 带符号类型会转换成无符号类型。  

## 2.1.3 字面量常量  

一个形如42的值被称作字面量常量（literal）。  
每个字面量常量都对应一种数据类型，字面量常量的形式和值决定了它的数据类型。  

### 整型和浮点型字面值  

| 进制     | 表现           | 类型                                                         |
| -------- | -------------- | ------------------------------------------------------------ |
| 十进制   | 自然数表示     | `int`, `long`, `long long`尺寸最小的。带符号。               |
| 八进制   | 0开头整数      | `int`, `unsigned int`, `long`, `unsigned long`, `long long`, `unsigned long long`尺寸最小者。可能带符号也可能不带符号。 |
| 十六进制 | 0x或0X开头整数 | `int`, `unsigned int`, `long`, `unsigned long`, `long long`, `unsigned long long`尺寸最小者。可能带符号也可能不带符号。 |

`short`类型没有对应字面值。  

尽管整型字面值可以存储在带符号的数据类型中，但严格来说，十进制字面值不会是负数。-42的负十进制字面值，负号并不在字面值之内，它的作用仅仅是对字面值取负值而已。  

如果一个字面值连与之关联的最大的数据类型都放不下，将产生错误。  

浮点型字面值是一个`double`类型。  

### 字符和字符串字面值

| 类型   | 表现形式        |
| ------ | --------------- |
| 字符   | `'a'`           |
| 字符串 | `"Hello World"` |

字符串实际是由字符构成的数组。编译器在每个字符串的结尾处添加一个空字符（`'\0'`）。  

### 转义序列

有两类字符程序员不可直接使用：  
- 不可打印字符（`std::isprint`可以检测），如退格或其他控制字符，因为它们没有可视的图符；  
- C++语言中的特殊含义字符（单引号、双引号、问号、反斜线）。  

特殊字符可以转义（escape），C++利用反斜线转义字符（`'\'`)。  

### 指定字面值的类型  

**字符和字符串字面值：**  

| 前缀 | 含义 | 类型 |
| -- | -- | -- |
| `u` | Unicode 16字符 | `char16_t` |
| `U` | Unicode 32字符 | `char32_t` |
| `L` | 宽字符 | `wchar_t` |
| `u8` | UTF-8（仅用于字符串字面常量） | `char` |

**整型字面值：**  

| 后缀 | 最小匹配类型 |
| -- | -- |
| `u` or `U` | `unsigned` |
| `l` or `L` | `long` |
| `ll` or `LL` | `long long` |

**浮点型字面值：**  

| 后缀 | 类型 |
| -- | -- |
| `f` or `F` | `float` |
| `l` or `L` | `long double` |

`nullptr`是指针字面值。


# 2.2 变量

## 2.2.1 变量定义

```
<类型> <变量名> = <初始值>
<类型> <变量名>(<初始值>)

// 列表初始化 - C++11
<类型> <变量名> = {<初始值>}
<类型> <变量名>{<初始值>}
```
这里=是用来**初始化**。与**赋值**是两个不同概念。  

> 初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，以一个新值来替代。  

列表初始化如果存在丢失数据的风向，编译器将报错。  

### 默认初始化

默认值由一下两个条件决定：  
- 变量类型  
- 定义变量位置  

如果是基本类型：  
- 函数外，默认值是0；  
- 函数内，默认值是未定义（如果是`static`变量，会有初始值，为0）。  

类的初始化对象方式由自己决定。  

## 2.2.2 变量声明和定义的关系  

**声明（declaration）** 使得变量名为程序所知，一个文件如果想使用别处定义的变量名则必须包含对那个变量名的声明。  
即：声明规定了变量类型和名字。  

**定义（definition）** 负责创建与变量名关联的实体。  
即：定义在声明基础上申请了存储空间，也可能会为变量赋初始值。  

> **注意**：变量能且只能被定义一次，但可以被多次声明。  

## 2.2.3 标识符（identifier）

C++标识符只能由**字母、数字和下划线**组成，其中必须以字母或下划线开头。  
大小写敏感，长度无限制。  

### 变量命名规范

- 标识符要体现实际含义；  
- 变量名一般用小写字母，如果是常量，全大写；  
- 用户自定义的类名一般以大写字母开头；  
- 如果标识符由多个单词组成，单词间应有区分。驼峰法或者下划线。  

## 2.2.4 变量的作用域

每个名字都会指向一个特定的实体：变量、函数、类型等。同一个名字出现的位置不同，也可能指向的是不同的实体。  

- 全局作用域 - 函数体之外的名字  
- 块级作用域  

### 嵌套的作用域

作用域能彼此包含，分内层作用域和外层作用域。  
内层作用域能访问外层作用域的名字，并且允许重新定义外层作用域已有的名字。  

# 2.3 复合类型

复合类型（compound type）是指基于其他类型定义的类型。  

C++有几种复合类型：  
- 引用  
- 指针  
- 数组  
- 类  
- 结构体  
- 枚举  

## 2.3.1 引用

**引用（reference）** 为对象起了另外一个名字。定义引用时，程序把引用和它的初始值 **绑定（bind）** 在一起，而不是将初始值拷贝给引用。  

**引用即别名**，并非对象。  

所有引用类型都要和与之绑定对象的类型严格匹配。除了以下两个例外：  
1. 在初始化常量引用时允许用任意表达式作为初始值，只要该表达式的结果能够转换成引用的类型即可。  
2. 可以将基类的指针或引用绑定到派生类对象上。  

一旦定义了引用，就不能再绑定其他对象，之后每次使用这个引用都是访问它最初绑定的那个对象。  

可以把引用理解成一个特殊的“指针”，它由编译解决了“寻址”和“解引用”的过程，并且保证不会出现空指针的问题。所以在能使用引用的地方，尽量使用引用，而不用指针。  

## 2.3.2 指针

**指针（pointer）** 是“指向（point to）”另外一种类型的复合类型。也实现了对其他对象的间接访问。  
与引用的不同点：  
1. 指针本身是一个对象，允许对其赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象；  
2. 指针无需在定义时赋初始值。  

**指针值（即地址）** 应属于下列4中状态之一：  
1. 指向一个对象；  
2. 指向紧邻对象所占空间的下一个位置；  
3. 空指针，意味着指针没有指向任何对象（nullptr）；  
4. 无效指针，即上述情况之外的其他值。任何方式访问会引发错误。  

把`int`变量直接赋值给指针是错误的操作，即使`int`变量的值恰好等于0也不行。  

建议初始化所有指针。  

**重点**：  
1. 指针和引用都是为了避免对象拷贝，浪费资源；  
2. 对于函数返回值，如果仅仅为了避免对象拷贝，这没必要，因为编译器会做RVO（Return Value Optimization - 返回值优化），避免拷贝。参考：[SO - C++ 11 rvalues and move semantics confusion (return statement)](https://stackoverflow.com/questions/4986673/c11-rvalues-and-move-semantics-confusion-return-statement)。当然，RVO要求满足两个条件：  
    - return的值类型（包括常量）与函数签名的返回值类型相同  
    - return的是一个局部对象  

参考：[IBM - RVO V.S. std::move](https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move)

### void* 指针

`void*`指针是一种特殊的指针类型，可用于存放任意对象的地址。  

利用`void*`指针能做的事有限：  
1. 和其他指针比较  
2. 作为函数的输入或输出  
3. 赋值给另外一个`void*`指针  

## 2.3.3 理解复合类型的声明

变量的定义包括一个基本数据数据类型和一组声明符。  
但在一条定义语句中，基本数据类型只有一个，声明符却可以不同，如下所示：  
```cpp
// i 是一个 int 型的数，p 是一个 int 型指针， r 是一个 int 型引用
int i = 1024, *p = &i, &r = i;
```

> 基本数据类型是`int`, `short`, `long`等这些，类型修饰符是`signed`, `unsigned`, `long`等这些（`long`可以修饰`long`和`double`）。后者是声明符的一部分。  

### 定义多个变量

从指针声明看。

合法，但是容易产生误导：
```cpp
int* p; 
```
特别是对于下面写法，会产生误解：  
```cpp
int* p1, p2;  // p1 是指向 int 的指针， p2 是 int
```

倾向于下面写法：  
```cpp
int *p
```

# 2.4 const 限定符

`const`限定变量的值不能不改变。  

经测试，如果定义一个 `const` 类变量，依然不能改变对象内成员变量的值，会出编译错误。这点不像Java。  
```cpp
class People
{
private:
    int age;

public:
    void setAge(int v) { this->age = v; }
};

const People p;
p.setAge(32);  // VS2012 => error C2662: 'People::setAge' : cannot convert 'this' pointer from 'const People' to 'People &'
```

### 初始化和 const

与非`const`类型相比，`const`类型对象**只能执行不改变其内容的操作**。像上面说改变对象成员变量的内容，就不行。  

`const`变量必须初始化。  

**默认状态下，`const`对象仅在文件内有效**。如果想要跨文件访问，和非`const`变量相比，需要在定义时也要加上`extern`。  
```cpp
// file_1.cc 定义并且初始化了一个常量，该常量能被其他文件访问
extern const int bufSize = fcn();

// file_1.h 头文件
extern const int bufSize; // 与file_1.cc中定义的bufSize是同一个
```

## 2.4.1 const 的引用

把引用绑定到`const`对象上，称为**对常量的引用（reference to const）**。  
与普通引用不同，对常量的引用不能被用作修改它所绑定的对象。  

常量引用初始化时不必是一个左值，甚至可以不是同类型（只要能转换就行），在这种情况下，对`const T&`初始化，其实会做以下几步：  
1. 首先，如果需要将应用到`T`的隐式类型转换；  
2. 而后将结果存入一个类型`T`的临时变量（临时量）；  
3. 最后，将此临时量用作初始化的值。  

需要记住引用不是一个对象，不能让引用本身恒定不变，只是引用绑定的对象不能被常量变量名改变。  

### 初始化和对 const 的引用

初始化常量引用时允许用任意表达式作为值，只要该表达式的结果能够转换成引用的类型即可。  
```cpp
int i = 42;
const int &r1 = i;  // 允许将一个const int&绑定到一个普通int对象上
const int &r2 = 42; // 正确：r2是一个常量引用
const int &r3 = r1 * 2; // 正确：r3是一个常量引用
int &r4 = r1 * 2; // 错误：r4是一个普通的非常量引用
```

为什么上面`r4`会出现错误？这里要引入**左值**，**右值**，**左值引用**和**右值引用**的概念。

----

### 左值、右值、左值引用和右值引用

这些概念在C++11标准下非常重要，它是理解`move`/`forward`等新语义的基础。相关定义如下：  
- 左值 - 可以获取内存地址的、有名字的  
- 右值 - 非左值，譬如临时值。同时右值也分为纯右值、将亡值    
  例如：`int a = b + c`，`a`就是左值，有变量名，并且通过`&a`可以获取变量的地址；`b + c`就是右值，还有例如函数调用`func()`返回值、字面量 `2`，在其被赋值给某一变量之前都是右值。  

#### 右值、将亡值

在理解C++ 11的右值前，先看看C++ 98中右值的概念：  
> C++98中右值是纯右值，纯右值指的是临时变量值、不跟对象关联的字面量值。临时变量指的是非引用返回的函数返回值、表达式等。

例如函数`int func()`的返回值，表达式`a+b`；不跟对象关联的字面量值，例如`true`，`2`，`"C"`等。

C++ 11对C++ 98中的右值进行了扩充。在C++ 11中右值又分为**纯右值（prvalue，Pure Rvalue）**和**将亡值（xvalue，eXpiring Value）**。  
其中纯右值的概念等同于我们在C++ 98标准中右值的概念，指的是**临时变量和不跟对象关联的字面量值**；将亡值则是C++ 11新增的跟右值引用相关的表达式，这样表达式通常是将要被移动的对象（移为他用），比如返回右值引用`T&&`的函数返回值、`std::move`的返回值，或者转换为`T&&`的类型转换函数的返回值。

将亡值可以理解为通过“盗取”其他变量内存空间的方式获取到的值。在确保其他变量不再被使用、或即将被销毁时，通过“盗取”的方式可以避免内存空间的释放和分配，能够延长变量值的生命期。  

#### 左值引用、右值引用

左值引用就是对一个左值进行引用的类型。右值引用就是对一个右值进行引用的类型，事实上，由于右值通常不具有名字，我们也只能通过引用的方式找到它的存在。  

右值引用和左值引用都是属于引用类型。无论是声明一个左值引用还是右值引用，都必须立即进行初始化。而其原因可以理解为是引用类型本身自己并不拥有所绑定对象的内存，只是该对象的一个别名。左值引用是具名变量值的别名，而右值引用则是不具名（匿名）变量的别名。  

左值引用通常也不能绑定到右值，但常量左值引用是个“万能”的引用类型。它可以接受非常量左值、常量左值、右值对其进行初始化。不过常量左值所引用的右值在它的“余生”中只能是只读的。相对地，非常量左值只能接受非常量左值对其进行初始化。  
```cpp
int &a = 2;       // 左值引用绑定到右值，编译失败

int b = 2;        // 非常量左值
const int &c = b; // 常量左值引用绑定到非常量左值，编译通过
const int d = 2;  // 常量左值
const int &e = c; // 常量左值引用绑定到常量左值，编译通过
const int &b =2;  // 常量左值引用绑定到右值，编译通过
```

右值值引用通常不能绑定到任何的左值，要想绑定一个左值到右值引用，通常需要`std::move()`将左值强制转换为右值，例如：  
```cpp
int a;
int &&r1 = c;             // 编译失败
int &&r2 = std::move(a);  // 编译通过
```

下表列出了在C++11中各种引用类型可以引用的值的类型。值得注意的是，只要能够绑定右值的引用类型，都能够延长右值的生命期。   
![](https://img-blog.csdn.net/20160727131907698)  

----
至此，对于`int &r4 = r1 * 2; // 错误：r4是一个普通的非常量引用`就可以理解：`r1 * 2`是一个右值，而普通引用是不能指向右值的。  

关于引用、常量引用以及在函数参数、返回值的使用，需要更多的理解！

**参考**：  
1. The C++ Programming Language, 4th edition - 6.4.1节和7.7节  
2. [C++中的左值和右值](http://www.cnblogs.com/catch/p/3500678.html)  
3. [C++ 11左值、右值、右值引用详解](https://blog.csdn.net/hyman_yx/article/details/52044632)  
4. [The C++ `const` Declaration: Why & How](http://duramecho.com/ComputerInformation/WhyHowCppConst.html)  
5. [C++常量类型`const`详解](http://www.cnblogs.com/daocaoren/archive/2011/07/14/2106278.html)  

这里说一个问题，在实验以下代码的时候：  
```cpp
int& func()
{
    int i = 0;
    return i;
}

int main()
{
    int ri = func();
    ri++;
    std::cout << ri << std::endl;
}
```
按理说函数`func()`里局部变量`i`已经结束它的生命周期，在传出引用的时候应该是没有对应的内存地址了。但是，我不能理解为什么VS2012 Update5不会编译错误，而且还能运行正常。而在g++ 8.1里，却能给出编译警告，并且运行出错。在SO上问了[这个问题](https://stackoverflow.com/questions/50868524/why-return-local-variable-with-reference-type-works-in-vs2012)，根据几个人的回答可以知道，这属于[Undefined behavior](https://en.cppreference.com/w/cpp/language/ub)，对于不同编译器来说，可能处理的行为不一样。  
关于相关的问题，可以看在我之后有个人问的问题：[SO - Passing non-lvalue as const reference argument. Is the temp created in local scope or caller scope?](https://stackoverflow.com/questions/50869823/passing-non-lvalue-as-const-reference-argument-is-the-temp-created-in-local-sco)  

1. 关于未定义行为可以看[Just For Fun - C++中的未定义行为](https://selfboot.cn/2016/09/18/c++_undefined_behaviours/)。  
2. 更多关于引用相关的，可以去官网看看[cpp - Reference initialization](http://en.cppreference.com/w/cpp/language/reference_initialization)，关于定义和生命周期说的很详细。  


## 2.4.2 指针和 const

- 常量指针 - 指针这个对象是常量，**必须初始化**，并且初始化后不能改变这个指针的地址。但是依然可以改变指针指向那个对象的值。  
- 指向常量的指针 - 指针指向的对象是一个常量，此时可以改变指针的地址，但是不能改变指向的那个对象的值。  

```cpp
int errNumb = 0;
int *const curErr = &errNumb;
const double pi = 3.14159;
const double *const pip = &pi;
```
如上代码，如何明确声明的含义，最有效的方法是：**从右向左阅读**。  
离`curErr`最近的是`const`，代表`curErr`本身是一个常量对象，对象类型由声明符的其余部分确定。声明符下一个符号是 `*`，意思是`curErr`是一个常量指针。最后，该声明语句的基本数据类型部分确定了常量指针指向的是一个`int`对象。  

记住：变量的定义包括一个基本数据类型和一组声明符。**类型修饰符只是声明符的一部分**。  

## 2.4.3 顶层 const

- 顶层const - top-level const，表示任意对象是常量，对任何数据类型都有效，包括算数类型、类和指针。  
- 底层const - low-level const，与指针和引用等复合类型有关。表示指针所指对象是一个常量。  

指针比较特殊，既可以是顶层const，也可以是底层const。  

**对于对象拷贝（拷贝不影响被拷贝对象的值）**：  
- 顶层const不受影响  
- 底层const拷贝必须是具有相同底层const，或者两个对象的数据类型必须能够转换。一般来说，非常量可以转换成常量，反之则不行。  

## 2.4.4 constexpr和常量表达式  

**常量表达式（const expression）** 是指值不会改变并且在编译过程就能得到计算结果的表达式。  
一个对象（或表达式）是不是常量表达式由它的数据类型和初始值共同决定。  

属于常量表达式：
- 字面值  
- 用常量表达式初始化的`const`对象  

然而需要注意：  
- 如果数据类型是普通类型，就算字面值是常量，也不是常量表达式。例如：`int i = 27;`  
- 如果表达式结果需要运行时才获取，也不是常量表达式。例如：`const int sz = get_size();`

### constexpr 变量  

C++11 标准规定，允许将变量声明为**constexpr**类型以便由编译器来验证变量的值是否是一个常量表达式。  

- `const`用于运行时常量  
- `constexpr`用于编译器常量  

当然有一个特例：  
已由常量表达式初始化的、带const限定符（且不带volatile限定符）的、整数类型或枚举类型的变量，可以当做编译期常量来用。

### 字面值类型

类型简单，值显而易见、容易得到，称为“字面值类型”。包括：  
- 算术类型  
- 引用  
- 指针  

自定义类、IO库、string类型则不属于。也不能定义为`constexpr`。  

`constexpr`指针必须有初始值，并且是`nullptr`或者0，或者是存储于某个固体地址中的对象。  

函数体内的变量一般来说并非存放在固定地址中，`constexpr`不能指向这样的变量，函数体之外的变量地址固定不变，可以用`constexpr`初始化指针。  

### 指针和 constexpr

`constexpr`声明的指针只对指针有效，和指针所指对象无关。  

# 2.5 处理类型  

## 2.5.1 类型别名  

利用`typedef`定义一种类型的别名。例如：  
```cpp
typedef double wages; // wages是double的别名

```

`typedef`作为声明语句中基本数据类型的一部分。  

C++11 使用`using`作为**别名声明**来定义类型的别名：  
```cpp
using SI = Sales_item; // SI是Sales_item的同义词
```

### 指针、常量和类型别名  

```cpp
typedef char *pstring;  // pstring是 char * 的别名
const pstring cstr = 0; // cstr是指向char的常量指针
const pstring *ps;      // ps是一个指针，它的对象是指向char的常量指针
```

不能简单的把类型别名代入声明语句来解读，这是错误的。而是应该把别名当作一个类型来解读。

## 2.5.2 auto类型说明符

C++11引入 `auto`类型说明符，用它能让编译器去分析表达式所属的类型。  
`auto`定义的变量必须有初始值。（所以建议多用`auto`）

### 复合类型、常量和auto

编译器推断出来的`auto`类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。  
- 使用引用初始化`auto`变量时，其实是用引用对象的值，而不是引用  
- `auto`一般会忽略顶层const，同时底层const会保留下来  