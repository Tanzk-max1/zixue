# C++基础

## 关键字与运算符

### 指针与引用

- [ ] 四个：定义、初始化、合法性、可变性

1. **定义**：指针存放的是某个对象的地址，引用表示的是一个对象的别名。
2. **初始化**：引用在定义的时候必须进行初始化，但是指针不需要。
3. **判断合法性**：因为引用在定义的时候必须进行初始化，所以在使用的时候不需要判断它是否为空。但是指针需要。
4. **是否可变**：指针可以被重新赋值来指向其他的对象，但是引用总是指向在初始化就被指定的对象，不可变，类似于指针常量。
4. 指针可以有多级，引用只有一级
4. sizeof指针得到的是本指针的大小，sizeof引用得到的是引用所指向变量的大小



### 运算符

#### 什么运算符可以重载/不可重载？

> 不能重载

`.`, `.*`, `::`, `?:`, `new` , `delete` , `sizeof` , `typeid` , `static_cast` , `dynamic_cast` , `const_cast` ,  `reinterpret_cast`

> 可以重载

除了不能重载的都能重载.0..

`operator new` , `operator delete` , `operator new[]` , `operator delete[]` 





### 关键字



#### const的作用

被它修饰的值不能改变，是只读变量，必须在定义时就赋初值

判断方法：看`const`修饰谁

##### 常量指针（底层const->指向的对象是const）

pointer to const

```c++
const int* a;
int const* a;

const int* a 意味着 a 是一个指向 const int 类型的指针，即指针 a 所指向的地址中的内容不能被修改。
```

```c++
// 底层 const 指针
int x = 5;
const int* constPtr = &x;  // constPtr 是一个指向常量整数的底层 const 指针
// *constPtr = 10;  // 错误，不能通过 constPtr 修改所指向的值
x = 10;  // 可以通过其他方式修改所指向的值

const double pi = 3.14159;
const double* ptr = &pi;  // ptr 是一个指向常量 double 的指针
// *ptr = 3.14;  // 错误，不能通过 ptr 修改所指向的值

// 底层 const 函数参数
void printValue(const int* ptr) {
    // *ptr = 10;  // 错误，不能通过指针修改底层 const 参数所指向的值
    std::cout << *ptr << std::endl;
}

int main() {
    int num = 5;
    printValue(&num);  // 传递指向常量整数的指针给 printValue 函数
    return 0;
}
```

`const` 修饰 `*a`，代表指针指向的对象是`const`，不能通过指针修改对象，强调指针对其所指对象的不可改变性。

##### 指针常量（顶层const->指针本身是const）

const pointer

```c++
int* const a;

int* const a 中的 const 是顶层 const，因为它修饰的是指针本身。这意味着 a 是一个常量指针，即指针所存储的值（指向的地址）不能改变，但可以通过 a 修改所指向的对象的值。
```

```c++
// 顶层 const 指针
const int* ptr = nullptr;  // ptr 是一个指向常量整数的指针
const double* constPtr = nullptr;  // constPtr 是一个指向常量 double 的常量指针

int x = 5;
const int* ptr2 = &x;  // ptr2 指向一个常量整数
// *ptr2 = 10;  // 错误，不能通过 ptr2 修改所指向的值
//x = 10;  // 可以通过其他方式修改所指向的值

// 顶层 const 函数参数
void printValue(const int value) {
    // value = 10;  // 错误，不能在函数中修改顶层 const 参数的值
    std::cout << value << std::endl;
}

int main() {
    int num = 5;
    printValue(num);  // 传递常量值给 printValue 函数
    return 0;
}
```

`const` 修饰 `a`，代表指针本身就是常量，不可改变指向，强调指针本身的不可改变性，只能在定义时初始化。

##### 指向常量的指针常量

```c++
const int* const a;
```

指针指向不可改变和也不可通过指针来改变所指的对象。

##### 顶层与底层的理解

```c++
底层 const 和顶层 const 都可以用于限制对象的可变性，但它们的作用范围不同。

底层 const 用于限制指针所指向的对象的可变性。当你使用底层 const 修饰指针时，该指针可以指向一个常量对象，即你不能通过该指针修改所指向对象的值。但是，你仍然可以通过其他方式修改对象本身的值。

顶层 const 用于限制对象本身的可变性。当你使用顶层 const 修饰对象时，该对象本身被视为常量，你不能通过任何方式修改其值。
    
    int x = 5;
const int* ptr1 = &x;  // 底层 const 指针，指向常量整数
int* const ptr2 = &x;  // 顶层 const 指针，指向整数的常量指针

*ptr1 = 7;  // 错误，不能通过 ptr1 修改所指向的值
ptr1 = nullptr;  // 正确，可以修改指针本身

*ptr2 = 7;  // 可以通过 ptr2 修改所指向的值（x 的值被修改为 7）
// ptr2 = nullptr;  // 错误，不能重新指向其他对象


在上述示例中，ptr1 是一个底层 const 指针，指向一个常量整数。因此，你不能通过 ptr1 修改所指向的对象的值，但可以修改指针本身，即改变指针指向的对象。

ptr2 是一个顶层 const 指针，指向一个整数的常量指针。这意味着你不能通过 ptr2 修改所指向的对象的值，但可以通过其他方式修改对象的值，例如通过解引用指针进行修改。但你不能将 ptr2 指向其他对象，因为它是一个顶层 const 指针。

因此，底层 const 和顶层 const 的区别在于它们所限制的内容不同：底层 const 限制了对象本身的可变性，而顶层 const 限制了指针或对象本身的可变性。
```



底层 `const` 和顶层 `const` 在实际开发中都有各自的用途和应用场景。下面是一个示例和开发场景，以帮助你更好地理解它们的作用。

示例代码如下：

cpp

复制

```c++
#include <iostream>

// 底层 const 示例：指针指向常量对象
void printValue(const int* ptr) {
    std::cout << *ptr << std::endl;
    // *ptr = 10;  // 错误，不能通过 ptr 修改所指向的值
}

// 顶层 const 示例：函数返回常量对象
const int* getValue() {
    static int value = 5;
    return &value;
    // int* ptr = &value;
    // return ptr;  // 错误，不能返回指向非常量的指针
}

int main() {
    // 底层 const 示例
    int x = 10;
    const int* ptr = &x;  // 底层 const 指针，指向常量整数
    printValue(ptr);

    // 顶层 const 示例
    const int* const constPtr = getValue();  // 顶层 const 指针，指向常量整数
    std::cout << *constPtr << std::endl;

    return 0;
}
```

在上述示例中，我们展示了底层 `const` 和顶层 `const` 的两个主要用途：

1. 底层 `const` 的用途：
   - `printValue` 函数的参数 `ptr` 是一个指向常量整数的底层 `const` 指针。这意味着函数内部不能通过 `ptr` 修改所指向的值。这在需要传递常量对象给函数时非常有用，可以保护传递的对象不被意外修改。
2. 顶层 `const` 的用途：
   - `getValue` 函数返回一个指向常量整数的顶层 `const` 指针。这意味着调用者不能通过返回的指针修改所指向的值。这在需要返回常量对象的情况下非常有用，可以确保调用者不能修改函数返回的对象。

开发场景示例：

假设你正在开发一个图像处理库，并且有一个函数用于对图像进行裁剪。在这个场景中，底层 `const` 和顶层 `const` 都可以发挥作用。

1. 底层 `const` 的应用：

   - 当你传递一个指向图像数据的指针给裁剪函数时，你可以使用底层 `const` 来指示函数不会修改原始图像数据。这可以提高代码的可读性并确保图像数据的完整性。

   cpp

   复制

   ```c++
   void cropImage(const unsigned char* imageData, int width, int height);
   ```

2. 顶层 `const` 的应用：

   - 当你定义一个函数用于返回图像的元数据，比如图像的宽度和高度时，你可以使用顶层 `const` 来指示函数返回的指针指向的对象是常量。这可以防止调用者修改元数据，保持数据的一致性。

   cpp

   复制

   ```c++
   const int* getImageSize(const Image& image);
   ```

在这个开发场景中，底层 `const` 和顶层 `const` 都有助于提高代码的可读性和安全性，同时确保图像数据和元数据的一致性和不变性。



#### cin输入流的规则

输入运算符 `>>` 会跳过输入中的空白字符，直到遇到非空白字符为止。当您输入一个空格时，`cin >> word` 操作会被解释为输入结束，因为空格被视为分隔符，用于切分输入。此时，`cin >> word` 无法读取空格字符，它会将空格字符留在输入流中，并将输入流的位置保留在空格字符之后。因此，循环再次执行 `cin >> word` 时，它会读取下一个非空白字符，而不是继续读取空格字符。



#### define和typedef的区别

`define`

1. 简单的字符串替换，没有类型检查
2. 在编译的预处理阶段起作用
3. 可以用来防止头文件被重复引用 `#ifdefine` 
4. 不分配内存，给出的是立即数，有多少次使用就进行多少次替换

`typedef`

1. 有对应的数据类型，进行类型检查
2. 子啊编译和运行时七座
3. 在静态存储区中分配空间，程序运行过程中内存只有一个copy

`using`

 1.`using` 是 C++ 的关键字，用于引入命名空间成员或定义类型别名。

 2.在 C++11 之后，`using` 还可以用于定义类型别名，与 `typedef` 相似。

 3.`using` 可以用来创建更简洁、易读的类型别名，并且支持模板别名。

 4.示例：`using myInt = int;` 定义了 `myInt` 作为 `int` 的别名，与 `typedef` 类似。

#### define 和 inline 的区别

`define`

- 定义的是编译时预处理阶段的宏，只是简单的字符串替代，不安全

`inline`

- 将内联函数编译完成生成的函数体直接插入调用的地方，减少了压栈、跳转、返回的函数调用开销。
- 对编译器的请求，编译器可以拒绝执行
- inline会进行类型检查

`inline`的限制：

- 不能有循环语句
- 不能有过多的条件判断语句
- 函数体不能过大
- 声明必须在调用之前



#### override 和 overload 的区别

**1、override是重写（覆盖）一个函数**

运行时多态，用于子类继承父类时，子类重写父类的函数

规则：

- override函数的参数列表、返回值、抛出异常与被重写的函数一致
- 被重写的函数不能是私有的
- 静态函数不能被重写为非静态函数
- 重写函数的访问权限必须大于被重写函数的访问权限

**2、overload是重载，这些函数的函数名相同而参数形式不同**

编译时多态，根据不同的参数类型，在编译时将不同的函数体插入指定的地方



#### new和malloc

- [ ] 库函数，异常，重载，构造函数，显式指定

1. new在分配失败时会抛出bad_alloc异常，不返回空指针；而malloc内存分配失败没有异常，直接返回空指针
2. new申请内存不需要显式指定内存块的大小而malloc需要
3. `operator new/delete`可以重载，而malloc/free不允许重载
4. new/delete会调用对象的构造函数和析构函数。malloc不会
5. malloc和free是标准库函数，new/delete是c++运算符
6. **operator new和new operator和placement new的区别：**
   - new operator是关键字；operator new是运算符，可以重载，里面实际上调用了 malloc ；placement new就是在指定的内存地址上构造对象（会调用对象的构造函数）
7. new从自由存储区（c++概念）上分配内存，而malloc从堆（OS的概念）上分配内存



#### constexpr和const

`const`表示“只读”的语义，`constexpr`表示“常量的语义”

`constexpr`只能定义编译期常量；`const`可以定义编译期常量，也可以定义运行期常量.

```c++
const int a = 4096;	// 编译期常量
const int size = vector<int>(26).size()	// 运行期常量
```

**constexpr的好处**

1. 为一些不能修改数据提供保障，避免被以外修改的风险
2. 部分场景，编译器可以在编译期对constexpr的代码进行优化，提高效率
3. 相比宏来说，没有额外的开销，更安全可靠



#### const和static

| 关键字 | 修饰常量（非类中）                                           | 修饰成员变量                                                 | 修饰成员函数                                                 |
| ------ | ------------------------------------------------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ |
| const  | 1、超出作用域后空间会被释放<br />2、在定义时必须初始化，之后无法更改<br />3、`const`形参可以接受const和非const类型的实参 | 不能赋值、不能在类外定义；只能通过构造函数的参数列表初始化进行初始化（原因：因为不同对象的const成员变量可以具有不同值，所以不能在声明时初始化） | 防止成员函数修改对象的内容（不能修改成员变量，但能够访问）<br />const对象不可以调用非const的函数 |
| static | 在函数执行后不会释放其存储空间                               | 只能用在类内声明，在外部初始化，且不加static                 | 1、作为类作用域的全局函数（不能访问非静态数据成员和调用非静态成员函数）<br />2、没有this指针<br />3、不能声明为virtual |

**const和static不能同时修饰成员函数（原因：静态成员函数不含有this指针，即不能实例化，而const成员函数必须具体到某一实例）**





#### static 和 const

##### static

- 不考虑类的情况
  1. 隐藏。所有不加static的全局变量和函数具有全局可见性，可以在其他文件中使用，加了之后只能在该文件所在的编译模块中使用
  2. 默认初始化为0，包括未初始化的全局静态变量与局部静态变量，都存在全局未初始化区
  3. 静态变量在函数内定义，始终存在，且只进行一次初始化，具有记忆性，其作用范围与局部变量相同，函数退出后仍然存在，但不能使用
- 考虑类的情况
  1. static成员变量：只与类关联，不与类的对象关联。定义时要分配空间，不能在类声明中初始化，必须在类定义体外部初始化，初始化时不需要标示为static；可以被非static成员函数任意访问。
  2. static成员函数：不具有this指针，无法访问类对象的非static成员变量和非static成员函数；**不能被声明为const、虚函数和volatile**；可以被非static成员函数任意访问



##### const

- 不考虑类的情况
  1. const常量在定义时必须初始化，之后无法更改
  2. const形参可以接收const和非const类型的实参，例如// i 可以是 int 型或者 const int 型void fun(const int& i){ //...}
- 考虑类的情况
  1. const成员变量：不能在类定义外部初始化，只能通过构造函数初始化列表进行初始化，并且必须有构造函数；**不同类对其const数据成员的值可以不同，所以不能在类中声明时初始化**
  2. const成员函数：const对象不可以调用非const成员函数；非const对象都可以调用；不可以改变非mutable（用该关键字声明的变量可以在const成员函数中被修改）数据的值

补充一点const相关：const修饰变量是也与static有一样的隐藏作用。只能在该文件中使用，其他文件不可以引用声明使用。 因此在头文件中声明const变量是没问题的，因为即使被多个文件包含，链接性都是内部的，不会出现符号冲突。





#### strlen 和 sizeof

<img src="https://img-blog.csdnimg.cn/20200804193045440.png" alt="C++数据类型的大小" style="zoom:50%;" />

- sizeof是运算符，并不是函数，结果在编译时得到而非运行中获得；strlen是字符处理的库函数。
- sizeof参数可以是任何数据的类型或者数据（sizeof参数不退化）；strlen的参数只能是字符指针且结尾是'\0'的字符串。
- **因为sizeof值在编译时确定，所以不能用来得到动态分配（运行时分配）存储空间的大小。**







#### std::atomic

**问题：`a++`和`int a = b`在c++中是否线程安全？**

1、`a++`的汇编

先将a对应的内存值搬运到某个寄存器（如eax）中，然后将该寄存器中的值自增1，最后将寄存器中的值搬运回a代表的内存中

```assembly
mov eax, dword ptr [a] #(1)
inc eax #(2)
mov dword ptr [a], eax #(3)
```

2、`int a = b`的汇编

数据不能直接从内存某处搬运到内存另外一处，必须通过寄存器来中专

```assembly
mov eax, dword ptr [b]
mov dword ptr [a], eax
```

解决办法：`std::atomic<int> value`对整型变量原子操作的相关库



#### volatile

1. volatile定义变量的值是易变的，每次用到这个变量的值的时候都要去重新读取这个变量的值，而不是读寄存器内的备份。
2. 多线程中被几个任务共享的变量需要定义为volatile类型。



#### static 关键字的作用

1. **限制数据的作用域（隐藏）**：所有没有加 static 的全局变量和函数都具有全局可见性，其它源文件中也可以访问。被 static 修饰的全局变量和函数只能在当前源文件中访问，其它源文件访问不了，利用这个特性可以在不同的文件中定义同名变量和同名函数，而不必担心命名冲突。
2. **延长数据的生命周期：**普通的局部变量出了作用域就会释放，而静态变量存储在静态区，直到程序运行结束才会释放。 
3. 静态成员被该类所有对象共享 static 关键字可以修饰类中的成员变量和成员方法，被称为静态成员变量和静态成员方法，静态成员拥有一块单独的存储区，不管创建多少个该类的对象，**所有对象都共享这一块内存。静态成员本质上属于类，可以通过类名直接访问。**
4.  静态变量默认初始化值为0，如果**没有显示初始化静态变量或者初始化为0的静态变量会存储在 BSS 段，而初显示初始化的静态变量存储在 DATA 段。**
5. **静态成员函数中不能访问普通的成员变量，只能访问静态成员变量，并且在静态成员函数中没有 this 指针。**



#### 类相关

##### explicit

表明该构造函数是显示的，而非隐式的，阻止类构造函数的隐式自动转换。

explicit 关键字只需用于类内的单参数构造函数前面。由于无参数的构造函数和多参数的构造函数总是显示调用，这种情况在构造函数前加explicit无意义。



##### override和final





### 类型转换

#### C++中类型转换有几种方法？

**这个需要由编译器支持。**

1. **`（类型说明符）表达式->(int)a`**

- 从C语言继承的方法，把表达式的值强制转换为类型说明符表示的类型

2. **`reinterpret_cast<类型说明符>(表达式）->reinterpret_cast<int>(a)`**
* 转换一个指针为其它类型的指针。它也允许从一个指针转换为整数类型。反之亦然。这个操作符能够在非相关的类型之间转换。操作结果只是简单的从一个指针到别的指针的值的二进制拷贝。在类型之间指向的内容不做任何类型的检查和转换。如传统的类型转换一样对待所有指针的类型转换
* 特意用于底层的强制转型，导致实现依赖（implementation-dependent）（就是说，不可移植）的结果，例如，将一个指针转型为一个整数。这样的强制转型在底层代码以外应该极为罕见。

3. **`const_cast<类型说明符>(表达式）->const_cast<int>(a)`**
* 这个转换类型操纵传递对象的 const 属性，或者是设置或者是移除
* 一般用于强制消除对象的常量性。它是唯一能做到这一点的 C++ 风格的强制转型

4. **`dynamic_cast<类型说明符>(表达式）->dynamic_cast<int>(a)`**
* 只用于对象的指针和引用。用于将指向基类的指针或引用转换成指向其派生类或其兄弟类的指针或引用。当转换失败时将返回空指针（指针），或者抛出异常（引用）
* 不能用于没有继承关系的类型转换，也不能用于转换 const

5. **`static_cast<类型说明符>(表达式）->static_cast<int>(a)`**
* 允许执行任意的隐式转换和相反转换动作，特别的点：允许父类指针转化为子类指针（下行转换）
* 可以被用于强制隐型转换（例如，non-const 对象转型为 const 对象，int 转型为 double，等等），它还可以用于很多这样的转换的反向转换（例如，void* 指针转型为有类型指针，基类指针转型为派生类指针），但是它不能将一个 const 对象转型为 non-const 对象（只有 const_cast 能做到），它最接近于C-style的转换。



#### 四种类型转换是在什么时候进行的？

1. **编译期进起作用**
   - `static_cast`
   - `reinterprete_cast`
   - `const_cast`
2. **运行期起作用**
   - `dynamic_cast`





> 为什么不使用 C 风格的类型转换

1. C 风格的类型转换无法实现更精确的类型转换，举两个例子，将一个指向 const 对象的指针转化为一个指向非 const 对象的指针 `const_cast` ，或者将指向基类的指针转换为指向子类的指针`dynamic_cast`。
2. C 风格的类型转换在程序中难以识别。





### malloc 和 new 的区别

- [ ] 属性，参数，返回值，失败处理，构造，5个！

1. **属性**

`new/delete` 是C++关键字，需要编译器支持。`malloc/free` 是库函数，需要头文件支持。

2. **参数**

使用 `new` 操作符申请内存分配时无须指定内存块的大小，编译器会根据类型信息自行计算。而 `malloc` 则需要显式地指出所需内存的尺寸。

3. **返回类型**

`new` 操作符内存分配成功时，返回的是对象类型的指针，类型严格与对象匹配，无须进行类型转换，故`new` 是符合类型安全性的操作符。而 `malloc` 内存分配成功则是返回 `void *` (可强制转换为任何类型)，需要通过强制类型转换将 `void*` 指针转换成我们需要的类型。

4. **分配失败**

`new` 内存分配失败时，会抛出 `bac_alloc` 异常。`malloc` 分配内存失败时返回 `NULL`。

5. **自定义类型**

`new` 会先调用 `operator new` 函数，申请足够的内存（通常底层使用 `malloc` 实现）。然后调用类型的构造函数，初始化成员变量，最后返回自定义类型指针。`delete` 先调用析构函数，然后调用 `operator delete` 函数释放内存（通常底层使用free实现）。
`malloc/free` 是库函数，只能动态的申请和释放内存，无法强制要求其做自定义类型对象构造和析构工作。

6. **重载**

`new/delete` 操作符允许重载，特别的，布局 `new` 的就不需要为对象分配内存，而是指定了一个地址作为内存起始区域，`new` 在这段内存上为对象调用构造函数完成初始化工作，并返回此地址。而malloc不允许重载。

7. **内存区域**

`new` 操作符从自由存储区（`free store`）上为对象动态分配内存空间，而 `malloc` 函数从堆上动态分配内存。自由存储区是C++基于 `new` 操作符的一个抽象概念，凡是通过 `new` 操作符进行内存申请，该内存即为自由存储区。而堆是操作系统中的术语，是操作系统所维护的一块特殊内存，用于程序的内存动态分配，C语言使用 `malloc` 从堆上分配内存，使用 `free` 释放已分配的对应内存。自由存储区不等于堆，如上所述，布局**new就可以不位于堆中**。

8. **others**

`std::operator new()` 和 `std::operator delete()` 是带异常的 `malloc()` 和 `free()`



### C++三大特性

继承、封装和多态

**访问权限**

<img src="https://s1.328888.xyz/2022/05/04/h7ygk.png" style="zoom:67%;" />

#### 继承

让某种类型对象获得另一个类型对象的属性和方法，使得派生类可以使用父类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。

**三种方式：**

1. 实现继承：使用基类的属性和方法而无需额外编码的能力
2. 接口继承：仅使用属性和方法的名称，但子类必须提供实现的能力
3. 可视继承：指子窗体（类）使用基窗体（类）的外观和实现代码的能力

#### 封装

**定义：**

​	数据和代码捆绑在一起，避免外界干扰和不确定性访问；

**功能：**

​	把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏，例如：将公共的数据或方法使用public修饰，而不希望被访问的数据或方法采用private修饰。



#### 多态

同一事物表现出不同事物的能力，即向不同对象发送同一消息，不同的对象在接收时会产生不同的行为（重载实现编译时多态，虚函数实现运行时多态），即**允许将子类类型的指针赋值给父类类型的指针。**

**实现多态的两种方式：**

1. 覆盖（override）：是指子类重新定义父类的虚函数的做法

2. 重载（overload）：是指允许存在多个同名函数，而这些函数的参数表不同（或许参数个数不同，或许参数类型不同，或许两者都不同）

   

**虚函数**

当基类希望派生类定义适合自已的版本，就将这些函数声明成虚函数（virtual）

虚函数依赖虚函数表工作，表来保存虚函数地址，当我们用基类指针指向派生类时，虚表指针指向派生类的虚函数表

**1、虚函数的动态绑定的**

​	也就是说，使用虚函数的指针和引用能够正确找到实际类的对应函数，而不是执行定义类的函数，这是虚函数的基本功能。

**2、调用规则**

- 调用函数的对象必须是指针或者引用
- 被调用的函数必须是虚函数（virtual），且完成了虚函数的重写（派生类中有一个跟基类的完全相同虚函数）

**3、动态绑定，绑定的是动态类型**

​	所对应的函数或属性依赖于对象的动态类型，发生在运行期。

**4、构造函数不能是虚函数**

​	而且，在构造函数中调用虚函数，实际执行的是父类的对应函数，因为自己还没有构造好，多态是被banned的。

**5、虚函数的工作方式**

![虚函数工作方式](https://s1.328888.xyz/2022/05/04/h7h9X.png)

​	依赖虚函数表工作的，表来保存虚函数地址，当我们用基类指针指向派生类时，虚表指针vptr指向派生类的虚函数表。这个机制可以保证派生类中的虚函数被调用到。

**6、析构函数可以是虚函数，而且，在一个复杂类结构中，这往往是必须的。**

​	在实现多态时，当用基类操作派生类，在析构时防止只析构基类而不析构派生类的状况发生。

```c++
int main(){ 
  //有多态
  ClxBase *p =  new ClxDerived;
  p->DoSomething();
  // 如果派生类的析构函数不是虚函数，此处只会删除派生类中的基类部分
  delete p;
  return 0;
} 
```

**7、将一个函数定义为纯虚函数**

​	实际上是将这个类定义为抽象类，不能实例化对象；纯虚函数通常没有定义体，但也完全可以拥有。

**8、inline,static,constructor三种函数都不能带有virtual关键字。**

​	（1）inline是在编译时展开，必须要有实体。

​	（2）static属于class自己的类相关，必须有实体；

​		static成员没有this指针。而虚函数依靠vptr和vtable来处理。vptr是一个指针，在类的构造函数中创建生成，并且只能用this指针来访问它，因为它是类的一个成员，并且vptr指向保存虚函数地址的vtable。

**9、派生类的override虚函数定义必须和父类完全一致。**

​	除了一个特例，如果父类中返回值是一个指针或引用，子类override时可以返回这个指针（或引用）的派生。



**为什么需要虚继承？**

**1、解决多继承时的命名冲突和冗余数据问题（尤其是菱形继承）**

虚继承在派生类中只保留一份间接基类的成员。其中多继承（Multiple Inheritance）是指从多个直接基类中产生派生类的能力，多继承的派生类继承了所有父类的成员。

<img src="https://s1.328888.xyz/2022/05/05/hKSL4.png" style="zoom: 50%;" />

**2、虚继承的目的是让某个类做出声明，承诺愿意共享它的基类**

其中，这个被共享的基类就称为虚基类（Virtual Base Class）。在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。

标准库中的iostream就是一个例子：

<img src="https://s1.328888.xyz/2022/05/05/hKozB.png" style="zoom:80%;" />







##### 多态注意事项

1. 通过一个基类指针来删除一个含有派生类对象的数组，结果将是不确定的。

   ```cpp
   // 删除一个数组, 但是首先记录一个删除信息
   void deleteArray(ostream& logStream, BST array[]) {
       LOG();
       delete [] array;
   }
   // delete [] array 实际上下面的代码
   // 但是编译器是按照 BST 的大小来移动内存的，当传入 BST 的派生类是，大小改变，删除会出现不确定的情况
   for (int i = array.size(); i >= 0; --i) {
       array[i].BST::~BST();
   }
   ```

   

2. ss





#### 空类

**1、为何空类的大小不是0**

为保证两个不同对象的地址不同，空类也会实例化，所以编译器会给空类隐含的添加一个字节（在不涉及虚函数时），此时`sizeof`为1，这样空类实例化后就有独一无二的地址了。

当基类中含有虚函数，或者派生类使用虚继承时，会含有虚函数表的地址/指向虚基类的指针，此时`sizeof`为4，当然具体情况视继承的数量而定。

![](https://s1.328888.xyz/2022/05/05/hKPu2.png)

### 智能指针

**智能指针有哪些了解？**

智能指针是为了解决动态分配内存导致内存泄露和多次释放同一内存所提出的，C11标准中放在`<memory>`头文件。包括：共享指针，独占指针，弱指针



#### shared_ptr

**1、shared_ptr的实现机制是在拷贝构造时使用同一份引用计数**

**实现要点：**

- 一个模板指针 `T* ptr`，指向实际的对象

- 一个引用计数

  必须 new 出来的，不然会多个 shared_ptr 里面会有不同的引用次数而导致多次 delete

- 重载 `operator*` 和 `operator->`

  使得能像指针一样使用shared_ptr

- 重载 copy constructor

  使其引用次数加一（拷贝构造函数）

- 重载 `operator=`（赋值运算符）

  如果原来的shared_ptr已经有对象，则让其引用次数减一并判断引用是否为零（是否调用delete），然后将新的对象引用次数加一

- 重载析构函数

  使引用次数减一并判断引用是否为零；（是否调用delete）

```c++
template <typename T>
class Shared_Ptr{
public:
	Shared_Ptr(T* ptr = nullptr)
		:_pPtr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~Shared_Ptr()
	{
		Release();
	}
	Shared_Ptr(const Shared_Ptr<T>& sp)
		:_pPtr(sp._pPtr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp)
	{
		//if (this != &sp)
		if (_pPtr != sp._pPtr)
		{
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_pPtr = sp._pPtr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}
	T& operator*(){
		return *_pPtr;
	}
	T* operator->(){
		return _pPtr;
	}
	int UseCount() { return *_pRefCount; }
	T* Get() { return _pPtr; }
	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _pRefCount;
			delete _pPtr;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int *_pRefCount;
	T* _pPtr;
	mutex* _pMutex;
};
```

**2、线程安全问题**

- 同一个`shared_ptr`被多个线程"读"是安全的：

- 同一个`shared_ptr`被多个线程"写"是不安全的：

  因为对一个`shared_ptr`写操作分为两步：更改实际指针指向，然后再修改引用计数，如果第一步完成后就切换线程了，因为可能会因为引用计数没增加而导致实际指针被释放。

  [一个参考示例](https://blog.csdn.net/solstice/article/details/8547547)

- 共享引用计数的不同的shared_ptr被多个线程"写“是安全的。

- **结论：多个线程访问同一个shared_ptr时，应该要进行加锁操作**



#### unique_ptr

**1、unique_ptr"唯一"拥有其所指对象**

同一时刻只能有一个unique_ptr指向给定对象，离开作用域时，若其指向对象，则将其所指对象销毁（默认delete）

**2、定义unique_ptr时**

需要将其绑定到一个new返回的指针上。

**3、unique_ptr不支持普通的拷贝和赋值（因为拥有指向的对象）**

但是可以拷贝和赋值一个将要被销毁的unique_ptr；可以通过release或者reset将指针所有权从一个（非const）unique_ptr转移到另一个unique。

```c++
template <typename T> 
struct PointerDeleter{
    void operator()(const T *ptr) {
        if(ptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
};

template <typename T, typename Deleter = PointerDeleter<T> >
class UniquePtr{
public:
    UniquePtr();
    UniquePtr(T *_ptr);
    UniquePtr(UniquePtr&& p); // 移动构造函数
    ~UniquePtr();

// non-copyable
private:
    UniquePtr(const UniquePtr& p) = delete;
    UniquePtr& operator= (const UniquePtr& p) = delete;

public:
    T& operator* ();
    T* operator-> ();
    UniquePtr &operator= (UniquePtr&& p); // 移动赋值，右值
    operator bool() const;

    // 返回原始指针
    T* get() const;
    // 返回指针，释放所有权
    T* release();
    // 替换被管理的对象
    void reset(T *_ptr);
    // 交换被管理的对象
    void swap(UniquePtr &p);

private:
    T *ptr;
};

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr() : ptr(nullptr)
{}

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(T *_ptr) : ptr(_ptr)
{}

// 移交所有权
template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(UniquePtr &&p) : ptr(p.ptr)
{
    p.ptr = nullptr;
}

// 析构函数
template<typename T, typename Deleter>
UniquePtr<T, Deleter>::~UniquePtr() 
{
    Deleter()(ptr);
    std::cout << "unique ptr destory." << std::endl;
}

// 
template<typename T, typename Deleter>
T& UniquePtr<T, Deleter>::operator*()
{
    return *ptr;
}

// 
template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::operator->()
{
    return ptr;
}

// 
template<typename T, typename Deleter>
UniquePtr<T, Deleter>& UniquePtr<T, Deleter>::operator=(UniquePtr &&p) 
{
    std::swap(ptr, p.ptr);
    return *this;
}

template<typename T, typename Deleter>
UniquePtr<T, Deleter>::operator bool() const 
{
    return ptr != nullptr;
}

template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::get() const 
{
    return ptr;
}

template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::release()
{
    T *pointer = ptr;
    ptr = nullptr;
    return pointer;
}

template<typename T, typename Deleter>
void UniquePtr<T, Deleter>::reset(T *_ptr) 
{
    UniquePtr<T, Deleter>().swap(*this);
    ptr = _ptr;
}

template<typename T, typename Deleter>
void UniquePtr<T, Deleter>::swap(UniquePtr &p) 
{
    std::swap(ptr, p.ptr);
}
```



#### weak_ptr

**1、weak_ptr是为了配合shared_ptr而引入的一种智能指针**

它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况，但weak_ptr没有共享资源，它的构造不会引起指针引用计数的增加。

**2、和shared_ptr指向相同内存**

shared_ptr析构之后内存释放，在使用之前使用函数 `lock()` 检查weak_ptr是否为空指针。

```c++
template<typename T>
class WeakPtr
{
public:
    WeakPtr() {};

    WeakPtr(const SharedPtr<T> &p) : ptr(p.get())
    {}

    ~WeakPtr()
    {}

    WeakPtr<T>& operator= (const WeakPtr &p)
    {
        ptr = p.ptr;
        return *this;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }
    
    shared_ptr<T> lock() { return shared_ptr<T>(*this); };

    operator bool()
    {
        return ptr != nullptr;
    }

private:
    // weak point 只引用，不计数
    T *ptr;
};
```

### 内存泄漏

**1、定义：**

内存泄漏（memory leak）是指由于疏忽或错误造成了**程序未能释放掉不再使用的内存的情况**。内存泄漏并非指内有在物理上的消失，而是应用程序分配某段内存后，由于设计错误，失去了对该段内存的控制，因而造成了内存的浪费。改变了指针的指向，却没有释放动态分配的内存。

可以使用Valgrind, mtrace进行内存泄漏检查。



**2、内存泄漏有哪几种？**

**（1）堆内存泄漏（Heap leak）**

没有正确释放malloc、realloc、new等从堆中分配的内存。

**（2）系统资源泄露（Resource Leak）**

主要指程序使用系统分配的资源比如Bitmap, handle, SOCKET等没有使用相应的函数释放掉，导致系统资源的浪费，严重可导致系统效能降低，系统运行不稳定。

**（3）没有将基类的析构函数定义为虚函数**

当基类指针指向子类对象时，如果基类的析构函数不是virtual，那么子类的析构函数将不会被调用，子类的资源没有正确是释放，因此造成内存泄露。



**3、如何防止内存泄漏**

将内存的分配封装在类中，构造函数分配内存，析构函数释放内存；使用智能指针



**4、c/c++的内存分配方式**

**（1）从静态存储区分配**

内存在程序**编译**的时候就已经分配好，这块内存在程序的整个运行期间都存在，如全局变量，static变量。

**（2）在栈上创建**

在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。

**（3）从堆上分配（动态内存分配）**

程序在运行的时候用malloc或new申请任意多少的内存，程序员负责在何时用free或delete释放内存。动态内存的生存期自己决定，使用非常灵活。



**5、如何检测内存泄漏？**

1. 自己写一个内存检测工具，定位内存分配的位置，覆盖operator new和operator delete这种弱符号函数

   ```c++
   #define new new (__FILE__, __LINE__)
   void* operator new(std::size_t size, const char* file, int line);
   void* operator new[](std::size_t size, const char* file, int line);
   ```

2. 使用内存检测工具valgrind、mtrace等





### C++STL

#### vector

**1、扩容方式**

- 固定扩容：每次扩容的时候在原capacity的基础上加上固定的容量
- 加倍扩容：每次扩容的时候原capacity翻倍

**2、为什么要成倍的扩容而不是一次增加一个固定大小的容量呢？**

采用成倍方式扩容，可以保证常数的时间复杂度，而增加指定大小的容量只能达到O(n)的时间复杂度。

**3、为什么是以两倍的方式扩容而不是三倍四倍，或者其他方式呢？**

考虑可能产生的堆空间浪费，所以增长倍数不能太大，一般是1.5或2；GCC是2；VS是1.5，k=2每次扩展的新尺寸必然刚好大于之前分配的总和，之前分配的内存空间不可能被使用，这样对于缓存并不友好，采用1.5倍的增长方式可以更好的实现对内存的重复利用。



#### vector和list的区别

1. vector底层实现是数组；Iist 是双向链表
2. vector是顺序内存，支持随机访问，list不行
3. vector在中间节点进行插入删除会导致内存拷贝，list不会
4. vector一次性分配好内存，不够时才进行翻倍扩容；list每次插入新节点都会进行内存申请
5. vector随机访问性能好，插入删除性能差；list随机访问性能差，插入删除性能好



#### map和set

| 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::set           | 红黑树   | 有序     | 否               | 否           | O(logn)  | O(logn)  |
| std::multiset      | 红黑树   | 有序     | 是               | 否           | O(logn)  | O(logn)  |
| std::unordered_set | 哈希表   | 无序     | 否               | 否           | O(1)     | O(1)     |

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的

| 映射               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::map           | 红黑树   | key有序  | key不可重复      | key不可修改  | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | key有序  | key可重复        | key不可修改  | O(log n) | O(log n) |
| std::unordered_map | 哈希表   | key无序  | key不可重复      | key不可修改  | O(1)     | O(1)     |



**1、共同点**

都是C++的关联容器，只是通过它提供的接口对里面的元素进行访问，底层都是采用红黑树实现。

**2、不同点**

- set：用来判断某一个元素是不是在一个组里面。
- map：映射，相当于字典，把一个值映射成另一个值，可以创建字典。

**3、优点**

查找某一个数的时间为O(logn)；遍历时采用literator，效果不错。

**4、缺点**

每次插入值的时候，都需要调整红黑树，效率有一定影响



#### map和unordered_map

**1、底层实现**

- map底层是基于红黑树实现的，因此map内部元素排列是有序的。
- unordered_map底层是基于哈希表实现的，因此其元素的排列顺序是杂乱无序的。



**2、map优缺点**

- **优点**
  1. 有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作。
  2. map的查找、删除、增加等一系列操作时间复杂度稳定，都为O(Iogn)
- **缺点**
  1. 查找、删除、增加等操作平均时间复杂度较慢，与n相关。



**3、unordered_map优缺点**

- 优点
  1. 查找、删除、添加的速度快，时间复杂度为常数级O(1)
- 缺点
  1. 因为unordered_mapl内部基于哈希表，以（key,value）对的形式存储，因此空间占用率高。
  2. unordered map的查找、删除、添加的时间复杂度不稳定，平均为O(1)，取决于哈希函数。极端情况下可能为O(n)



**4、为什么insert之后，以前保存的iterator不会失效？**

因为map和set存储的是节点，不需要内存拷贝和内存移动。但是像vector在插入数据时如果内存不够会重新开辟一块内存。map和set的iterator指向的是节点的指针，vector指向的是内存的某个位置



**5、为何map和set的插入删除效率比其他序列容器高？**

因为map和set底部使用红黑树实现,插入和删除的时间复杂度是O(logn)，而向vector这样的序列容器插入和删除的时间复杂度是O(N)



### C++泛型编程

#### C++模板全特化和偏特化

模板分为类模板与函数模板，特化分为特例化（全特化）和部分特例化（偏特化）。
对模板特例化是因为对特定类型，可以利用某些特定知识来提高效率，而不是使用通用模板。

**函数模板：**

- 模板和特例化版本应该声明在同一头文件，所有同名模板的声明应放在前面，接着是特例化版本。
- 一个模板被称为全特化的条件：1.必须有一个主模板类。2.模板类型被全部明确化。

**对主版本模板类、全特化类、偏特化类的调用优先级从高到低进行排序是：全特化类>偏特化类>主版本模板类。**



### C++11新特性

#### 类型推导

**1、auto**

auto可以让编译器在**编译期**就推导出变量的类型

- auto的使用必须马上初始化，否则无法推导出类型
- auto在一行定义多个变量时，各个变量的推导不能产生二义性，否则编译失败（在一个语句中声明多个变量也行，因为一条声明语句只能有一个基本数据类型，所以该语句中所有变脸的初始基本数据都必须一样
- ![image-20240413222826301](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240413222826301.png)
- auto不能用作函数参数
- 在类中auto不能用作非静态成员变量
- auto不能定义数组，可以定义指针
- auto无法推导出模板参数
- 在不声明为引用或指针时，auto会忽略等号右边的引用类型和cv限定
- 在声明为引用或者指针时，auto会保留等号右边的引用和cv属性



**2、decltype**

decltype则用于推导表达式类型，这里只用于编译器分析表达式的类型，表达式实际不会进行运算

对于decltype(exp)有：

1. exp是表达式，decltype(exp)和exp类型相同
2. exp是函数调用，decltype(exp)和函数返回值类型相同
3. 其它情况,若exp是左值，decltype(exp)是exp类型的左值引用
4. `decltype` 根据表达式的类型来推导出相应的类型。
5. 对于普通标识符和表达式，推导结果是其值的类型。
6. 对于赋值表达式，推导结果是被赋值的左值引用类型。例如decltype（a = b) 意思是把推到结果int&，结果是被赋值的左值a。`decltype` 根据这个赋值操作推导出了表达式的类型。相当于是对a的引用，但是是实际上并不会改变a的值，decltype只关心表达式的类型推导，而不会执行表达式本身的操作
7. `decltype` 并不会实际执行表达式，它只用于类型推导

**auto和decltype的配合使用：**

```c++
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}
```



#### 右值引用

**1、左值和右值是什么意思？**

左值：可以放在等号左边，可以取地址并有名字

右值：不可以放在等号左边，不能取地址，没有名字

`++i,--i` 是左值（返回的是引用），`i++,i--` 是右值（返回的是对象）



**2、将亡值**

将亡值可以理解为即将要销毁的值，通过“盗取”其它变量内存空间方式获取的值，在确保其它变量不再被使用或者即将被销毁时，可以避免内存空间的释放和分配，延长变量值的生命周期，常用来完成移动构造或者移动赋值的特殊任务



**3、左值引用**

左值引用就是对左值进行引用的类型，是对象的一个别名并不拥有所绑定对象的堆存，所以必须立即初始化。

对于左值引用，等号右边的值必须可以取地址，如果不能取地址，则会编译失败，或者可以使用const引用形式



**4、右值引用**

表达式等号右边的值需要是右值，可以使用`std:move`函数强制把左值转换为右值。



**5、移动语义**

可以理解为转移所有权，对于移动语义，类似于转让或者资源窃取的意思，对于那块资源，转为自己所拥有，别人不再拥有也不会再使用。

通过移动构造函数使用移动语义，也就是`std:move`；移动语义仅针对于那些**实现了移动构造函数的类的对象**，对于那种基本类型int、float等没有任何优化作用，还是会拷贝，因为它们实现没有对应的移动构造函数



**6、完美转发**

写一个接受任意实参的函数模板，并转发到其它函数，目标函数会收到与转发函数完全相同的实参，通过`std:forward()`实现



#### nullptr

`nullptr`是用来代替`NULL`,一般C++会把NULL、O视为同一种东西,这取决去编译器如何定义`NULL`,有的定义为`(void*)0`,有的定义为0

C++11引入`nullptr`:关键字来**区分空指针和0**。nullptr的类型为`nullptr_t`,能够转换为任何指针或成员指针的类型,也可以进行相等或不等的比较。



#### lambda表达式

lambda表达式表示一个可调用的代码单元，没有命名的内联函数，不需要函数名因为我们直接（一次性的）用它，不需要其他地方调用它。

**1、lambda表达式的语法**

```c++
[capture list] (parameter list) -> return type {function body}
// [捕获列表] (参数列表) -> 返回类型 {函数体}
// 只有捕获列表和函数体是必选的

auto lam = []() -> int { cout << "Hello"; return 88; }
auto ret = lam();
cout << ret << endl;
```

大部分情况下lambda表达式的返回值可以由编译器得出，所以不需要显式指定返回值类型。



2、lambda表达式的特点

**（1）变量捕获**

1. []不捕获任何变量,这种情况下lambda表达式内部不能访问外部的变量
2. [&]以引用方式捕获所有变量(保证lambda执行时变量存在)
3. [=]用值的方式捕获所有变量(创建时拷贝,修改对lambda内对象无影响)
4. [=,&foo]以引用捕获变量foo,但其余变量都靠值捕获
5. [&,foo]以值捕获foo,但其余变量都靠引用捕获
6. [bar]以值方式捕获bar;不捕获其它变量
7. [this]捕获所在类的this指针

**（2）排序**

```c++
int arr[] = {6, 4, 3, 2, 1, 5, 4};
bool compare(int& a, int& b) { //谓词函数
    return a > b;
}
std::sort(arr, arr + 6, compare);

// lambda形式
std::sort(arr, arr + 6, [](const int& a, const int& b) {return a < b});
```



#### 可调用对象

1. 普通函数
2. 函数指针
3. 仿函数，即重载了operator()运算符的类对象
4. 匿名函数，即 **Lambda表达式**
5. std::function





## 《Effective STL》

### 条款13：尽量使用vector和string来代替动态分配的数组

在多线程中使用引用计数的string，会导致保护引用计数的同步开销。可以考虑使用不允许使用引用计数的`vector<char>`，当然会少了许多string具有的特性。



### 条款14：使用reserve来避免不必要的重新分配

因为动态扩展空间意味着你要做以下四件事：

1. 分配新的内存块，它有容器目前容量的几倍。在大部分实现中，vector和string的容量每次以2为因数增长。也就是说，当容器必须扩展时，它们的容量每次翻倍。
2. 把所有元素从容器的旧内存拷贝到它的新内存。
3. 销毁旧内存中的对象。
4. 回收旧内存。



### 条款15：小心string实现的多样性

> `sizeof(string)`是多少？

根据库函数的具体实现而定， string对象的大小可能从1到至少7倍char*指针的大小。

- 新字符串值的建立可能需要0、1或2次动态分配。
- string对象可能是或可能不共享字符串的大小和容量信息。
- 字符串值可能是或可能不是引用计数的。
- 不同实现对于最小化字符缓冲区的配置器有不同策略。
- string可能是或可能不支持每对象配置器。



### 条款16：如何将vector和string的数据传给遗留的API

一个`vector<int>`对象需要传入形参为`int*`的函数：

```c++
vector<int> v;
void doSomething(const int* pInts, size_t numInts);

if(!v.empty()) {
    // 需要先判断是否为空，否则&v[0]试图产生一个指向根本就不存在的东西的指针
    // 并且不可用v.begin()代替&v[0]，v.begin()不总是指针，也有可能是对象iterator
    doSomething(&v[0], v.size());
}
```

而上述方法对于`string`是不可靠的，因为

- string中的数据并没有保证被 存储在独立的一块连续内存中
- string的内部表示形式并没承诺以一个null字符结束。

实际上，应该通过`c_str()`传递

```
string s;
void doSomething(const char* pString);

doSomething(s.c_str());
```

让C风格API把数据放入一个vector，然后拷到你实际想要的STL容器中的主意总是有效的



### 条款17：使用swap来修正过剩容量

修正剩余容量

```c++
string s;
... // 使s变大，然后收缩空间
string(s).swap(s);
```

清除容器，并且最小化它的容量

```c++
vector<int> v;
doSomething(v);
vector<int>().swap(v);
```



### 条款18：避免使用`vector<bool>`

`vector<bool>`存在两个问题：

- 它不是一个STL容器
- 它并不容纳bool，每个保存在`vector`中的`bool`占用一个单独的比特，而一个8比特的字节将容纳8 个`bool`。

实际使用中最好使用`deque<bool>`或者`bitset`



### 条款21：永远让函数对相等的值返回false

除非你的比较函数总是为相等的值返回false，你将会打破所有的标准关联型容器，不管它们是否允许存储复本。

- 对于set/map，会导致存入了重复的元素
- 对于multiset/multimap，会导致equal_range等算法失效

```c++
struct myCmp {
    bool operator() (const string* s1, const string* s2) {
        return *s1 < *s2;
        // 不能写
        // return *s1 <= *s2;
    }
};
```



### 条款22：避免原地修改set和multiset的键

这对于map和multimap特别简单，因为试图改变这些容器里的一个键值的程序将不能编译，因为`map/multimap<K, V>`中元素的类型是，`pair<const K, V>`除非使用`const_cast`否则无法修改。

```c++
map<int, string> m;
multimap<int, string> mm;
dosomething();
m.begin()->first = 20; // 错误！map键不能改变
mm.begin()->first = 20;// 错误！multimap键也不能改变
```

本条款的目的是提醒你如果你改变set或 multiset里的元素， 你必须确保不改变一个键部分——影响容器有序性的元素部分。

大多数映射可以避免，那包括我们刚刚考虑的。如果你要总是可以工作而且总是安全地改变set、multiset、 map或multimap里的元素，按五个简单的步骤去做：

1. 定位你想要改变的容器元素。如果你不确定最好的方法，条款45提供了关于怎样进行适当搜寻的指导。
2. 拷贝一份要被修改的元素。对map或multimap而言，确定不要把副本的第一个元素声明为const。毕竟，你想要改变它！
3. 修改副本，使它有你想要在容器里的值。
4. 从容器里删除元素，通常通过调用erase（参见条款9）。
5. 把新值插入容器。**如果新元素在容器的排序顺序中的位置正好相同或相邻于删除的元素**，使用insert 的“提示”形式把插入的效率从对数时间改进到分摊的常数时间。使用你从第一步获得的迭代器作为提示。



### 条款23：考虑用有序vector代替关联容器



### 条款24：当在乎效率时应该在map::operator[]和map-insert之间谨慎选择

是`operator[]`返回一个与**k关联的值对象的引用**。然后v赋值给所引用（从`operator[]`返回的）的 对象。当要更新一个已存在的键的关联值时很直接，因为已经有`operator[]`可以用来返回引用的值对象。但是 如果k还不在map里，`operator[]`就没有可以引用的值对象。那样的话，它使用值类型的默认构造函数从头开始建立一个，然后`operator[]`返回这个新建立对象的引用。

```c++
// 例如
map<int, Widget> m;
m[1] = 1.50;

// 等价于
typedef map<int, Widget> intWidgetMap;
pair<intWidgetMap::iterator, bool> result =     // 先用以键为1构造一个默认的对象插进去
    m.insert(intWidgetMap::value_type(1, Widget()));
result.first->second = 1.50;	// 然后再修改值

// 应该这样做
m.insert(intWidgetMap::value_type(1, 1.50));
// 节省了三次函数调用
// 1.构造临时的Widget()对象
// 2.临时对象的销毁
// 3.对widget的赋值操作
```

**总结：**

- 要更新已存在的map元素，operator[]更好
- 如果要增加一个新元素，insert则有优势。



### 条款26：尽量用iterator代替const_iterator,reverse_iterator和const_reverse_iterator



### 条款29：需要一个一个字符输入时考虑使用istreambuf_iterator



### 条款31：了解你的排序选择

**1、部分排序（前面的一部分一定是有序的）：**

```c++
//按照默认的升序排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last);
//按照 comp 排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last,
                   Compare comp);
```

`partial_sort()` 或 `partial_sort_copy()` ，会以交换元素存储位置的方式实现部分排序，partial_sort() 会将 [first, last) 范围内最小（或最大）的 middle-first 个元素移动到 [first, middle) 区域中，并对这部分元素做升序（或降序）排序。

**容器支持的迭代器类型必须为随机访问迭代器，只适用于 array、vector、deque 这 3 个容器。**



**2、部分排序（前面的一部分不一定是有序的）：**

```c++
//排序规则采用默认的升序排序
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last);
//排序规则为自定义的 comp 排序规则
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last,
                  Compare comp);
```

整个序列经过 nth_element() 函数处理后，所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大。

**容器支持的迭代器类型必须为随机访问迭代器，只适用于 array、vector、deque 这 3 个容器。**



**排序算法选择**：

- 如果你需要在vector、string、deque或数组上进行完全排序，你可以使用sort或stable_sort。
- 如果你有一个vector、string、deque或数组，你只需要排序前n个元素，应该用partial_sort。
- 如果你有一个vector、string、deque或数组，你需要鉴别出第n个元素或你需要鉴别出最前的n个元素， 而不用知道它们的顺序，nth_element是你应该注意和调用的。
- 如果你需要把标准序列容器的元素或数组分隔为满足和不满足某个标准，你大概就要找partition或 stable_partition。
- 如果你的数据是在list中，你可以直接使用partition和stable_partition，你可以使用list的sort来代替sort和 stable_sort。如果你需要partial_sort或nth_element提供的效果，你就必须间接完成这个任务，但正如我 在上面勾画的，会有很多选择。



### 条款32：如果你真的想删除东西的话就在类似remove的算法后接上erase

`remove()` 相当于压缩，将不要的值移动到需要删除的值的位置上，然后返回结束位置的迭代器

**注意：`remove()` 不会改变容器的size，因为他无法调用容器的接口。**

**因此删除指定值的元素需要这么做：**

```c++
vector<int> v;
v.erase(remove(v.begin(), v.end()), v.end());  // 删除所有值为99的元素
```



### 条款34：注意哪些算法需要有序区间

只能操作有序数据的算法的表：

| 算法名         | 备注                                       | 算法名                         | 备注                                   |
| -------------- | :----------------------------------------- | ------------------------------ | -------------------------------------- |
| binary_search  | 二分查找                                   | lower_bound                    | 查找不小于目标值的第一个元素           |
| upper_bound    | 查找大于目标值的第一个元素                 | equal_range                    | 查找等于目标值的所有元素               |
| set_union      | 集合的并集运算                             | set_intersection               | 集合的交集运算                         |
| set_difference | 集合的差集运算                             | set_symmetric_<br />difference | 取集合对称差集                         |
| merge          | 将 2 个有序序列合并为 1 个有序序列         | inplace_merge                  | 同左，不过它是两个有序序列在同一个容器 |
| includes       | 检测是否一个区间的所有对象也在另一个区间中 |                                |                                        |



### 条款35：通过mismatch或lexicographical比较实现简单的忽略大小写字符串比较



### 条款37：用accumulate或for_each来统计区间



**区别：**

1. accumulate 的名字表示它是一个产生区间统计的算法（只读），for_each 更像只是对区间中的每个元素进行操作。

2. accumulate 直接返回我们想要的统计值，for_each 返回一个函数对象



### 条款38：把仿函数类设计为用于值传递

因为函数对象以值传递和返回，所以需要确保两件事情：

1. 保证你的函数对象应该很小，否则它们的拷贝会很昂贵。
2. 你的函数对象必须单态-->他们不能使用虚函数，因为派生类对象以值传递带入基类类型的参数会造成切割问题：在拷贝时，它们的派生部分被删除。



### 条款39：用纯函数做判断式



### 条款41：了解是使用ptr_fun、mem_fun和mem_fun_ref的原因

只要你传一个成员函数给 STL 组件，你就必须使用他们

`mem_fun` 主要为了解决在 `for_each` 中调用成员函数的问题：

`mem_fun` 的声明：

```c++
template<typename R, typename C>
mem_fun_t<R, C>
	mem_fun(R(C::*pmf)());
```



```c++
vector<Widget> vw;
//example 1.
void test(Widget& w);
for_each(vw.begin(), vw.end(), test);  //非成员函数ok

//example 2.（test()是Widget的成员函数）
for_each(vw.begin(), vw.end(), mem_func(&Widget::test));
```



### 条款42：确定 `less<T>` 表示operator<



### 条款43：尽量用算法调用代替手写循环

有三个理由：

- 效率：算法通常比程序员产生的循环更高效
- 正确性：写循环时比调用算法更容易产生错误
- 可维护性：算法通常使代码比相应的显示循环更干净、更直观



## C++常见面试题



### C++ 基础

#### i++和++i的区别

一个是引用，一个是临时值，++i效率高，不涉及创建临时值，i++多一次拷贝，析构过程把，而且它们两个函数的参数不一样，为了区分

#### 说说 C 语言和 C++ 的区别

1. C 语言是 C++ 的子集，c++可以兼容 c 语言，但是 c++ 里面又引入了很多新特性，如引用、智能指针、类等
2. c++ 是面向对象的语言，c 是面向过程的语言
3. c 语言中存在一些不安全的语言特性，如指针使用的潜在危险、强制转换的不确定性、内存泄漏等。而 C++ 增加了新特性来改善安全性，如 const常量、智能指针、cast 转换、try-catch 异常处理等
4. c++的可复用性高，引入了模板的概念。并在此基础上实现了标准模板库 STL，与 c语言函数库相比更加灵活
4. 在C++中，允许有相同的函数名，不过它们的参数类型不能完全相同，这样这些函数就可以相互区别开来。而这在C语言中是不允许的。也就是C++可以重载，C语言不允许。
4. 标准C++中的字符串类取代了标准C函数库头文件中的字符数组处理函数（C中没有字符串类型）。



#### C++和Python的区别

1. Python是一种脚本语言，是解释执行的，而C++是编译语言，是需要编译后在特定平台运行的。python可以很方便的跨平台，但是效率没有C++高。
2. Python使用缩进来区分不同的代码块，C++使用花括号来区分
3. C++中需要事先定义变量的类型，而Python不需要，Python的基本数据类型只有数字，布尔值，字符串，列表，元组等等
4. Python的库函数比C++的多，调用起来很方便



#### 结构体和类的区别？

1. 从定义上来讲，结构体是描述数据结构的集合；而类是对一个对象数据的封装。
1. 无论是成员结构体的默认限定符是public；类是private
2. 在继承关系中，结构体默认是公有继承，而类默认是私有继承
2. **class 关键字可以用于定义模板参数。**



#### C++ 和 C 中 struct 的区别

- [ ] **函数、权限、继承、实例化**

1. C 的结构体不允许有函数存在（但可以有函数指针），而 C++ 的结构体允许有内部函数，并且允许该函数是虚函数。
2. C 的结构体内部成员不能设置权限，均为 public。而 C++ 的结构体可以设置内部成员的权限，默认为 public。
3. C 的结构体不能继承，而 C++ 的结构体可以从其他结构体或者类中继承。
4. C 中实例化一个结构体，需要带上 struct 关键字。而 c++ 中不用。



#### 指针和引用的区别？

- [ ] 四个：定义、初始化、合法性、可变性

1. **定义**：指针存放的是某个对象的地址，引用表示的是一个对象的别名。
2. **初始化**：引用在定义的时候必须进行初始化，但是指针不需要。
3. **判断合法性**：因为引用在定义的时候必须进行初始化，所以在使用的时候不需要判断它是否为空。但是指针需要。
4. **是否可变**：指针可以被重新赋值来指向其他的对象，但是引用总是指向在初始化就被指定的对象，不不可变，类似于指针常量。



#### 强引用和弱引用的区别

编译器默认函数和已初始化的全局变量为强符号，而未初始化的全局变量为弱符号。

- 当两者都为强符号时，报错：redefinition of 'xxx'
- 当两者为一强一弱时，选取强符号的值
- 当两者同时为弱时，选择其中占用空间较大的符号，这个其实很好理解，编译器不知道编程者的用意，选择占用空间大的符号至少不会造成诸如溢出、越界等严重后果。









#### 数组名和指针（指向数组首元素的指针）的区别？

1. 二者均可通过增减偏移量来访问数组中的元素。
2. 数组名不是真正意义上的指针，可以理解为指针常量，所以数组名没有自增、自减等操作。
3. 当数组名当做形参传递给调用函数后，就失去了原有特性，退化成一般指针，多了自增、自减操作，但sizeof运算符不能再得到原数组的大小了。



#### 什么是野指针？怎么产生的？如何避免？

1. **定义：**野指针是指指向位置随机的、不可知的、不正确的的指针。
2. **野指针产生原因：**指针变量未初始化或者随便赋值，指针释放后未置空，指针操作超出了变量的作用域（返回局部变量的指针或者引用）
3. **如何避免：**指针变量一定要初始化、释放后置为空。



#### 静态变量何时初始化？

1. 对于C语言的全局和静态变量，初始化发生在任何代码执行之前，属于编译期初始化。
2. 而C++标准规定：全局或静态对象当且仅当对象首次用到时才进行构造。



#### 堆和栈的区别

1. **申请方式不同**
   - 栈由系统自动分配
   - 堆由程序员手动分配
2. **申请大小限制不同**
   - 栈顶和栈底是之前预设好的，大小固定，可以通过ulimit -a查看，由ulimit -s修改。
   - 堆向高地址扩展，是不连续的内存区域，大小可以灵活调整。
3. **申请效率不同**
   - 栈由系统分配，速度快，不会有碎片。
   - 堆由程序员分配，速度慢，且会有碎片。

|                  |                              堆                              |                              栈                              |
| ---------------- | :----------------------------------------------------------: | :----------------------------------------------------------: |
| **管理方式**     |         堆中资源由程序员控制（容易产生memory leak）          |             栈资源由编译器自动管理，无需手工控制             |
| **内存管理机制** | 系统有一个记录空闲内存地址的链表，当系统收到程序申请时，遍历该链表，寻找第一个空间大于申请空间的堆结点，删 除空闲结点链表中的该结点，并将该结点空间分配给程序（大多数系统会在这块内存空间首地址记录本次分配的大小，这样delete才能正确释放本内存空间，另外系统会将多余的部分重新放入空闲链表中） | 只要栈的剩余空间大于所申请空间，系统为程序提供内存，否则报异常提示栈溢出。 |
| **空间大小**     | 堆是不连续的内存区域（因为系统是用链表来存储空闲内存地址，自然不是连续的），堆大小受限于计算机系统中有效的虚拟内存（32bit 系统理论上是4G），所以堆的空间比较灵活，比较大 |        栈是一块连续的内存区域，大小是操作系统预定好的        |
| **碎片问题**     |    对于堆，频繁的new/delete会造成大量碎片，使程序效率降低    | 对于栈，它是有点类似于数据结构上的一个先进后出的栈，进出一一对应，不会产生碎片 |
| **生长方向**     |                  堆向上，向高地址方向增长。                  |                  栈向下，向低地址方向增长。                  |
| **分配方式**     |              堆都是动态分配（没有静态分配的堆）              | 栈有静态分配和动态分配，静态分配由编译器完成（如局部变量分配），动态分配由alloca函数分配，但栈的动态分配的资源由编译器进行释放，无需程序员实现。 |
| **分配效率**     |  堆由C/C++函数库提供，机制很复杂。所以堆的效率比栈低很多。   | 栈是其系统提供的数据结构，计算机在底层对栈提供支持，分配专门 寄存器存放栈地址，栈操作有专门指令。 |



> 堆和栈的效率对比

因为操作系统会在底层对栈提供支持，会分配专门的寄存器存放栈的地址，栈的入栈出栈操作也十分简单，并且有专门的指令执行，所以栈的效率比较高也比较快。

而堆的操作是由C/C++函数库提供的，在分配堆内存的时候需要一定的算法寻找合适大小的内存。并且获取堆的内容需要两次访问，第一次访问指针，第二次根据指针保存的地址访问内存，因此堆比较慢。





#### 内联函数和宏函数的区别？

1. **宏定义不是函数**，但是使用起来像函数。预处理器用复制宏代码的方式代替函数的调用，省去了函数压栈退栈过程，提高了效率；**而内联函数本质上是一个函数**，内联函数一般用于函数体的代码比较简单的函数，不能包含复杂的控制语句，while、switch，并且内联函数本身不能直接调用自身。
2. **宏函数**是在预编译的时候把所有的宏名用宏体来替换，简单的说就是字符串替换 ；**而内联函数**则是在编译的时候进行代码插入，编译器会在每处调用内联函数的地方直接把内联函数的内容展开，这样可以省去函数的调用的开销，提高效率
3. **宏定义**是没有类型检查的，无论对还是错都是直接替换；**而内联函数**在编译的时候会进行类型的检查，内联函数满足函数的性质，比如有返回值、参数列表等
4. 内联函数只是用户给编译器的建议，编译器可以不执行。



#### malloc 和 new 的区别，以及各自的底层实现原理？

1. new是操作符，而malloc是函数。
2. new在调用的时候先分配内存，在调用构造函数，释放的时候调用析构函数；而malloc没有构造函数和析构函数。
3. malloc需要给定申请内存的大小，返回的指针需要强转；new会调用构造函数，不用指定内存的大小，返回指针不用强转。
4. new可以被重载；malloc不行
5. new分配内存更直接和安全。
6. new发生错误抛出异常，malloc返回null



**malloc底层实现：**当开辟的空间小于 128K 时，调用 `brk()` 函数；当开辟的空间大于 128K 时，调用 `mmap()`。malloc采用的是内存池的管理方式，以减少内存碎片。先申请大块内存作为堆区，然后将堆区分为多个内存块。当用户申请内存时，直接从堆区分配一块合适的空闲快。采用隐式链表将所有空闲块，每一个空闲块记录了一个未分配的、连续的内存地址。

**new底层实现：**new关键字在底层调用的是operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，尝试执行空间不足的应对措施，如果该应对措施用户设置了，则继续申请，否则抛异常。

1. 创建一个新的对象
2. 将构造函数的作用域赋值给这个新的对象（因此this指向了这个新的对象）
3. 执行构造函数中的代码（为这个新对象添加属性）
4. 返回新对象

> 如何让 new 不抛出异常？

1. 使用 `new(std::nothrow)` 关键字，当 new 一个对象失败时，默认设置对象为 NULL。
2. 通过 `set_new_handler(noMoreMemory);` 让 new 抛出异常时，执行程序给定的handler。一般来说 handler 只有两个选择：
   - 让更多memory可用（调用了程序员指定的handler，表示内存基本用完了，程序员可以选择释放一些其他的内存，C++会再次尝试new）
   - 调用 abort() 或 exit()





#### 对数组名取地址的增量问题

```c++
int a[][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};

// 1、对数组名取地址，增量为整个数组
// p1 指向的二维数组末尾元素的下一个字节
int *p1 = (int *)(&a + 1);  // p1 增量为 sizeof(int)
auto p1 = &a + 1;  // p1 增量为 sizeof(a)

// 2、首地址的增量是该数组的大小
// p2 指向第二个一维数组
int *p2 = (int *)(a + 1);  // p2 增量为 sizeof(int)
auto p2 = a + 1; // p2 增量为 sizeof(a[0])

// 3、a[0]是第一个一维数组
// 与 1 类似，看是否对数组名取地址
int *p3 = (int *)(a[0] + 1);  // p3 指向 a[0][1]，增量为 int
int *p4 = (int *)(&a[0] + 1); // p4 指向 a[1][0]，增量为 sizeof(int)
auto p4 = &a[0] + 1;  // p4 指向 a[1][0]，增量为 sizeof(a[0])
```



#### 有符号数和无符号数之间的转换

```
题目：
    32位机上根据下面的代码，问哪些说法是正确的？
    signed char a = 0xe0;
    unsigned int b = a;
    unsigned char c = a;

答案:
    b的十六进制表示是：0xffffffe0

解答:
    考察有符号数和无符号数之间的转换。
    1. a : 1110 0000。
    2. 扩展问题：
        长 -> 短：低位对齐，按位复制。
        短 -> 长：符号位扩展。
    3. 精度提升：
        两个变量运算，表示范围小的变量精度达的变量提升（signed -> unsigned）。
```



#### 内存对齐

1. **定义**

   指的是内存中数据的首地址是CPU单次获取数据大小的整数倍

2. **为什么要有内存对齐**

   - **平台原因**：不是所有的硬件平台都能访问任意内存地址上的任意数据，某些硬件平台（ARM架构的）只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。为了同一个程序可以在多平台运行，需要内存对齐。
   - **硬件原因**：经过内存对齐后，CPU访问内存的速度大大提升。
     1. CPU每次寻址都是要消费时间的，如果一次取不完数据就要取多次。比如int类型的变量a占4Byte，假设在内存中没有对齐，且存放在0x00000003 - 0x00000006处(**0x00000003不是4的整数倍**)。那么每次取4字节(32位宽总线)的CPU第一次取到[0x00000000 - 0x00000003]，只得到变量a的1/4数据，进而需要进行第二次取数[0x00000004 - 0x00000007]，为了得到int类型的一个变量，却需要两次访问内存，并且还需要拼接处理，**性能较低**。

   

3. **应用场景**

   内存对齐应用于三种数据类型中：**struct/class/union**

   - 数据成员对齐规则：结构(struct)或联合(union)的数据成员，第一个数据成员放在offset为0的地方，以后每个数据成员存储的起始位置要从该成员大小或者成员的子成员大小的整数倍开始。
   - 结构体作为成员:如果一个结构里有某些结构体成员,则结构体成员要从其内部"最宽基本类型成员"的整数倍地址开始存储。(struct a里存有struct b,b里有char,int ,double等元素,那b应该从8的整数倍开始存储)。
   - 收尾工作:结构体的总大小，也就是sizeof的结果，必须是其内部最大成员的"**最宽基本类型成员**"的整数倍。不足的要补齐。(基本类型不包括struct/class/uinon)。
   - sizeof(union)，以结构里面size最大元素为union的size，因为在某一时刻，union只有一个成员真正存储于该地址。
   
4. **取消对齐**

   使用 `__attribute__((packed))` 关键字，让编译器取消对齐优化







#### 简述一下 C++11 中四种类型转换

**这个需要由编译器支持。**

1. `（类型说明符）表达式->(int)a`

- 从C语言继承的方法，把表达式的值强制转换为类型说明符表示的类型

2. `reinterpret_cast<类型说明符>(表达式）->reinterpret_cast<int>(a)`

* 转换一个指针为其它类型的指针。它也允许从一个指针转换为整数类型。反之亦然。这个操作符能够在非相关的类型之间转换。操作结果只是简单的从一个指针到别的指针的值的二进制拷贝。在类型之间指向的内容不做任何类型的检查和转换。如传统的类型转换一样对待所有指针的类型转换
* 特意用于底层的强制转型，导致实现依赖（implementation-dependent）（就是说，不可移植）的结果，例如，将一个指针转型为一个整数。这样的强制转型在底层代码以外应该极为罕见。

3. `const_cast<类型说明符>(表达式）->const_cast<int>(a)`

* 这个转换类型操纵传递对象的const属性，或者是设置或者是移除
* 一般用于强制消除对象的常量性。它是唯一能做到这一点的 C++ 风格的强制转型

4. `dynamic_cast<类型说明符>(表达式）->dynamic_cast<int>(a)`

* 只用于对象的指针和引用。用于将指向基类的指针或引用转换成指向其派生类或其兄弟类的指针或引用。当转换失败时将返回空指针（指针），或者抛出异常（引用）
* 不能用于没有继承关系的类型转换，也不能用于转换 const

5. `static_cast<类型说明符>(表达式）->static_cast<int>(a)`

* 允许执行任意的隐式转换和相反转换动作，特别的点：允许父类指针转化为子类指针（下行转换）
* 可以被用于强制隐型转换（例如，non-const 对象转型为 const 对象，int 转型为 double，等等），它还可以用于很多这样的转换的反向转换（例如，void* 指针转型为有类型指针，基类指针转型为派生类指针），但是它不能将一个 const 对象转型为 non-const 对象（只有 const_cast 能做到），它最接近于C-style的转换。



> 与 C语言 中强制转换的区别

C的强制转换表面上看起来功能强大什么都能转，但是转换不够明确，不能进行错误检查，容易出错。



> static_cast 和 reinterpret_cast都能转换指针，二者有什么区别？

这方面我不太清楚，但是我可以讲一下我碰到过的区别：

在多重继承中，比如 C 继承 B，继承 A，对于一个指向 C 的指针转换为 B*，`static_cast` 会正确的指向 B 的对象，而 `reinterpret_cast` 依旧指向 C 的对象。我的理解是 `reinterpret_cast` 只是按照转换的类型，重新解释了指针，并不保证转换的结果是合理的。





#### 堆栈溢出？如何避免？

递归过程的局部变量过多、递归深度过大，是造成系统栈溢出的原因，特别是递归列循环时肯定会发生系统栈溢出。



> 如何避免栈溢出

- 减少栈空间的需求，**`不要定义占用内存较多的局部变量`**，应该将此类变量修改成指针或者引用，`从堆空间分配内存`。
- 函数参数中不要传递大型结构/联合/对象，应该使用`引用或指针作为函数参数`。
- 减少函数调用层次，`慎用递归函数`，例如A->B->C->A环式调用。



#### 主函数的退出方式有哪些？各自的区别是什么？



- **正常退出方式**：exit()、_exit()、return（在main中）。

  exit() 和 exit() 区别：exit() 是对 \_exit() 的封装，都会终止进程并做相关收尾工作，最主要的区别是 exit() 函数关闭全部描述符和清理函数后不会刷新流，但是 exit() 会在调用 \_exit() 函数前刷新数据流。

  return 和 exit() 区别：exit() 是函数，但有参数，执行完之后控制权交给系统。return 若是在调用函数中，执行完之后控制权交给调用进程，若是在 main 函数中，控制权交给系统。

- **异常退出方式**：abort()、终止信号。



### 面向对象基础



#### 说一下你对面向对象的理解？

面向对象是将用户需要功能等通过对象来实现，将功能封装进对象之中，让对象去实现具体的细节；

面向对象有三大特征：封装性、继承性、多态性。

1. **封装性**：是隐藏了对象的属性和实现细节，将一些方法和属性私有化，仅对外提供公共的访问方式，这样就隔离了具体的实现，便于用户使用，提高了代码复用性和安全性。
2. **继承性**：将共性的内容放在父类中，子类只需要关注自己特有的内容，共性的继承过来。这就提高了代码的复用性。继承是作为动态多态的前提。
3. **多态**：一个对象在不同的情况下显示不同的形态，是说父类的指针或者引用指向了子类对象，从而调用子类中重写了父类中相应的方法，这就提高了程序的扩展性。



#### C++ 的构造函数有哪几种？分别有什么用？

C++中的构造函数可以分为4类：默认构造函数、初始化构造函数、拷贝构造函数、移动构造函数。

1. 默认构造函数和初始化构造函数。 在定义类的对象的时候，完成对象的初始化工作。
2. 赋值构造函数默认实现的是值拷贝（浅拷贝）。
3. 移动构造函数。用于将其他类型的变量，隐式转换为本类对象。



#### 说说一个类，默认会生成哪些函数

1. 一个无参的默认构造函数
2. 拷贝构造函数（浅拷贝）
3. 拷贝赋值运算符
4. 析构函数（非虚）



#### 类中的常函数什么作用？

1. 类的成员函数后面加 const，表明这个函数不能对这个类对象的数据成员（准确地说是非静态数据成员）作任何改变。
2. 有 const 修饰的成员函数（指 const 放在函数参数表的后面，而不是在函数前面或者参数表内），只能读取数据成员，不能改变数据成员；没有 const 修饰的成员函数，对数据成员则是可读可写的。
3. 常量（即 const）对象可以调用 const 成员函数，而不能调用非 const 修饰的函数。



#### 面向对象三大特性？

- **封装性：**将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交互。本质上是一种管理。C++通过 private、protected、public 三个关键字来控制成员变量和成员函数的访问权限。能够提高代码的复用性和安全性。

- **继承性：**最重要的特征是代码重用，通过继承机制可以利用已有的数据类型来定义新的数据类型，是多态的基础。

- **多态性：**在面向对象中，多态是指通过基类的指针或者引用，在运行时动态调用实际绑定对象函数的行为。多态是在程序运行时根据基类的引用（指针）指向的对象来确定自己具体该调用哪一个类的虚函数。当父类指针（引用）指向 父类对象时，就调用父类中定义的虚函数；即当父类指针（引用）指向 子类对象时，就调用子类中定义的虚函数。多态性改善了代码的可读性和组织性，同时也使创建的程序具有可扩展性。



#### 简述一下 C++ 中的多态

- [ ] 静态多态、动态多态、多态的实现原理、虚函数、虚函数表

1. 多态是同一个事物在不同场景下的多种形态。
2. **静态多态：**静态多态是编译器在编译期间完成的，编译器会根据实参类型来选择调用合适的函数，如果有合适的函数就调用，没有的话就会发出警告或者报错。静态多态有**函数重载、运算符重载、泛型编程**等。
3. **动态多态：**动态多态是在程序运行时根据基类的引用（指针）指向的对象来确定自己具体该调用哪一个类的虚函数。当父类指针（引用）指向 父类对象时，就调用父类中定义的虚函数；即当父类指针（引用）指向 子类对象时，就调用子类中定义的虚函数。**动态多态行为的表现效果为：同样的调用语句在实际运行时有多种不同的表现形态。**
4. **实现动态多态的条件：** 
   - 要有继承关系 - 要有虚函数重写（被 virtual 声明的函数叫虚函数）
   - 要有父类指针（父类引用）指向子类对象
5. **动态多态的实现原理：**当类中声明虚函数时，编译器会在类中生成一个虚函数表，虚函数表是一个存储类虚函数指针的数据结构， 虚函数表是由**编译器自动生成与维护的**。virtual 成员函数会被编译器放入虚函数表中，存在虚函数时，每个对象中都有一个指向虚函数表的指针（vptr 指针）。在多态调用时，vptr 指针就会根据这个对象在对应类的虚函数表中查找被调用的函数，从而找到函数的入口地址。





#### 对象的存储空间？

##### 空类的大小为什么1字节？

因为任何不同的对象不能拥有相同的内存地址

为了区分空类的实例化对象，和实现每个实例在内存中都有一个独一无二的地址，编译器往往会给一个空类隐含的加一个字节，这样空类在实例化后在内存得到了独一无二的地址，所以空类所占的内存大小是1个字节。



##### 对象的存储空间由什么决定？

1. 非静态成员的数据类型大小之和。
2. 编译器加入的额外成员变量（如指向虚函数表的指针）。
3. 为了边缘对齐优化加入的padding。



#### C++ 中哪些函数不能声明为虚函数？

普通函数（非成员函数）、静态成员函数、内联成员函数、构造函数、友元函数

1. **构造函数**：构造函数用来创建一个新的对象，而虚函数的运行是建立在对象已经实例化的基础上，在构造函数执行时，对象尚未形成，所以不能将构造函数定义为虚函数。在派生类的构造函数中调用虚函数，执行的是基类的版本。
2. **内联成员函数**：因为内联成员函数是在编译期展开的，而虚函数是在运行时才动态绑定的，在运行前内联函数就已经确定了。
3. **静态成员函数**：静态成员函数对于每个类来说只有一份代码，所有的对象都共享这一份代码，他也没有要动态绑定的必要性。并且静态成员函数属于一个类而非某一对象，没有this指针,它无法进行对象的判别。
4. **友元函数**：C++不支持友元函数的继承，对于没有继承特性的函数没有虚函数的说法。





#### 构造函数和析构函数能否为虚函数？

- **析构函数可以为虚函数**
  1. 析构函数可以为虚函数，并且一般情况下基类析构函数要定义为虚函数。
  2. 只有在基类析构函数定义为虚函数时，调用操作符delete销毁指向对象的基类指针时，才能准确调用派生类的析构函数（从该级向上按序调用虚函数），才能准确销毁数据。
  3. 析构函数可以是纯虚函数，含有纯虚函数的类是抽象类，此时不能被实例化。但派生类中可以根据自身需求重新改写基类中的纯虚函数。

- **构造函数**
  1. **从存储空间角度：**虚函数对应一个vtale,这个表的地址是存储在对象的内存空间的。如果将构造函数设置为虚函数，就需要到 vtable 中调用，可是对象还没有实例化，没有内存空间分配，如何调用。
  2. **从使用角度：**虚函数主要用于在信息不全的情况下，能使重载的函数得到对应的调用。构造函数本身就是要初始化实例，那使用虚函数也没有实际意义呀。所以构造函数没有必要是虚函数。虚函数的作用在于通过父类的指针或者引用来调用它的时候能够变成调用子类的那个成员函数。而构造函数是在创建对象时自动调用的，不可能通过父类的指针或者引用去调用，因此也就规定构造函数不能是虚函数。
  3. 从实现上看，vbtl 在构造函数调用后才建立，因而构造函数不可能成为虚函数。从实际含义上看，在调用构造函数时还不能确定对象的真实类型（因为子类会调父类的构造函数）；而且构造函数的作用是提供初始化，在对象生命期只执行一次，不是对象的动态行为，也没有太大的必要成为虚函数。
  4. 构造函数中可以调用虚函数，不过调用的是基类的虚函数，因为子类还没有构建完成。



#### 构造函数的调用顺序，析构函数呢？

1. 调用所有虚基类的构造函数，顺序为从左到右，从最深到最浅
2. 基类的构造函数：如果有多个基类，先调用纵向上最上层基类构造函数，如果横向继承了多个类，调用顺序为派生表从左到右顺序。

3. 如果该对象需要虚函数指针(vptr)，则该指针会被设置从而指向对应的虚函数表(vtbl)。

4. 成员类对象的构造函数：如果类的变量中包含其他类（类的组合），需要在调用本类构造函数前先调用成员类对象的构造函数，调用顺序遵照在类中被声明的顺序。

5. 派生类的构造函数。

6. 析构函数与之相反。



#### 构造函数和析构函数的调用时机？

- **全局范围中的对象**

  构造函数在所有函数调用之前执行，在主函数 `main()` 执行完调用析构函数。

- **局部自动对象**

  建立对象时调用构造函数，离开作用域时调用析构函数。

- **动态分配的对象**

  建立对象 `new` 时调用构造函数，调用释放 `delete` 时调用析构函数。

- **静态局部变量对象**

  建立时调用一次构造函数，主函数结束时调用析构函数。







#### 深拷贝和浅拷贝的区别？

**浅拷贝：**

- 浅拷贝只是拷贝一个指针，并没有新开辟一个空间，拷贝的指针和原来的指针指向同一块地址。
- 如果原来的指针所指向的资源释放了，那么再释放浅拷贝的指针资源就会出现错误。
- 如果原地址中对象被改变了，那么浅拷贝出来的对象也会相应的改变。
- 默认的拷贝构造函数和默认的赋值运算符重载函数都是浅拷贝。

**深拷贝：**

- 深拷贝不仅拷贝值，还开辟一块新的空间来存放新的值，即使原先的对象被析构掉，释放内存了也不会影响到深拷贝得到的值。在自己实现拷贝赋值时，如果有指针变量的话是需要自己实现深拷贝的。



#### 拷贝构造函数和赋值运算符重载的区别？

1. 拷贝构造函数是函数，赋值运算符是运算符重载。

2. 拷贝构造函数会生成新的类对象，赋值运算符不能。

3. 拷贝构造函数是直接构造一个新的类对象，所以在初始化对象前不需要检查源对象和新建对象是否相同；赋值运算符需要上述操作并提供两套不同的复制策略，另外赋值运算符中如果原来的对象有内存分配则需要先把内存释放掉。

4. 形参传递是调用拷贝构造函数（调用的被赋值对象的拷贝构造函数），但并不是所有出现"="的地方都是使用赋值运算符。

**注：类中有指针变量时要重写析构函数、拷贝构造函数和赋值运算符**



#### 虚函数和纯虚函数的区别？

- 虚函数是为了实现动态编联产生的，目的是通过基类类型的指针指向不同对象时，自动调用相应的、和基类同名的函数（使用同一种调用形式，既能调用派生类又能调用基类的同名函数）。虚函数需要在基类中加上virtual修饰符修饰，因为virtual会被隐式继承，所以子类中相同函数都是虚函数。当一个成员函数被声明为虚函数之后，其派生类中同名函数自动成为虚函数，在派生类中重新定义此函数时要求函数名、返回值类型、参数个数和类型全部与基类函数相同。

- 纯虚函数只是相当于一个接口名，但含有纯虚函数的类不能够实例化。



#### 覆盖（override）、重载（overload）和隐藏（hide）的区别？

 - **覆盖（override）**

   派生类中**重新定义的函数**，其函数名、参数列表（个数、类型和顺序）、返回值类型和父类完全相同，只有函数体有区别。派生类虽然继承了基类的同名函数，但用派生类对象调用该函数时会根据对象类型调用相应的函数。覆盖只能发生在类的成员函数中。**（完全相同才可，并且基类函数需要定义为虚函数）**

 - **隐藏（hide）**

   **指派生类函数屏蔽了与其同名的函数**，这里仅要求基类和派生类函数同名即可。其他状态同覆盖。可以说隐藏比覆盖涵盖的范围更宽泛，毕竟参数不加限定。**（函数名相同即可，需要调用基类的同名函数需要加上作用域）**

 - **重载（overload）**

   具有相同函数名但参数列表不同（个数、类型或顺序）的两个函数（不关心返回值），当调用函数时根据传递的参数列表来确定具体调用哪个函数。重载可以是同一个类的成员函数也可以是类外函数。**（参数列表不同）**
   





#### C++ 的重载和重写是如何实现的？

1. C++利用命名倾轧（name mangling）技术，来改名函数名，区分参数不同的同名函数。命名倾轧是在编译阶段完成的。
2. 重写：存在虚函数的类都有一个一维的虚函数表叫做虚表，类的对象有一个指向虚表开始的虚指针。虚表是和类对应的，虚表指针是和对象对应的。





#### 虚函数表的实现及内存布局

代码参考：[c++对象模型05：虚继承内存布局](https://blog.csdn.net/effort_study/article/details/119488496)

![](.\image\c++基础\对象内存布局.svg)

1. 虚函数在地址空间中的存放

   ![这里写图片描述](https://img-blog.csdn.net/20180820143644168?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzU5MDIy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

2. 单一继承的虚函数表：（ClassB继承ClassA）

   ![这里写图片描述](https://img-blog.csdn.net/20180820162125485?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzU5MDIy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

3. 多重继承的虚函数表：（ClassC继承ClassB，ClassB继承ClassA）

   ![这里写图片描述](https://img-blog.csdn.net/20180821103628852?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzU5MDIy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

4. 多继承下的虚函数表：（ClassC依次继承ClassA1、ClassA2）

   ![在这里插入图片描述](https://img-blog.csdn.net/20181023164040667?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzU5MDIy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)





#### 什么代码会在main之前执行？

1. 初始化栈指针
2. 初始化 static 静态变量和 global 全局变量，即 data 段的内容
3. 如果全局变量未初始化，如果是内置类型会执行默认初始化（int, bool, 指针等），如果是非内置类型，则会调用默认构造函数进行初始化，即 bss 段的内容
4. 将main函数的参数，argc 和argv 等参数传递给main函数。



> 写一段在main()之前执行的代码

1. 全局变量的构造函数
2. 全局变量的赋值函数

```cpp
#include <iostream>
#include <vector>

using namespace std;

int a = []() {
    cout << "a" << endl;
    return 0;
}();

int main() {
    cout << "b" << endl;

    system("pause");
    return 0;
}
```



#### 在main执行之前和之后执行的代码可能是什么？

**main函数执行之前**，主要就是初始化系统相关资源：

- 设置栈指针
- 初始化静态 `static` 变量和 `global` 全局变量，即 `.data` 段的内容
- 将未初始化部分的全局变量赋初值：数值型 `short`，`int`，`long` 等为 `0`，`bool` 为 `FALSE`，指针为 `NULL` 等等，即 `.bss` 段的内容
- 全局对象初始化，在 `main` 之前调用构造函数，这是可能会执行前的一些代码
- 将main函数的参数 `argc`，`argv` 等传递给 `main` 函数，然后才真正运行 `main` 函数
- `__attribute__((constructor))`

**main函数执行之后**：

- 全局对象的析构函数会在main函数之后执行；
- 可以用 `atexit` 注册一个函数，它会在 main 之后执行;
- `__attribute__((destructor))`





#### 必须使用初始化成员列表的情况？

- 初始化一个 const 成员。

- 初始化一个 reference 成员。

- 调用一个基类的构造函数，而该函数有一组参数。

- 调用一个数据成员对象的构造函数，而该函数有一组参数。

```c++
class A {
    public:
        A(int &v) : i(v), p(v), j(v) {}
        void print_val() { cout << "hello:" << i << "  " << j << endl;}
    private:
        const int i;   //const成员
        int p;
        int &j;        //引用成员
};
```



#### C++ 中实现不能被继承的类

1. 将**构造函数声明为私有**，这样派生类无法调用基类的构造函数进行构造

2. 将自身作为一个已存在类的友元类，利用了**友元不能被继承的特性**。虚基类构造函数的参数必须由最新派生出来的类负责初始化（即使不是直接继承）

   ```cpp
   class Base {
   private:
   	Base(){}
   	friend class A;
   };
   
   class A : virtual public Base {
   public:
   	A(int a) : ma(a) {}
   private:
   	int ma;
   };
   ```

3. c++11中可以使用关键字 **final**



#### 如何让类对象只在栈/堆上分配空间

1. **只能在栈上分配类对象**
   - 将 new 和 delete 运算符重载为私有的。
2. **只能在堆上分配类对象**
   - 将析构函数声明为私有的，如果类的析构函数为私有的，编译器不会在栈空间上为类对象分配内存。



### C++11



#### 说一下 C++11 的新特性（hr建议分类阐述）

1. **新增语法**
   - nullptr
   - auto 自动类型推导（auto声明的变量必须要初始化，不能被声明为返回值，不能作为形参，不能被修饰为模板参数）
   - 范围 for 循环
   - 初始化列表
   - lambda 表达式
2. **智能指针**
   - unique_ptr：遵循独占语义的智能指针，在任何时间点，资源智能唯一地被一个unique_ptr所占有，当其离开作用域时自动析构。资源所有权的转移只能通过 `std::move()` 而不能通过赋值。
   - shared_ptr：基于引用计数的智能指针，会统计当前有多少个对象同时拥有该内部指针；当引用计数降为0时，自动释放。
   - weak_ptr：解决 shared_ptr 循环引用的问题。
3. **库相关**
   - thread库及其相配套的同步原语mutex, lock_guard, condition_variable, 以及异步 std::furture
   - 函数对象和bind绑定器
4. **右值引用和移动语义**
   - 右值引用是C++11新特性，它实现了转移语义和完美转发。
   - 主要作用：（1）消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率（2）能够更简洁明确地定义泛型函数
   - **移动语义**：编译器只对右值引用才能调用移动构造函数，所以需要用户定义自己的移动构造函数，然后调用 `std::move()` 将左值转换为右值
   - **完美转发**：将一组参数原封不动地传递给另一个函数（C++11对T&&的类型推导： 右值实参为右值引用，左值实参仍然为左值），使用 `std::forward()`



#### 说一下三种智能指针的实现原理和使用场景，及其线程安全性（华为一面）

智能指针的作用是管理一个指针，因为存在以下这种情况：申请的空间在函数结束时忘记释放，造成内存泄漏。使用智能指针可以很大程度上的避免这个问题，因为智能指针就是一个类，当超出了类的作用域是，类会自动调用析构函数，析构函数会自动释放资源。所以智能指针的作用原理就是在函数结束时自动释放内存空间，不需要手动释放内存空间。

##### 实现原理

1. **unique_ptr**：将拷贝构造函数和赋值拷贝构造函数申明为private或delete。不允许拷贝构造函数和赋值操作符，但是支持移动构造函数，通过 std:move 把一个对象指针变成右值之后可以移动给另一个 unique_ptr
2. **shared_ptr**：有一个引用计数的指针类型变量，专门用于引用计数，使用拷贝构造函数和赋值拷贝构造函数时，引用计数加1，当引用计数为0时，释放资源。



##### 使用场景

1. 如果程序要使用多个指向同一个对象的指针，应该选择 shared_ptr；
2. 如果程序不需要多个指向同一个对象的指针，则可以使用 unique_ptr; 
3. 如果使用 new [] 分配内存，应该选择 unique_ptr; 
4. 如果函数使用 new 分配内存，并返回指向该内存的指针，将其返回类型声明为 unique_ptr 是不错的选择。



##### 线程安全性

**shared_ptr 本身是线程安全的，但是其指向对象的线程安全，需要由用户自己保证。**

shared_ptr 智能指针的引用计数在手段上使用了 atomic 原子操作，只要 shared_ptr 在拷贝或赋值时增加引用，析构时减少引用就可以了。首先原子操作是线程安全的，所有 shared_ptr 智能指针在多线程下引用计数也是安全的，也就是说 shared_ptr 智能指针在多线程下传递使用时引用计数是不会有线程安全问题的。 但是指向对象的指针不是线程安全的，使用 shared_ptr 智能指针访问资源不是线程安全的，需要手动加锁解锁。智能指针的拷贝也不是线程安全的。



##### 用 new 和 make_shared 初始化智能指针有什么不一样？

```cpp
A* a = new A;
std::shared_ptr<A> pa1(a);  //①

std::shared_ptr<A> pa2 = std::make_shared<A>(1);  //②
```

1. 对于 `new` 来说，会在堆上分配两次内存，一次是在堆上分配内存给需要建立的对象，另一次是创建共享指针时，在堆上为引用计数分配内存，会造成内存碎片化。
2. 对于 `std::make_shared` 来说，会直接在堆上分配一段大的内存，一部分分配给需要建立的对象，一部分分配给引用计数。





#### 说一下 STL 中有哪些常见的容器（字节）

1. STL 中的容器分为顺序容器、关联式容器、容器适配器三种类型。
2. **顺序容器**：容器并非排序的，元素插入位置与元素的值无关，主要包括 vector、 deque 、 list。
   - vector：动态数组，元素在内存中连续存放。随机存储任何元素都能在常数时间完成。尾端增删元素具有较好的性能。
   - deque：双向队列，元素在内存中连续存放。随机存取任何元素都能在常数时间完成。在两段增删元素具有较佳的性能。
   - list：双向链表，元素在内存中不连续存放。在任何位置增删元素都能在常数时间完成。不支持随机存取。
3. **关联式容器**：元素排序的，插入任何元素都按照相应的规则来确定其位置。在查找时有较好的性能，主要包括set、map
   - set：根据 value 来对元素进行排序
   - map：根据键值进行排序
4. **容器适配器**：封装了一些基本的容器，使之具备了新的函数功能，在实例化时可以自行选择底层实现的容器。包括stack、queue、priority_queue。
   - stack：栈中删除、检索和修改的项只能是最近插入序列的项，后进后出。
   - queue：队列，插入只可以在尾部进行，删除、检索和修改只允许从头部进行，先进先出。
   - priority_queue：优先队列，内部维持某种有序，确保优先级最高的元素总是位于头部，最高优先级元素总是第一个出列。



#### STL 容器用过哪些，查找的时间复杂度是多少，为什么？

vector、deque、list、map、set、multimap、multiset、unordered_map、unordered_set等。容器底层实现方式及时间复杂度分别如下：

1. ***vector***

   采用一维数组实现，元素在内存连续存放，不同操作的时间复杂度为：

   插入: O(N)

   查看: O(1)

   删除: O(N)

2. ***deque***

   采用双向队列实现，元素在内存连续存放，不同操作的时间复杂度为：

   插入: O(N)

   查看: O(1)

   删除: O(N)

3. ***list***

   采用双向链表实现，元素存放在堆中，不同操作的时间复杂度为：

   插入: O(1)

   查看: O(N)

   删除: O(1)

4. ***map、set、multimap、multiset***

   上述四种容器采用红黑树实现，红黑树是平衡二叉树的一种。不同操作的时间复杂度近似为:

   插入: O(logN)

   查看: O(logN)

   删除: O(logN)

5. ***unordered_map、unordered_set、unordered_multimap、 unordered_multiset***

   上述四种容器采用哈希表实现，不同操作的时间复杂度为（与哈希函数有关）：

   插入: O(1)，最坏情况O(N)

   查看: O(1)，最坏情况O(N)

   删除: O(1)，最坏情况O(N)

   **注意：**容器的时间复杂度取决于其底层实现方式。



#### set 和 unordered_set 存储自定义数据类型，应该怎么做？

注意：

- `set` 的底层是红黑树，只要定义了比较规则就能知道存放的位置。但是 `unordered_set` 的底层是哈希表，对于自定义的数据类型来说，需要自定义哈希函数。
- 自定比较规则接受的是 `function` 对象，所以要按照构造 `function` 的形式传入参数。



> set

自定义排序规则

1. 定义一个类，重载()，或者 大于，小于运算符
2. 自定义比较函数，需要传入函数指针，或者使用 `std::function<>`
3. lambda 表达式



> unordered_set

自定义哈希函数

1. 自定义对象
2. 重载opeartor()
3. lambda表达式





#### 说说 STL 容器动态链接可能产生的问题？

向动态库函数传入容器的引用时，如果在动态库里面对容器插入了一些元素，那么这些内存分配的代码是属于dll的，此时从dll返回后再进行容器的释放，程序会崩溃，因为程序不知道dll中插入元素的内存在哪。



#### 迭代器相关

##### 和指针的区别

1. **迭代器的作用**

   （1）用于指向顺序容器和关联容器中的元素

   （2）通过迭代器可以读取它指向的元素

   （3）通过非const迭代器还可以修改其指向的元素

   （4）STL 的容器和算法之间通过迭代器进行交互

2. **迭代器和指针的区别**

   **迭代器不是指针，是类模板，表现的像指针。**他只是模拟了指针的一些功能，重载了指针的一些操作符，->、++、-- 等。迭代器封装了指针，是一个”可遍历STL（ Standard Template Library）容器内全部或部分元素”的对象，**本质**是封装了原生指针，是指针概念的一种提升，提供了比指针更高级的行为，相当于一种智能指针，他可以根据不同类型的数据结构来实现不同的++，--等操作。

   **迭代器返回的是对象引用而不是对象的值**，所以cout只能输出迭代器使用取值后的值而不能直接输出其自身。

3. **迭代器产生的原因**

   Iterator类的访问方式就是把不同集合类的访问逻辑抽象出来，使得不用暴露集合内部的结构而达到循环遍历集合的效果。



##### 迭代器什么情况下会失效

1. 对于**顺序容器** vector，deque 来说，使用 erase 后，后边的每个元素的迭代器都会失效，**后边每个元素都往前移动一位**，erase 返回下一个有效的迭代器。
   - `push_back` 和 `insert` ：对于 `push_back` 来说，`end()` 肯定会失效。如果因为插入导致了扩容，那么会导致所有元素的迭代器失效。
   - `insert` 和 `erase` ：会导致插入/删除位置后面的所有元素都失效。
2. 对于**关联式容器**map，set来说，使用了erase后，当前元素的迭代器失效，但是其结构是红黑树，删除当前元素，不会影响下一个元素的迭代器，所以在调用erase之前，记录下一个元素的迭代器即可。
3. 对于 list 来说，它使用了不连续分配的内存，并且它的erase方法也会返回下一个有效的迭代器，因此上面两种方法都可以使用。



#### push_back 和 emplace_back 的区别

1. **接受的参数类型不同**：`push_back(const T&)` 或 `push_back(T&&)` ，参数为常量左值或者右值引用；而 `emplace_back(Args&&... args)` 接受的是参数包（右值引用形式的）。

2. **vector中构造对象的形式不同**：二者传入参数的不同导致了在底层调用 `allocator::construct` 时传入的参数也不同，对于传入的对象，`allocator` 会调用拷贝构造函数或者移动构造函数，而对于传入的参数，`allocator` 会选择在内存中直接构造对象，避免了一次拷贝/构造的过程。

   ```cpp
   // emplace_back()
   // void emplace_back(Args&&... args);
   _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                                    std::forward<_Args>(__args)...); 
   // push_back()
   // void push_back(const T& value)
   // void push_back(T&& value)
   _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                                    __x);
   ```

3. 由此导致 `push_back` 的效率低于 `emplace_back`





#### map 和 unordered_map 的区别

1. 头文件不同
2. 底层数组结构不同，map的底层实现是红黑树，这个数据结构具有自动排序功能，所以 map 内部的所有元素都是有序的；而 unordered_map 的底层实现的哈希表，其内部元素的排列顺序是杂乱无序的。



#### 红黑树的特性？为什么要有红黑树？

虽然平衡树解决了二叉查找树退化为近似链表的缺点，能够把查找时间控制在 O(logn)，不过却不是最佳的，因为平衡树要求每个节点的左子树和右子树的高度差至多等于 1，导致每次进行插入/删除节点的时候，都需要通过左旋和右旋来进行调整，使之再次成为一颗符合要求的平衡树。显然，如果在那种插入、删除很频繁的场景中，平衡树需要频繁着进行调整，这会使平衡树的性能大打折扣，为了解决这个问题，于是有了红黑树，红黑树具有如下特点：

1. 具备二叉查找树的特点；
2. 根节点是黑色的；
3. 每个叶子节点都是黑色的空节点，也就是说叶子节点不存数据；（叶子节点是为空的叶子节点）
4. 如果一个节点是红色的，则它的子节点必须是黑色的。
5. 每个节点，从该节点到达其可达的叶子节点，都包含相同数目的黑色节点；



> 红黑树（RBT）和平衡树（AVL）的区别？

1. RBT的是近似平衡的二叉搜索树，就是RBT的左右子树的高度差不会严格小于1，只是保证没有一条路径会比其他路径长出俩倍。但是AVL是严格平衡的，左右子树的高度差保证严格小于1。
2. RBT节点的增加和删除，由于不要求严格平衡，所以可以通过改变节点的颜色来减少节点的旋转次数，在插入和删除效率上会比AVL高。
3. 由于不要求严格平衡，所以RBT的搜索效率会略低于RBT
4. RBT和AVL都是二叉查找树





#### 说一下 unordered_map 的实现原理（腾讯）

unordered_map 容器和 map 容器一样，以键值对（pair类型）的形式存储数据，存储的各个键值对的键互不相同且不允许被修改。但由于 unordered_map 容器底层采用的是哈希表存储结构，该结构本身不具有对数据的排序功能，所以此容器内部不会自行对存储的键值对进行排序。底层采用哈希表实现无序容器时，会将所有数据存储到一整块连续的内存空间中，并且当数据存储位置发生冲突时，解决方法选用的是“链地址法”（又称“开链法”）。这个连续空间存储的不是键值对，而是各个链表的头指针。

1. 将该键值对中键的值带入设计好的哈希函数，会得到一个哈希值（一个整数，用 H 表示）；
2. 将 H 和无序容器拥有桶的数量 n 做整除运算（即 H % n），该结果即表示应将此键值对存储到的桶的编号；
3. 建立一个新节点存储此键值对，同时将该节点链接到相应编号的桶上。



#### 类模板是在什么时候实例化的？

1. **模板实例化**：模板的实例化分为显示实例化和隐式实例化，前者是研发人员明确的告诉模板应该使用什么样的类型去生成具体的类或函数，后者是在编译的过程中由编译器来决定使用什么类型来实例化一个模板不管是显示实例化或隐式实例化，最终生成的类或函数完全是按照模板的定义来实现的。
2. **模板具体化**：当模板使用某种类型类型实例化后生成的类或函数不能满足需要时，可以考虑对模板进行具体化。具体化时可以修改原模板的定义，当使用该类型时，按照具体化后的定义实现，具体化相当于对某种类型进行特殊处理。



#### 右值引用相关



##### 说一下移动构造函数，什么库用到了这个函数？

C++11中新增了移动构造函数。与拷贝类似，移动也使用一个对象的值设置另一个对象的值。但是，又与拷贝不同的是，移动实现的是对象值真实的转移（源对象到目的对象）：源对象将丢失其内容，其内容将被目的对象占有。移动操作的发生的时候，是当移动值的对象是**未命名的对象**的时候。这里未命名的对象就是那些临时变量，甚至都不会有名称。典型的未命名对象就是函数的返回值或者类型转换的对象。使用临时对象的值初始化另一个对象值，不会要求对对象的复制：因为临时对象不会有其它使用，因而，它的值可以被移动到目的对象。做到这些，就要使用移动构造函数和移动赋值：当使用一个临时变量对对象进行构造初始化的时候，调用移动构造函数。类似的，使用未命名的变量的值赋给一个对象时，调用移动赋值操作。



##### 说一下拷贝赋值和移动赋值的区别？

1. 拷贝赋值调用的拷贝构造函数，移动赋值调用的是移动构造函数
2. 拷贝构造函数的形参是一个左值引用，而移动构造函数的形参是一个右值引用
3. 拷贝构造函数完成的是整个对象或变量的深拷贝，而移动构造函数只是简单地把右值引用的资源浅拷贝给需要建立的对象，然后将右值引用对象的资源赋空。



##### 左值/右值、左值引用/右值引用？

- **左值引用**，就是绑定到左值的引用。
- **左值**，就是在内存有确定存储地址、有变量名，赋值表达式结束依然存在的值。
- **右值引用**，本质上是将引用的右值内容存储到空间中，该右值引用变量具有名称和地址，所以右值引用变量是一个左值。
- **右值**，就是在内存没有确定存储地址、没有变量名的值。c++11中的右值分为纯右值和将亡值两种。
  1. 纯右值：字面常量或者是一个不具名的临时对象，比如一个数，一个字符常量
  2. 将亡值：生命周期即将结束的变量，通常用于移动构造或移动赋值。

使用左值去初始化对象或为对象赋值时，会调用拷贝构造函数或赋值构造函数。

而使用一个右值来初始化或赋值时，会调用移动构造函数或移动赋值运算符来移动资源，从而避免拷贝，提高效率。



*引用类型与可以引用的值类型的对应关系*

| 引用类型       | 非常量左值 | 常量左值 | 非常量右值 | 常量右值 | 使用场景                   |
| -------------- | ---------- | -------- | ---------- | -------- | -------------------------- |
| 非常量左值引用 | Y          | N        | N          | N        | 无                         |
| 常量左值引用   | Y          | Y        | Y          | Y        | 常用于类中构建拷贝构造函数 |
| 非常量右值引用 | N          | N        | Y          | N        | 移动语义、完美转发         |
| 常量右值引用   | N          | N        | Y          | Y        | 无实际用途                 |

> 右值引用和左值引用的区别

（1）左值引用绑定到有确定存储空间以及变量名的对象上，表达式结束后对象依然存在；右值引用绑定到要求转换的表达式、字面常量、返回右值的表达式等临时对象上，赋值表达式结束后就对象就会被销毁。
（2）左值引用后可以利用别名修改左值对象；右值引用绑定的值不能修改。



> 右值引用的作用

1. 实现移动语义和完美转发
1. 让编译器能够正确按照左值和右值去调用对应的构造函数或者赋值运算符，传入的右值优先调用移动构造函数和移动赋值运算符。在移动构造函数中进行对象的浅拷贝，并将临时对象的资源置空，从而直接使用临时对象。
2. 实现可以移动但不能拷贝的类对象，这种情况是在拷贝构造函数和拷贝赋值运算中加入delete关键字，并定义自己的移动构造函数和移动赋值运算符。



#### 解释下 C++ 中类模板和模板类的区别

1. 类模板是模板的定义，不是一个实实在在的类，定义中用到通用类型参数
2. 模板类是实实在在的类定义，是类模板的实例化。类定义中参数被实际类型所代替。
3. 



#### 正则表达式

正则表达式实质上是一个字符串，该字符串描述了一种特定模式的字符串。常用符号的意义如下：

| 符号  | 意义                           |
| ----- | ------------------------------ |
| ^     | 匹配行的开头                   |
| $     | 匹配行的结尾                   |
| .     | 匹配任意单个字符               |
| […]   | 匹配[]中的任意一个字符         |
| (…)   | 设定分组                       |
| \     | 转义字符                       |
| \d    | 匹配数字[0-9]                  |
| \D    | \d 取反                        |
| \w    | 匹配字母[a-z]，数字，下划线    |
| \W    | \w 取反                        |
| \s    | 匹配空格                       |
| \S    | \s 取反                        |
| +     | 前面的元素重复1次或多次        |
| *     | 前面的元素重复任意次           |
| ?     | 前面的元素重复0次或1次         |
| {n}   | 前面的元素重复n次              |
| {n,}  | 前面的元素重复至少n次          |
| {n,m} | 前面的元素重复至少n次，至多m次 |
| \|    | 逻辑或                         |



#### lambda 表达式

```c++
[capture list] (params list) mutable exception-> return type {function body}

```

1. captrue list：捕获外部变量列表（必须）

2. params list：形参列表

3. mutable 指示符：用来说明是否可以修改捕获的变量

4. exception：异常设定

5. return type：返回类型（可省略）

   （1）：如果function body中存在return语句，则该Lambda表达式的返回类型由return语句的返回类型确定；
   （2）：如果function body中没有return语句，则返回值为void类型。

6. function body：函数体



##### lambda 表达式的捕获方式有哪些？

Lambda表达式可以使用其可见范围内的外部变量，但必须明确声明（明确声明哪些外部变量可以被该Lambda表达式使用）。

主要有值捕获、引用捕获和隐式捕获三种。

- **值捕获**：对该变量的修改不会影响影响Lambda表达式中的值。并且不可修改传入的值（如果真的要修改，需要加上 mutable 关键字）。值捕获传入的是创建 lambda 表达式时的值。
- **隐式捕获**：让编译器根据函数体中的代码来推断需要捕获哪些变量。

| 捕获形式    | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| []          | 不捕获任何外部变量                                           |
| [变量名, …] | 默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符） |
| [this]      | 以值的形式捕获this指针                                       |
| [=]         | 以值的形式捕获所有外部变量                                   |
| [&]         | 以引用形式捕获所有外部变量                                   |
| [=, &x]     | 变量x以引用形式捕获，其余变量以传值形式捕获                  |
| [&, x]      | 变量x以值的形式捕获，其余变量以引用形式捕获                  |



#### 说一下 RVO 和 NRVO 机制？

RVO 是返回值优化，就是在一个函数内部返回一个匿名对象时，由编译器对这个返回过程进行优化，直接将匿名对象作为返回值，避免函数返回过程中调用拷贝构造函数的开销。

NRVO 是具名返回值优化，函数返回值是一个在函数内部构建的有名对象，同样由编译器对这个返回过程进行优化，直接将有名作为返回值，避免函数返回过程中调用拷贝构造函数的开销。

这两个机制用于返回值是结构体或者类。



#### 介绍一下 auto 关键字

auto 是自动类型推断，用于从初始化表达式中推断出变量的数据类型，这个推导的工作由编译器完成。

注意点：

1. auto不能自动推导成constant 或者 volatile，会覆盖顶层的引用和修饰，除非被声明为引用类型
2. auto会退化成指向数组的指针，除非被声明为引用
3. 如果需要保留顶层的引用和修饰，需要声明为 auto 引用或者使用 decltype



### 编译及调试



#### 编译流程

从 `gcc hello.c` 到 `./a.out` 之间发生什么？

这个过程有四个步骤：

- [ ] 预处理 -> 编译 -> 汇编 -> 链接

<img src="https://pic3.zhimg.com/80/v2-2797ea99d0d38eb9996993bb0ad77ab2_720w.jpg" alt="img" style="zoom:;" />

现在 GCC 把预编译和编译都合在一起了。但是也可以分开实现，GCC的命令其实是对一些编译程序的包装而已，它根据不同的参数去调用预编译程序（cc1）、汇编器（as）、链接器（ld）。



##### 预处理(Preprocessing)

预处理用于将所有的 `#include` **头文件以及宏定义替换成其真正的内容**，预处理之后得到的仍然是文本文件，但文件体积会大很多。gcc 的预处理是**预处理器cpp来完成的**，你可以通过如下命令对 `test.c` 进行预处理：

```bash
$ gcc -E hello.c -o hello.i
# 或者
$ cpp hello.c -> hello.i
```

**预处理的规则：**

1. 展开所有的宏定义，完成字符常量替换。
2. 处理条件编译语句，通过是否具有某个宏来决定过滤掉哪些代码。

3. 处理#include指令，将被包含的文件插入到该指令所在位置。

4. 过滤掉所有注释语句。

5. 添加行号和文件名标识。

6. 保留所有#pragma编译器指令。

**当无法判断宏定义是否正确或头文件包含是否正确时，可以查看预编译后的文件来确定问题。**



##### 编译(Compilation)

编译不是指程序从源文件到二进制程序的全部过程，而是指将经过预处理之后的程序转换成特定**汇编代码(assembly code)** 的过程。

需要在这个过程中完成词法分析、语法分析、语义分析及优化产生的汇编代码。

```bash
$ gcc -S hello.i -o hello.s
```

编译过程完成后，**将生成程序的汇编代码test.s，这也是文本文件**。



##### 汇编(Assemble)

汇编器将上面生成的汇编代码转为机器可以执行的指令。每一条汇编语句对应一条机器指令，这一步产生的文件叫做**目标文件，是二进制格式**。

当然这个目标文件，还需要**重定位**。

```bash
$ gcc -c hello.s -o hello.o
# 或者直接调用汇编器
$ as test.s -o test.o
```

**这一步会为每一个源文件产生一个目标文件**。

```bash
# 查看 obj 文件的主要段
$ objdump -h main.o
```





##### 链接(Linking)

链接过程将**多个目标文件以及所需的库文件(.so等)链接**成最终的**可执行文件**(executable file)。

1. **合并段**

   <img src="https://img-blog.csdn.net/20180722165121542?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L01yX0g5NTI3/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="img" style="zoom: 67%;" />

   将各个文件不同的段合并起来，每个.o文件的.text段合并在一起.data段合并在一起，这样，在生成的可执行 文件中，各个段都只有一个，由于在链接时只需要加载代码段(.text段)和数据段（.data段和.bss段）。因此合并段之后，在系统给我们分配内存时，只需要分配两个页面大小就可以，分别存放代码和数据如图

2. **调整段偏移**

   合并段之后，必须进行的一个操作就是调整段偏移和段长度。每个进程都有自己的虚拟地址空间，都是从0地址开始的，将各个文件的各个段加载进来之后，段的大小会有所变化，相对于0地址的偏移量也会不同，因此我们需要调整段偏移和段偏移

3. **汇总所有符号**

   每个 obj 文件在编译时都会生成自己的符号表，要把这些符号都合并起来进行符号解析

4. **完成符号的重定位**

   在进行合并段，调整段偏移时，输入文件的各个段在连接后的虚拟地址就已经确定了，这一步完成后，连接器开始计算各个符号的虚拟地址，因为各个符号在段内的相对位置是固定的，所以段内各个符号的地址也已经是确定的了，只不过连接器需要给每个符号加上一个偏移量，使他们能够调整到正确的虚拟地址，这就是符号的重定位过程

   在 elf 文件中，有一个叫**重定位表**的结构专门用来保存这些与从定位有关的信息，重定位表在elf文件中往往是一个或多个段



##### 动态/静态库的建立

- **静态链接**

<img src="https://img-blog.csdnimg.cn/img_convert/b6c466a08f8ea6a626a1a2087816edd6.png" alt="img" style="zoom: 80%;" />

静态链接最简单的情况就是在编译时和静态库链接在一起成为完整的可执行程序。这里所说的静态库就是对多个目标文件（.o）文件的打包，通常静态链接的包名为lib\*\*\*\*.a，静态链接所有被用到的目标文件都会复制到最终生成的可执行目标文件中。这种方式的好处是在运行时，可执行目标文件已经完全装载完毕，只要按指令序执行即可，速度比较快。

```bash
$ gcc -c test1.c    # 生成test1.o
$ gcc -c test2.c    # 生成test2.o
$ ar cr libtest.a test1.o test2.o  # 生成静态库
```

首先编译得到test1.o和test2.o两个目标文件，之后通过ar命令将这两个文件打包为.a文件，文件名格式为lib + 静态库名 + .a后缀。在生成可执行文件需要使用到它的时候只需要在编译时加上即可。需要注意的是，使用静态库时加在最后的名字不是libtest.a，而是l + 静态库名。

```bash
$ gcc -o main main.c -ltest
```

- **动态链接**

<img src="https://img-blog.csdnimg.cn/img_convert/040d3b4dd5b5dbe0db05e33fefae7dd5.png" alt="img" style="zoom:80%;" />

静态链接发生于编译阶段，加载至内存前已经完整，但缺点是如果**多个程序**都需要使用某个静态库，则该静态库会在每个程序中都拷贝一份，非常浪费内存资源，所以出现了动态链接的方式来解决这个问题。

动态链接在形式上倒是和静态链接非常相似，首先也是需要打包，打包成动态库，不过文件名格式为lib + 动态库名 + .so后缀。不过动态库的打包不需要使用ar命令，gcc就可以完成，但要注意在编译时要加上-fPIC 选项，打包时加上-shared选项。

```bash
$ gcc -fPIC -c test1.c # -fPIC:生成位置无关的代码
$ gcc -fPIC -c test2.c
$ gcc -shared test1.o test2.o -o libtest.so  # 生成动态库
```

- **动态链接和静态链接的比较**

1. 动态库运行时会先检查内存中是否已经有该库的拷贝，若有则共享拷贝，否则重新加载动态库（C语言的标准库就是动态库）。静态库则是每次在编译阶段都将静态库文件打包进去，当某个库被多次引用到时，内存中会有多份副本，浪费资源。
2. 动态库另一个有点就是**更新很容易**，当库发生变化时，如果接口没变只需要用新的动态库替换掉就可以了。但是如果是静态库的话就需要重新被编译。

3. 不过静态库也有优点，主要就是静态库一次性完成了所有内容的绑定，运行时就不必再去考虑链接的问题了，执行效率会稍微高一些。



##### 动态库与静态库的区别

1. 静态库代码装载的速度快，执行速度略比动态库快。
2. 动态库更加节省内存，可执行文件体积比静态库小很多。
3. 静态库是在编译时加载，动态库是在运行时加载。
4. 生成的静态链接库，Windows下以.lib为后缀，Linux下以.a为后缀。生成的动态链接库，Windows下以.dll为后缀，Linux下以.so为后缀。



##### 静态链接和动态链接的区别？应用场景？

1. **静态链接**
   - **特点**：在生成可执行文件的时候(链接阶段)，把所有需要的函数的二进制代码都包含到可执行文件中去。因此，链接器需要知道参与链接的目标文件需要哪些函数，同时也要知道每个目标文件都能提供什么函数，这样链接器才能知道是不是每个目标文件所需要的函数都能正确地链接。如果某个目标文件需要的函数在参与链接的目标文件中找不到的话，链接器就报错了。目标文件中有两个重要的接口来提供这些信息：一个是符号表，另外一个是重定位表。
   - **优点**：在程序发布的时候就**不需要的依赖库**，也就是不再需要带着库一块发布，程序可以独立执行。
   - **缺点**：程序体积会相对大一些；如果静态库有更新的话，所有可执行文件都得**重新链接**才能用上新的静态库。
2. **动态链接**
   - **特点：** 在编译的时候不直接拷贝可执行代码，而是通过记录一系列符号和参数，在程序运行或加载时将这些信息传递给操作系统，操作系统负责将需要的动态库加载到内存中，然后程序在运行到指定的代码时，去共享执行内存中已经加载的动态库可执行代码，最终达到运行时连接的目的。
   - **优点：** 多个程序可以共享同一段代码，而不需要在磁盘上存储多个拷贝。
   - **缺点：** 由于是运行时加载，可能会影响程序的前期执行性能。
3. **应用场景**
   - 当该当链接库还需要链接其它的链接库，包括静态或者动态链接库的场合，应该使用动态链接库。
   - 在库文件需要频繁更新时，考虑使用动态链接，可以避免更新时的重新链接
   - 动态链接库.dll可以链接到不同编程语言的工程，所以对于多语言的软件开发的场合可以考虑动态链接。
   - 在考虑运行速度的小型应用中，应该使用静态链接。



#### 调试流程

##### 有哪些引起程序崩溃的原因？如何定位？

> 引起程序崩溃的原因

1. 数组越界
2. 访问非法指针（野指针，或者在用户空间访问了内核空间的指针）
3. 堆栈溢出
4. 除数为0

**定位的话使用gdb调试即可**



##### 简述 GDB 常见的调试命令，什么是条件断点，多进程下如何调试？

**GDB调试**：gdb调试的是可执行文件，在gcc编译时加入 -g ，告诉gcc在编译时加入调试信息，这样gdb才能调试这个被编译的文件 gcc -g tesst.c -o test

**GDB命令格式：**

1. quit：退出gdb，结束调试

2. list：查看程序源代码

   list 5，10：显示5到10行的代码

   list test.c:5, 10: 显示源文件5到10行的代码，在调试多个文件时使用

   list get_sum: 显示get_sum函数周围的代码

   list test.c get_sum: 显示源文件get_sum函数周围的代码，在调试多个文件时使用

3. reverse-search：字符串用来从当前行向前查找第一个匹配的字符串

4. run：程序开始执行

5. help list/all：查看帮助信息

6. break：设置断点

   break 7：在第七行设置断点

   break get_sum：以函数名设置断点

   break 行号或者函数名 if 条件：以条件表达式设置断点

7. watch 条件表达式：条件表达式发生改变时程序就会停下来

8. next：继续执行下一条语句 ，会把函数当作一条语句执行

9. step：继续执行下一条语句，会跟踪进入函数，一次一条的执行函数内的代码

**条件断点：**break if 条件 以条件表达式设置断点

**多进程下如何调试：**

- 用set follow-fork-mode child 调试子进程
- 或者set follow-fork-mode parent 调试父进程



##### 说一下如何使用gdb调试段错误？

1. 在编译过程中，需要加入 `-g` 选项，来加入 gdb 调试的功能
2. 使用 gdb 来运行发生段错误的程序
3. 进入 gdb 调试界面后，输入 `run` 命令运行
4. 段错误一般都是操作系统发出了 `SIGSEGV` 信号，导致程序中断
5. 使用 `backtrace` 命令查看程序的函数调用栈
6. 定位出现问题的堆栈帧，使用 `frame x` 命令切换到指定的堆栈帧 x，查看具体的代码，使用 `print` 命令查看具体参数是否存在问题。
7. 为发生段错误的前面代码添加断点，从断点开始使用 `next` 命令单步执行，最终定位段错误的问题区域。



#### 执行过程

##### 创建子进程

<img src="https://pic1.zhimg.com/80/v2-8bc2eb74785e0486e6c67482030243d0_720w.jpg" alt="img"  />

当通过 shell 执行 C++ 可执行程序后，系统会拷贝当前进程空间的内容，创建子进程空间。然后会清空子进程的空间（包括原动态库、数据段、代码段以及堆栈），只保留环境变量部分。之后内核可以调用 loader() 程序将可执行文件内容加载到子进程内存空间。

##### 加载可执行程序

loader 的作用是将可执行程序内容移动到虚拟内存相应地址当中。loader 根据每一个部分(section) 的读写属性将其归入不同的段（segment）内，然后将各个段加载到虚拟内存中。

用 readelf --segments regularBuild 命令可以查看可执行程序 regularBuild的各个段的组成。可见，该程序由九个段组成，其中类型为 LOAD的段是运行时需要加载的段。权限为RE（可读可执行）的 LOAD 段为程序的代码段，权限为 RW (可读可写) 的 LOAD 段为程序的数据段。

loader 会根据 INTERP 段的内容加载动态链接库。若要完全避免动态链接（包括C++ 标准库）过程，可以用 -static关键字编译： g++ -static main.c -o staticBuild 。

loader 通过可执行程序的头部信息获得各个段的长度和虚拟地址，将其赋值到一系列结构体对象中，再根据这些信息和内存管理单元（MMU）将各个段加载到物理内存中。

##### main() 函数的执行

当然 `main()` 执行之前还需要进行其他操作。



### 经典面试题

#### 链接时含有多个重名函数会报错吗？

- [ ] 分两点回答：直接链接 + 以库的形式链接

1. **直接链接**

   ```bash
   gcc -c ./test1.c
   gcc -c ./test2.c
   gcc -o main ./test1.o ./test2.o ./main.c
   ```

   将包含同名函数的目标文件进行链接，如果其在同一个命名空间中，会报 `multiple definition` 错误。

2. **以库的形式链接**

   ```bash
   g++ -c ./test1.c
   g++ -c ./test2.c
   ar crv libtest1.a test1.o # 创建静态库
   ar crv libtest2.a test2.o # 创建静态库
   gcc -L. ./main.c -ltest1 -ltest2 -o main
   ```

   - **静态链接**

     1. 编译器根据链接先后顺序，依次查找链接库。
     2. 首先查找`libtest1.a`，发现其有main函数需要的函数`void test()`，因此将其进行了链接。
     3. 再扫描到`libtest2.a`的时候，由于`void test()`已经被`libtest1.a`中的符号提供，因此不再链接。
   - **动态链接**
   
     1. 在动态链接时，不同的链接库可以有同名函数，不影响编译。这是由动态链接库的性质决定的，其只有在运行时才会动态加载，并且加载的顺序是由编译时链接的顺序决定的。
   



#### 头文件相互引用会发生什么？如何解决？写一个判断文件相互引用的程序

在一个头文件内引用定义在另一个头文件内的类。需要在使用这个类之前加入这个类的声明。

判断的话，可以先根据头文件的有引用情况建议一个文件引用的图，然后对文件引用图进行拓扑排序，判断图中是否有环，有环则代表存在相互引用。



#### 什么是哈希冲突？如何解决？

哈希是通过对数据进行再压缩，提高效率的一种解决方法。但由于通过哈希函数产生的哈希值是有限的，而数据可能比较多，导致经过哈希函数处理后仍然有不同的数据对应相同的哈希值。这时候就产生了哈希冲突。

> 解决方法

1. 开放地址法：在发生哈希冲突时，通过一定的探测技术来找到下一个不发生哈希冲突的位置。常见的探测方法有线性探测、再平方探测还有伪随机探测，在原有哈希值的基础上加上探测方法得到的偏移量。
2. 链式地址法：对于相同的哈希值，使用链表进行连接。使用数组存储每一个链表。
3. 建立公共溢出区：建立公共溢出区存储所有哈希冲突的数据。
4. 再哈希法：对于冲突的哈希值再次进行哈希处理，直至没有哈希冲突。









## 现场手撕题

### 运算符重载

#### 赋值运算符重载（类）

例题：如下为类 `CMyString` 的声明，请为该类添加赋值运算符函数：

**注意的点**：

1. 返回值 `string&` 
2. 参数 `const string&` 
3. 判断自赋值

```c++
class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    CMyString& operator= (const CMyString& str);
    ~CMyString();

private:
    char* pData_;
};

// 一般解法（在new抛出异常时，执行赋值的对象也被改变了）
CMyString& CMyString::operator= (const CMyString& str) {
    if(this == &str)
        return *this;
    
    delete[] pData_;
    pData = nullptr;
    pData = new char[strlen(str.pData_) + 1];
    
    // 如果 char*不是字符串，则里面可能存在'\0'，可以考虑使用memcpy()
    strcpy(pData_, str.pData_);
    
    return *this;
}

// 考虑异常安全性
CMyString& CMyString::operator= (const CMyString& str) {
    if(this == &str)
        return *this;

    // 构造函数里面使用new，可能会抛出异常，导致返回的实例状态不确定
    CMyString temp(str);

    // 构造成功，再交换
    char* pTemp = temp.pData_;
    temp.pData_ = pData_;
    pData_ = pTemp;

    return *this;
}
```



#### 前置++与后置++

为了区分前后置，重载函数是以参数类型来区分，在调用的时候，编译器会给 int 指定一个0

```c++
// 前置++
self &operator++() {
    node = (linktype)((node).next);
    return *this;
}

// 后置++
const selt operator++(int) {
    selt temp = *this;
    ++*this;
    return temp;
}
```

**一些问题：**

**1、为什么后置返回对象，而不是引用**

因为后置为了返回旧值创建了一个临时对象，在函数结束后这个对象就会销毁，不可返回局部变量的引用。

**2、为什么后置前面也要加const**

防止用户使用`i++++`，连续两次调用后置++运算符，使得结果只累加一次，无法产生用户所期望的结果

**3、处理用户的自定义类型**

最好使用前置++，因为不会创建临时对象，不会产生构造和析构所造成的开销



### 实现常用数据结构

#### 实现 string 类

```cpp
class MyString {
public:
    MyString(const char* pData = nullptr);
    MyString(const MyString& str);
    MyString& operator= (const MyString& str);
    ~MyString();

    size_t size() const { return _size; }
    const char* c_str() const { return _pData; }

private:
    char* _pData;
    size_t _size;
};

MyString::MyString(const char* pData) {
    // 空指针也要赋值
    if (pData == nullptr) {
        _size = 0;
        _pData = new char[1];
        *_pData = '\0';
    }
    else {
        _size = strlen(pData);
        _pData = new char[_size + 1];
        strcpy(_pData, pData);
    }
}

MyString::MyString(const MyString& str) {
    _size = str.size();
    _pData = new char[_size + 1];
    strcpy(_pData, str.c_str());
}

MyString::~MyString() {
    delete[] _pData;
    _pData = nullptr;
    _size = 0;
}

MyString& MyString::operator= (const MyString& str) {
    if (this == &str) {  // 检查自赋值 
        return *this;
    }
    delete[] _pData;
    _size = str.size();
    _pData = new char[_size + 1];
    strcpy(_pData, str.c_str());
    return *this;
}
```



# 设计模式

## 单例模式

需要注意的点：

- 全局只有一个实例，`static` 特性，同时禁止用户自己声明并定义实例（将构造函数和赋值运算符设为 `private` ）
- 线程安全
- 用户通过接口获取示例：使用 `static` 类成员函数



### 使用智能指针和锁

- 使用 `mutex` 是为了避免多个线程同时获取单例，造成实例化出两个单例对象。
- 使用智能指针是为了避免将释放单例对象的操作交给用户，容易造成内存泄漏。
- 使用双检锁，因为第一次判断通过后才加锁（如果没有第二次判断的话，第一次判断后，另一线程创建出示例，那么会实例化出两个单例对象）

```c++
class Singleton{
public:
    //typedef std::shared_ptr<Singleton> Ptr;
    using Ptr = std::shared_ptr<Singleton>;
 
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
 
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
 
    static Ptr getInstance(){
        // 双重锁
        if(m_pInstance==nullptr){
            std::lock_guard<std::mutex> lk(m_mutex);
 
            if(m_pInstance == nullptr){
                m_pInstance = std::shared_ptr<Singleton>(new Singleton);
            }
        }
 
        return m_pInstance;
    }
 
private:
    Singleton() {
        std::cout << "constructor called!" << std::endl;
    }
 
private:
    static Ptr m_pInstance;
    static std::mutex m_mutex;
};
 
// initialization static variables out of class
Singleton::Ptr Singleton::m_pInstance = nullptr;
std::mutex Singleton::m_mutex;
```



### 使用局部静态变量（面试就写这个）

函数的静态变量，如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束。从而保证了线程安全。

```c++
class Singleton
{
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
 
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
 
    //返回引用，避免用户对指针使用delete
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
 
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};
```



### 继承单例模式，有哪些需要注意的地方？

**实现要点：**

- 构造函数需要是 `protected`，这样子类才能继承；
- 将基类声明为友元，这样才能调用子类的**私有构造函数**。
- 使用了奇异递归模板模式 CRTP(Curiously recurring template pattern) ，`enable_shared_form_this<T>` 也是用的这个

- 基类实现同前

- 在这里基类的析构函数可以不需要 `virtual` ，因为子类在应用中只会用 `Derived` 类型，保证了析构时和构造时的类型一致

```c++
template<typename T>
class Singleton{
public:
    static T& getInstance(){
        static T instance;
        return instance;
    }
 
    virtual ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
 
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
 
protected:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};
 
/********************************************/
// Example:
// 1.friend class declaration is requiered!
// 2.constructor should be private
 
class DerivedSingle : public Singleton<DerivedSingle>{
    // !!!! attention!!!
    // needs to be friend in order to
    // access the private constructor/destructor
    friend class Singleton<DerivedSingle>;
 
public:
    DerivedSingle(const DerivedSingle&) = delete;
    DerivedSingle& operator =(const DerivedSingle&) = delete;
 
private:
    DerivedSingle() = default;
};
```



## 观察者模式

<img src="https://pic2.zhimg.com/80/v2-0a7ef7d1a328dc37eadefb29e0ea705d_720w.jpg" alt="img"  />

```c++
class NonCopyable{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable& operator=(const NonCopyable &) = delete;
};

template <typename Func>
class Event : NonCopyable{
public:
    Event() = default;
    ~Event() = delete;
    // 注册观察者,支持右值引用
    int Attach(Func && f){
        return Assign(f);
    }
    // 注册观察者,支持左值引用
    int Attach(Func & f){
        return Assign(f);
    }
    // 移除观察者
    void Deatach(int iKey){
        m_mapOberserve.erase(iKey);
    }
    // 通知接口
    template <typename... Args>
    void Notify(Args&&... args){
        for(auto& it : m_mapOberserve)
        {
            it.second(std::forward<Args>(args)...);
        }
    }
private:
    template <typename F>
    int Assign(F && f){
        int k = m_iObersevre++;
        m_mapOberserve.emplace(k, std::forward<F>(f));
        return k;
    }
    
    int m_iObersevre = 0;
    std::map<int,Func> m_mapOberserve;
};
```



> 观察者模式和发布订阅模式的区别？

![img](https://pic2.zhimg.com/80/v2-b6ed65f370a766620718ad4227d5d4e5_720w.jpg)

- 在**观察者模式**里，当发布者发生事件时，会直接（**由自身**）通知所有订阅者。
- 在**发布订阅模式**里，发布者，**并不会直接通知订阅者**，换句话说，发布者和订阅者，彼此互不相识。发布订阅模式通过第三者，也就是在消息队列里面，我们常说的经纪人Broker。



## 工厂模式

### 简单工厂模式

建立一个工厂类，对实现了同一接口的一些类进行实例的创建。简单工厂模式的实质是由一个工厂类根据传入的参数，动态决定应该创建哪一个产品类（这些产品类继承自一个父类或者接口）的实例。

```cpp
#include <iostream>
using namespace std;

// 产品类（抽象类，不能实例化）
class Product {
public:
    Product() {};
    virtual void show() = 0;  // 纯虚函数
};

class productA : public Product {
public:
    productA() {}
    void show() { cout << "product A create !" << endl; }
    ~productA() {}
};

class productB : public Product {
public:
    productB() {}
    void show() { std::cout << "product B create ! " << endl; }
    ~productB() {}
};

class simpleFactory {
public:
    simpleFactory() {}
    Product* product(const string str) {
        if (str == "productA")	return new productA();
        if (str == "productB")	return new productB();
        return nullptr;
    }
};
```



### 抽象工厂模式

⼯⼚模式⽬的就是代码解耦，如果我们不采⽤⼯⼚模式，如果要创建产品 A、B，通常做法采⽤⽤ switch...case语 句，那么想⼀想后期添加更多的产品进来，我们不是要添加更多的 switch...case 吗？这样就很麻烦，⽽且也不符 合设计模式中的开放封闭原则。

 为了进⼀步解耦，在简单⼯⼚的基础上发展出了抽象⼯⼚模式，即连⼯⼚都抽象出来，实现了进⼀步代码解耦。

```cpp
#include <iostream>
using namespace std;

// 产品类（抽象类，不能实例化）
class Product {
public:
    Product() {};
    virtual void show() = 0;  // 纯虚函数
};

class productA : public Product {
public:
    productA() {}
    void show() { cout << "product A create !" << endl; }
    ~productA() {}
};

class productB : public Product {
public:
    productB() {}
    void show() { std::cout << "product B create ! " << endl; }
    ~productB() {}
};

// 抽象工厂
class Factory {
public:
	virtual Product* CreateProduct() = 0;
};

// 工厂类A，只生产A产品
class FactoryA : public Factory {
public:
    Product* createProduct() {
        Product* _product = nullptr;
        _product = new ProductA();
        return _product;
    }
};

// 工厂类B，只生产B产品
class FactoryB : public Factory {
public:
    Product* createProduct() {
        Product* _product = nullptr;
        _product = new ProductB();
        return _product;
    }
};
```



### 模板工厂模式

针对工厂方法模式封装成模板工厂类，那么这样在新增产品时，是不需要新增具体的工厂类，减少了代码的编写量。

```cpp
#include <iostream>
using namespace std;

// 产品类（抽象类，不能实例化）
class Product {
public:
    Product() {};
    virtual void show() = 0;  // 纯虚函数
};

class productA : public Product {
public:
    productA() {}
    void show() { cout << "product A create !" << endl; }
    ~productA() {}
};

class productB : public Product {
public:
    productB() {}
    void show() { std::cout << "product B create ! " << endl; }
    ~productB() {}
};

// 抽象工厂
class Factory {
public:
	virtual Product* CreateProduct() = 0;
};

// 工厂类A，只生产A产品
class FactoryA : public Factory {
public:
    Product* createProduct() {
        Product* _product = nullptr;
        _product = new ProductA();
        return _product;
    }
};

// 抽象模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类
template <typename AbstractProduct_t>
class AbstractFactory {
public:
    virtual AbstractProduct_t* createProduct() = 0;
    virtual ~AbstractFactory() {}
};

// 具体模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类，ConcreteProduct_t 产品具体类
template <typename AbstractProduct_t, typename ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t> {
public:
    AbstractProduct_t* createProduct() {
        return new ConcreteProduct_t();
    }
}
```



## 装饰器模式

装饰器模式（Decorator Pattern）允许向⼀个现有的对象添加新的功能，**同时⼜不改变其结构**。

`装饰类` 和 `被装饰类` 可以独立发展，不会相互耦合，装饰器模式是继承的一个替代模式，装饰器模式可以动态地扩展实现一个类的功能。**可以将装饰器理解为扩展的功能！！！**

这种类型的设计模式属于结构型模式，它是作为现有的类的⼀个包装。

```cpp
#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Car {
public:
	virtual void show() = 0;
};

// 三个实体的汽车类
class Bmw :public Car {
public:
	void show() {
		cout << "这是一辆宝马汽车，配置有：基本配置";
	}
};

class Audi :public Car {
public:
	void show() {
		cout << "这是一辆奥迪汽车，配置有：基本配置";
	}
};

class Benz :public Car {
public:
	void show() {
		cout << "这是一辆奔驰汽车，配置有：基本配置";
	}
};

// 装饰器1 定速巡航
class Decorator01 :public Car {
public:
	Decorator01(Car* p) : pCar(p) {}
	void show() {
		pCar->show();
		cout << "，定速巡航";
	}
private:
	Car* pCar;
};

// 装饰器2 自动刹车
class Decorator02 :public Car {
public:
	Decorator02(Car* p) : pCar(p) {}
	void show() {
		pCar->show();
		cout << "，自动刹车";
	}
private:
	Car* pCar;
};

// 装饰器3 定速巡航
class Decorator03 :public Car {
public:
	Decorator03(Car* p) : pCar(p) {}
	void show() {
		pCar->show();
		cout << "，车道偏离";
	}
private:
	Car* pCar;
};


int main() {
    // 以自身为装饰器的实例对象，来达到扩展功能的目的。
	Car* p1 = new Decorator01(new Bmw());
	p1 = new Decorator02(p1);
	p1 = new Decorator03(p1);
	p1->show();
	cout << endl;

	Car* p2 = new Decorator02(new Audi());
	p2->show();
	cout << endl;

	Car* p3 = new Decorator03(new Benz());
	p3->show();
	cout << endl;

	return 0;
}
```









## 生产者消费者模式

```cpp
#include <condition_variable>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

const int PRODUCER_SIZE = 20;  // 生产者数量
const int CONSUMER_SIZE = 10;  // 消费者数量
const int MAX_SIZE = 10;       // 缓冲区大小

queue<int> que;  // 模拟缓冲区
mutex mtx;
condition_variable con;

// 生产者
void put() {
    while (true) {
        Sleep(5);
        unique_lock<mutex> lock(mtx);
        while (que.size() > MAX_SIZE) {
            con.wait(lock);
        }
        // 生产产品
        int data = rand();
        que.emplace(data);
        cout << this_thread::get_id() << " produce product : " << data << endl;
        con.notify_one();
    }
}

// 消费者
void take() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        while (que.empty()) {
            con.wait(lock);
        }
        // 消费产品
        int data = que.front();
        que.pop();
        cout << this_thread::get_id() << " consume product : " << data << endl;
        con.notify_one();
    }
}

int main() {
    vector<thread> threadPool;
    for (int i = 0; i < PRODUCER_SIZE; ++i) threadPool.emplace_back(put);
    for (int i = 0; i < CONSUMER_SIZE; ++i) threadPool.emplace_back(take);

    for (int i = 0; i < PRODUCER_SIZE + CONSUMER_SIZE; ++i) {
        threadPool[i].join();
    }

    system("pause");
    return 0;
}
```



# 数据结构



### 说一下各种常见数据结构的优缺点？



| 数据结构 | 优点                                                       |                           缺点                           |
| :------- | :--------------------------------------------------------- | :------------------------------------------------------: |
| 数组     | 插入快，如果知道下标，可以非常快的存取                     |                 查找慢，删除慢，大小固定                 |
| 有序数组 | 比无序的数组查找快                                         |                  删除和插入慢，大小固定                  |
| 栈       | 提供后进先出方式的存取                                     |                      存取其他项很慢                      |
| 队列     | 提供先进先出方式的存取                                     |                      存取其他项很慢                      |
| 链表     | 插入快，删除快                                             |                          查找慢                          |
| 二叉树   | 查找，插入，删除都快（如果树保持平衡）                     |                       删除算法复杂                       |
| 红-黑树  | 查找，插入，删除都快，树总是平衡的                         |                         算法复杂                         |
| 2-3-4树  | 查找，插入，删除都快，树总是平衡的，类似的树对磁盘存储有用 |                         算法复杂                         |
| 哈希表   | 如果关键字已知则存取极快，插入快                           | 删除慢，如果不知道关键词则存取很慢，对存储空间使用不充分 |
| 堆       | 插入删除快，对最大数据项的存取很快                         |                    对其他数据项存取慢                    |
| 图       | 对现实世界建模                                             |                     有些算法慢且复杂                     |









# 每日过一遍的知识点

- [ ] 4种智能指针，shared_ptr，weak_ptr，unique_ptr
- [ ] 虚函数的实现及内存分布
- [ ] c++面向对象三大特性，
- [ ] 成员初始化部分



