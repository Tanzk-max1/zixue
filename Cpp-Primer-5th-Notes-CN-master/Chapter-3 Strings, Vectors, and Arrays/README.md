# 第3章 字符串、向量和数组

## 命名空间的`using`声明（Namespace `using` Declarations）

使用`using`声明后就无须再通过专门的前缀去获取所需的名字了。

```c++
using std::cout;
```

程序中使用的每个名字都需要用独立的`using`声明引入。

头文件中通常不应该包含`using`声明。

## 标准库类型`string`（Library `string` Type）

标准库类型`string`表示可变长的字符序列，定义在头文件`string`中。

### 定义和初始化`string`对象（Defining and Initializing `string`s）

初始化`string`的方式：

|                     方式                      |                  含义                  |
| :-------------------------------------------: | :------------------------------------: |
|                  `string s1`                  |         `s1`被默认初始化为空串         |
|      `string s2(s1)`<br>`string s2 = s1`      |            `s2`是`s1`的拷贝            |
| `string s3("value")`<br>`string s3 = "value"` |         `s3`是`"value"`的拷贝          |
|              `string s4(n, 'c')`              | `s4`被初始化为连续`n`个字符`c`组成的串 |

如果使用等号初始化一个变量，实际上执行的是拷贝初始化（copy initialization），编译器把等号右侧的初始值拷贝到新创建的对象中去。如果不使用等号，则执行的是直接初始化（direct initialization）。

### `string`对象上的操作（Operations on `string`s）

`string`的操作：

|           操作           |                          含义                           |
| :----------------------: | :-----------------------------------------------------: |
|        `os << s`         |              将`s`写入输出流`os`，返回`os`              |
|        `is >> s`         | 从输入流`is`读取字符串至`s`，字符串以空白分隔，返回`is` |
|     `getline(is, s)`     |           从输入流`is`读取一行至`s`，返回`is`           |
|       `s.empty()`        |                   `s`为空则返回`true`                   |
|        `s.size()`        |                   返回`s`中的字符个数                   |
|          `s[n]`          |               返回`s`中第`n`个字符的引用                |
|        `s1 + s2`         |                返回`s1`和`s2`拼接后的串                 |
|        `s1 = s2`         |                    将`s2`赋值给`s1`                     |
| `s1 == s2`<br>`s1 != s2` |           判断`s1`和`s2`中的字符是否完全一样            |
|   `<`、`<=`、`>`、`>=`   |                以字典顺序比较`s1`和`s2`                 |

在执行读取操作时，`string`对象会自动忽略开头的空白（空格符、换行符、制表符等）并从第一个真正的字符开始读取，直到遇见下一处空白为止。

使用`getline`函数可以读取一整行字符。该函数只要遇到换行符就结束读取并返回结果，如果输入的开始就是一个换行符，则得到空`string`。触发`getline`函数返回的那个换行符实际上被丢弃掉了，得到的`string`对象中并不包含该换行符。

`size`函数返回`string`对象的长度，返回值是`string::size_type`类型，这是一种**无符号类型**。要使用`size_type`，必须先指定它是由哪种类型定义的。(size_t)

如果一个表达式中已经有了`size`函数就不要再使用`int`了，这样可以避免混用`int`和`unsigned int`可能带来的问题。

当把`string`对象和字符字面值及字符串字面值混合在一条语句中使用时，必须确保每个加法运算符两侧的运算对象中至少有一个是`string`。

```c++
string s4 = s1 + ", ";          // ok:一个string对象和一个字面值相加
string s5 = "hello" + ", ";     // error:两个都不是string对象
string s6 = s1 + ", " + "world";    // ok: 每个加法运算符都有一个运算对象是“string”
string s6 = ", " + "world"+s1; // error，不能直接字面值相加
```

为了与C兼容，C++语言中的字符串字面值并不是标准库`string`的对象。

#### string 字符串的比较

![image-20240417163455114](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240417163455114.png)

解释一下，在字符相同的时候，比较长度，在字符不同的时候，比较大小，2>1，b》a，这样子进行比较

### 处理`string`对象中的字符（Dealing with the Characters in a `string`）

头文件`cctype`中的字符操作函数：

|     操作      |              含义               |
| :-----------: | :-----------------------------: |
| `isalnum(c)`  |   `c`是字母或数字时返回`true`   |
| `isalpha(c)`  |      `c`是字母时返回`true`      |
| `iscntrl(c)`  |    `c`是控制字符时返回`true`    |
| `isdigit(c)`  |      `c`是数字时返回`true`      |
| `isgraph(c)`  | `c`不是空格但可打印时返回`true` |
| `islower(c)`  |    `c`是小写字母时返回`true`    |
| `isprint(c)`  |   `c`是可打印字符时返回`true`   |
| `ispunct(c)`  |    `c`是标点符号时返回`true`    |
| `isspace(c)`  |      `c`是空白时返回`true`      |
| `isupper(c)`  |    `c`是大写字母时返回`true`    |
| `isxdigit(c)` |  `c`是十六进制数字时返回`true`  |
| `tolower(c)`  |  将`c`转变为小写字母或原样返回  |
| `toupper(c)`  |  将`c`转变为大写字母或原样返回  |

建议使用C++版本的C标准库头文件。C语言中名称为`name.h`的头文件，在C++中则被命名为`cname`。

C++11提供了范围`for`（range for）语句，可以遍历给定序列中的每个元素并执行某种操作。

```c++
for (declaration : expression)
    statement
```

`expression`部分是一个对象，用于表示一个序列。`declaration`部分负责定义一个变量，该变量被用于访问序列中的基础元素。每次迭代，`declaration`部分的变量都会被初始化为`expression`部分的下一个元素值。

```c++
string str("some string");
// print the characters in str one character to a line
for (auto c : str)      // for every char in str
    cout << c << endl;  // print the current character followed by a newline
```

如果想在范围`for`语句中改变`string`对象中字符的值，必须把循环变量定义成引用类型。

下标运算符接收的输入参数是`string::size_type`类型的值，表示要访问字符的位置，返回值是该位置上字符的引用。

下标数值从0记起，范围是0至`size - 1`。使用超出范围的下标将引发不可预知的后果。

C++标准并不要求标准库检测下标是否合法。编程时可以把下标的类型定义为相应的`size_type`，这是一种无符号数，可以确保下标不会小于0，此时代码只需要保证下标小于`size`的值就可以了。另一种确保下标合法的有效手段就是使用范围`for`语句。

![image-20240421212101744](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240421212101744.png)

另外一种记录的方式，这样子可以保证只要是返回true，然后bool类型的话返回1，然后就会达成条件，在上面那些函数里面可以做到



decltype 关键字用来推到类型，作用是选择并返回操作数的数据类型，此处的返回的类型是int ，从而punct+cnt进行类型定义。`decltype(s.size())` 的目的是根据 `s.size()` 的返回类型来推导出 `punct_cnt` 的类型，并将其定义为相应的类型。假设 `s` 是一个 `std::string` 对象，那么 `s.size()` 返回的类型是 `std::string::size_type`，这是一个无符号整数类型。因此，`decltype(s.size())` 推导出的类型是 `std::string::size_type`。

```c++
string s("hello world!");
  for(auto &c : s)
    c = toupper(c);
  cout << s << endl;
```

通过 `auto &c` 这样的引用声明，我们创建了一个别名 `c`，它引用了字符串 `s` 中的每个字符。在循环的每次迭代中，`c` 代表了当前字符的别名。

通过对 `c` 进行修改，实际上就是直接修改了 `s` 中对应位置的字符。由于 `c` 是 `s` 的引用，对 `c` 的修改会反映在原始字符串 `s` 上。这样，循环遍历过程中对 `c` 的修改实际上就是在修改 `s` 中对应字符的值。

这种方式避免了直接操作字符串的索引，使代码更加简洁和易读。通过使用引用，我们可以直接在循环中修改原始字符串，而不需要创建临时变量或使用索引来访问和修改字符串中的字符。这种方式在处理容器或字符串等可变对象时非常方便和高效。

其实这种for循环就是前者对后者的一个遍历，一个一个字符的遍历，用在字符串或者一堆数据的时候比较好用

#### 常用的遍历推导规律：

```c++
//遍历字符串时，元素类型是 char，因此迭代变量的类型将被推导为 char。
std::string str = "Hello";
for (auto c : str)
{
    // c 的类型是 char
}

//遍历整型容器（如 std::vector<int>）时，迭代变量的类型将被推导为容器中存储的元素类型。
std::vector<int> numbers = {1, 2, 3, 4, 5};
for (auto num : numbers)
{
    // num 的类型是 int
}

//遍历浮点数容器（如 std::vector<double>）时，迭代变量的类型将被推导为容器中存储的元素类型
std::vector<double> values = {1.5, 2.7, 3.2};
for (auto val : values)
{
    // val 的类型是 double
}

//遍历容器的迭代器时，迭代变量的类型将被推导为迭代器指向的元素类型。
std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
for (auto it = names.begin(); it != names.end(); ++it)
{
    // *it 的类型是 std::string
}
```



#### 使用for语句改变字符串中的字符

如果想要改变字符串中的字符，必须要把循环变量定义成引用的类型。所谓引用其实就是给对象一个别名。因此当使用引用作为循环控制变量时，这个变量实际上被依次绑定到了序列的每个元素上。使用这个引用，我们就能改变它绑定的字符。

```c++
string s("hello world!");
  for(auto &c : s)
    c = toupper(c);
  cout << s << endl;

//输出的是HELLO WORLD!
```

#### 使用for语句修改一部分的字符

两个方法，一个是使用迭代器，一个是使用下表，此处讲下标运算符（''[ ]''）接受的参数是string::size_type

这个参数表示要访问的字符的位置；返回值是该位置上的引用。

string对象的下标从0计起。如果string对象s至少包含两个字符，则s[0]是第1个字符、s[1]是第2个字符、s[s.size()-1]是最后一个字符。string对象的下标必须大于等于0而小于s.size()。

```c++
if(!s.empty()) // 确保确实有字符需要输出
cout << s[0] << endl; //输出s的第一个字符
//在访问指定字符之前，首先检查s是否为空。其实不管什么时候只要对string对象使用
//了下标，都要确认在那个位置上确实有值。如果s为空，则s[0]的结果将是未定义的。
```

使用下标执行迭代写法

```c++
for(decltype(s.size()) index = 0;
    index!=s.size() && !isspace(s[index]); ++index)
    {
    s[index] = toupper(s[index]);
    cout << s[index] ;

  }
```

使用下标随机访问

```c++
const string hexdigits = "0123456789ABCDEF";
  cout <<"Enter a series of numbers between 0 and 15"
       <<" separated by apaces. Hit ENTER when finished:"
       << endl;
  string result;
  string :: size_type  n;//无符号类型，
  while (cin >> n)
    if (n < hexdigits.size())
      result += hexdigits[n];
  cout << "your hex number is: " << result << endl;
  return 0;

//输入0-15，用输入的数值进行下标访问
```



## 标准库类型`vector`（Library `vector` Type）

标准库类型`vector`表示对象的集合，也叫做容器（container），定义在头文件`vector`中。`vector`中所有对象的类型都相同，每个对象都有一个索引与之对应并用于访问该对象。

`vector`是模板（template）而非类型，由`vector`生成的类型必须包含`vector`中元素的类型，如`vector<int>`。

因为引用不是对象，所以不存在包含引用的`vector`。

在早期的C++标准中，如果`vector`的元素还是`vector`，定义时必须在外层`vector`对象的右尖括号和其元素类型之间添加一个空格，如`vector<vector<int> >`。但是在C++11标准中，可以直接写成`vector<vector<int>>`，不需要添加空格。

```c++
vector<int> ivec; // ivec保存int类型的对象
vector<Sales_item> Sales_vec;//保存Sales_item类型的对象 
vector<vector<string>> file;//该向量的元素是 vector 对象
//编译器根据模板 vector 生成了三种不同的类型：vector<int>、vector<Sales_item>和 vector<vector<string>>。
```



### 定义和初始化`vector`对象（Defining and Initializing `vector`s）

初始化`vector`的方法与`string`类似。

初始化`vector`对象时如果使用圆括号，可以说提供的值是用来构造（construct）`vector`对象的；如果使用的是花括号，则是在列表初始化（list initialize）该`vector`对象。

可以只提供`vector`对象容纳的元素数量而省略初始值，此时会创建一个值初始化（value-initialized）的元素初值，并把它赋给容器中的所有元素。这个初值由`vector`对象中的元素类型决定。

* 初始化vector对象的方法

![image-20240422113516662](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422113516662.png)

列表初始化vector对象

![image-20240422114015324](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422114015324.png)



创造指定数量的元素



![image-20240422114039228](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422114039228.png)

值初始化

![image-20240422114138113](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422114138113.png)

![image-20240422114152407](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422114152407.png)

ps：初始化里面，如果是（）圆括号的话代表的是元素的个数

{}代表的是元素的值

```c++
vector<int> v1(10); // v1有10个元素，每个的值都是0
vector<int> v2{10}; // v2有1个元素，该元素的值是10
vector<int> v3(10,1);//v3有10个元素，每个的值都是1
vector<int> v4{10,1};//v4有2个元素，值分别是10和1
```

前者代表vector的容量，后者代表元素的初值

![image-20240422114506403](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422114506403.png)

```c++
vector<string> v5{"hi"};//列表初始化：v5有一个元素
vector<string> v6("hi");//错误；不能使用字符串字面值构建 vector 对象
vector<string> v7{10}; // v7有10个默认初始化的元素
vector<string> v8{10,"hi"}; //v8有10个值为“hi”的元素
```



### 向`vector`对象中添加元素（Adding Elements to a `vector`）

三种情况下直接初始化合适

1. 初始值已知并且数量较少
2. 初始值是另外一个vector对象的副本
3. 所有元素初始值都一样

`push_back`函数可以把一个值添加到`vector`的尾端。

```c++
vector<int> v2;         // empty vector
for (int i = 0; i != 100; ++i)
    v2.push_back(i);    // 依次把整数值放进v2的尾端
// at end of loop v2 has 100 elements, values 0 . . . 99
```

范围`for`语句体内不应该改变其所遍历序列的大小。那么在定义vector 对象的时候设定其大小也就没什么必要了，事实上如果这么做性能可能更差。只有一种例外情况，就是所有(all)元素的值都一样。一旦元素的值有所不同，更有效的办法是先定义一个空的 vector 对象，再在运行时向其中添加具体值 

### 其他`vector`操作（Other `vector` Operations）

`vector`支持的操作：

|       操作       |                             含义                             |
| :--------------: | :----------------------------------------------------------: |
|   `v.empty()`    |                     `v`为空则返回`true`                      |
|    `v.size()`    |                     返回`v`中的元素个数                      |
| `v.push_back(t)` |                     将`t`添加至的`v`尾部                     |
|      `v[n]`      |                  返回`v`中第`n`个元素的引用                  |
| `v = {a, b, c}`  |                 将`v`赋值为`{a, b, c}`的拷贝                 |
|    `v1 = v2`     |                用v2中元素的拷贝替换v1中的元素                |
|    `v1 == v2`    | v1和v2相等当且仅当他们的元素数量相同且对应位置的元素值都相同 |
|    `v1 !=v2`     |                         同上一条相反                         |
|                  |                                                              |

`size`函数返回`vector`对象中元素的个数，返回值是由`vector`定义的`size_type`类型。`vector`对象的类型包含其中元素的类型。

```c++
vector<int>::size_type  // ok
vector::size_type       // error
```

各个相等性运算符和关系运算符也于string的相应运算符功能一样。

两个vector对象当且仅当他们所含的元素个数而已，而且对应位置的元素值也相同。

关系运算符按照字典顺序进行比较：如果两个vector对象的

`vector`和`string`对象的下标运算符只能用来访问已经存在的元素，而不能用来添加元素。

```c++
vector<int> ivec;   // empty vector
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
{
    ivec[ix] = ix;  // disaster: ivec has no elements
    ivec.push_back(ix); // ok: adds a new element with value ix
}
```

![image-20240422220253091](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240422220253091.png)

#### 也可以使用索引进行对vector里面的数值进行更改

![image-20240423093933481](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240423093933481.png)

## 迭代器介绍（Introducing Iterators）

迭代器的作用和下标类似，但是更加通用。所有标准库容器都可以使用迭代器，但是其中只有少数几种同时支持下标运算符。

### 使用迭代器（Using Iterators）

定义了迭代器的类型都拥有`begin`和`end`两个成员函数。`begin`函数返回指向第一个元素的迭代器，`end`函数返回指向容器“尾元素的下一位置（one past the end）”的迭代器，通常被称作尾后迭代器（off-the-end iterator）或者简称为尾迭代器（end iterator）。尾后迭代器仅是个标记，表示程序已经处理完了容器中的所有元素。迭代器一般为`iterator`类型。

```c++
// b denotes the first element and e denotes one past the last element in ivec
auto b = ivec.begin(), e = ivec.end();    // b and e have the same type
```

如果容器为空，则`begin`和`end`返回的是同一个迭代器，都是尾后迭代器。

标准容器迭代器的运算符：

|                运算符                |                             含义                             |
| :----------------------------------: | :----------------------------------------------------------: |
|               `*iter`                |         返回迭代器`iter` 所指元素的引用解引用`iter`          |
|    `iter->mem` <br> `(*iter).mem`    | 这两一个意思,解引用`iter` 并获取该元素的名为`mem`的成员等价于`(*iter).mem` |
|               `++iter`               |              递增`iter`使其指向容器的下一个元素              |
|               `--iter`               |              递减`iter`使其指向容器的前一个元素              |
| `iter1 == iter2`<br>`iter1 != iter2` | 比较`iter1`和`iter2`。若他们指向相同元素或都是尾后迭代器，则两者相等 |

因为`end`返回的迭代器并不实际指向某个元素，所以不能对其进行递增或者解引用的操作。

在`for`或者其他循环语句的判断条件中，最好使用`!=`而不是`<`。所有标准库容器的迭代器都定义了`==`和`!=`，但是只有其中少数同时定义了`<`运算符。

如果`vector`或`string`对象是常量，则只能使用`const_iterator`迭代器，该迭代器只能读元素，不能写元素。

`begin`和`end`返回的迭代器具体类型由对象是否是常量决定，如果对象是常量，则返回`const_iterator`；如果对象不是常量，则返回`iterator`。

```c++
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();   // it1 has type vector<int>::iterator
auto it2 = cv.begin();  // it2 has type vector<int>::const_iterator
```

C++11新增了`cbegin`和`cend`函数，不论`vector`或`string`对象是否为常量，都返回`const_iterator`迭代器。

任何可能改变容器对象容量的操作，都会使该对象的迭代器失效。

### 迭代器运算（Iterator Arithmetic）

|             操作             |                             含义                             |
| :--------------------------: | :----------------------------------------------------------: |
|   `iter + n`<br>`iter - n`   |    `iter`向前或向后移动`n`个元素后指向某个元素或尾后位置     |
|       `iter1 - iter2`        |                  获得`iter1`和`iter2`的间距                  |
|     `>`、`>=`、`<`、`<=`     |                     比较两个迭代器的位置                     |
| `iter1 += n`<br>`iter1 -= n` | 迭代器加法的/减法的符合赋值语句，将iter1加n/减n的结果赋给iter1 |

`difference_type`类型用来表示两个迭代器间的距离，这是一种带符号整数类型。

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 获取迭代器的差异类型
    using difference_type = std::vector<int>::difference_type;

    // 计算迭代器之间的距离
    difference_type distance = numbers.end() - numbers.begin();

    std::cout << "Distance between iterators: " << distance << std::endl;

    return 0;
}
```



#### 迭代器的类型

拥有迭代器的标准库类型使用iterator 和 const_iterator 来表示迭代器的类型：

```c++
vector<int>::iterator it; // it能读写 vector<int>的元素。这行代码定义了一个名为 it 的迭代器，它的类型是 vector<int>::iterator。这种类型的迭代器可以用于读取和修改 vector<int> 容器中的元素。
string::iterator it2; // it2 能读写string对象中的字符。这行代码定义了一个名为 it2 的迭代器，它的类型是 string::iterator。这种类型的迭代器可以用于读取和修改 string 对象中的字符。
vector<int>::const_iterator it3;// it3只能读元素，不能写元素。这行代码定义了一个名为 it3 的迭代器，它的类型是 vector<int>::const_iterator。这种类型的迭代器只能用于读取 vector<int> 容器中的元素，不允许对元素进行修改。
string::const_iterator it4; // it4只能读宇符，不能写字符。这行代码定义了一个名为 it4 的迭代器，它的类型是 string::const_iterator。这种类型的迭代器只能用于读取 string 对象中的字符，不允许对字符进行修改。
```

总结

- `vector<int>::iterator` 类型的迭代器可以读取和修改 `vector<int>` 容器中的元素。
- `string::iterator` 类型的迭代器可以读取和修改 `string` 对象中的字符。
- `vector<int>::const_iterator` 类型的迭代器只能读取 `vector<int>` 容器中的元素，不允许修改。
- `string::const_iterator` 类型的迭代器只能读取 `string` 对象中的字符，不允许修改。

#### begin和end运算符

begin和 end返回的具体类型由对象是否是常量决定，如果对象是常量，begin和end 返回 const_iterator;如果对象不是常量，返回iterator:

为了便于专门得到 const_iterator类型的返回值，C++11新标准引入了两个新函数，分别是cbegin和 cend:

auto it3= v.cbegin();// it3的类型是vector<int>::const_iterator

有所不同的是，不论 vector对象(或string对象)本身是否是常量，返回值都是const_iterator。

#### 迭代器失效

![image-20240423124445993](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240423124445993.png)

* 凡是使用了迭代器的循环体，都不要向迭代器所属的元素加入元素，因为迭代器 `it` 将失效，无法正确指向下一个元素，从而导致未定义的行为。<br>

* 为了避免这种情况，我们应该在循环体中避免对容器进行添加或删除元素的操作。如果需要对容器进行修改，可以先记录需要添加或删除的元素，然后在循环结束后进行相应的修改操作。

* ```c++
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> elementsToRemove;
  
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
      if (*it == 3) {
          elementsToRemove.push_back(*it);
      }
  }
  
  for (const auto& element : elementsToRemove) {
      numbers.erase(std::remove(numbers.begin(), numbers.end(), element), numbers.end());
  }
  ```

  



## 数组（Arrays）

数组类似`vector`，但数组的大小确定不变，不能随意向数组中添加元素。

如果不清楚元素的确切个数，应该使用`vector`。

### 定义和初始化内置数组（Defining and Initializing Built-in Arrays）

数组是一种复合类型，声明形式为`a[d]`，其中`a`是数组名称，`d`是数组维度（dimension）。维度必须是一个常量表达式。

默认情况下，数组的元素被默认初始化。

定义数组的时候必须指定数组的类型，不允许用`auto`关键字由初始值列表推断类型。

如果定义数组时提供了元素的初始化列表，则允许省略数组维度，编译器会根据初始值的数量计算维度。但如果显式指明了维度，那么初始值的数量不能超过指定的大小。如果维度比初始值的数量大，则用提供的值初始化数组中靠前的元素，剩下的元素被默认初始化。

```c++
const unsigned sz = 3;
int ia1[sz] = {0,1,2};  // 含有三个元素0, 1, 2
int a2[] = {0, 1, 2};   // 维度是3的数组
int a3[5] = {0, 1, 2};  // 等价于 a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"};   // 等价于 a4[] = {"hi", "bye", ""}，没有被表明的直接默认是空字符，初始值化
int a5[2] = {0,1,2};    // 错误，初始值过多
```

可以用字符串字面值初始化字符数组，但字符串字面值结尾处的空字符也会一起被拷贝到字符数组中。

```c++
char a1[] = {'C', '+', '+'};        // 列表初始化，没有空字符
char a2[] = {'C', '+', '+', '\0'};  // 列表初始化，含有限时的空字符
char a3[] = "C++";      // 自动添加表示字符串结束的空字符
const char a4[6] = "Daniel";    // 错误；没有空间可存放空字符！a4 数组的大小被指定为 6，但是字符串字面量 "Daniel" 需要 7 个字符的空间，包括表示字符串结束的空字符 '\0'。因此，在将 "Daniel" 复制到 a4 数组时，无法容纳字符串结束符，导致数组越界访问。
```

不能用一个数组初始化或直接赋值给另一个数组。

从数组的名字开始由内向外阅读有助于理解复杂数组声明的含义。

默认情况下，类型修饰符从右向左依次绑定。对于 ptrs 来说，从右向左(参见2.3.3节，第52页)理解其含义比较简单：首先知道我们定义的是一个大小为10的数组，它的名字是ptrs,然后知道数组中存放的是指向 int 的指针。

```c++
int *ptrs[10];              // ptrs 是含有10个整型指针的数组
int &refs[10] = /* ? */;    // error：不存在引用的数组
int (*Parray)[10] = &arr;   // Parray 指向一个含有10个整数的数组
int (&arrRef)[10] = arr;    // arrRef 引用一个含有10个整数的数组
int *(&arry)[10] = ptrs; // arry是数组的引用，该数组含有10个指针
```

### 访问数组元素（Accessing the Elements of an Array）

数组下标通常被定义成`size_t`类型，这是一种机器相关的无符号类型，可以表示内存中任意对象的大小。`size_t`定义在头文件`cstddef`中。

大多数常见的安全问题都源于缓冲区溢出错误。当数组或其他类似数据结构的下标越界并试图访问非法内存区域时，就会产生此类错误。

### 指针和数组（Pointers and Arrays）

在大多数表达式中，使用数组类型的对象其实是在使用一个指向该数组首元素的指针。

```c++
string nums[] = {"one", "two", "three"};    // array of strings
string *p = &nums[0];   // p指向nums的第一个元素
string *p2 = nums;      // 等价于p2 = &nums[0]
```

当使用数组作为一个`auto`变量的初始值时，推断得到的类型是指针而非数组。但`decltype`关键字不会发生这种转换，直接返回数组类型。

```c++
int ia[] = {0,1,2,3,4,5,6,7,8,9};   // ia is an array of ten ints
auto ia2(ia);   // ia2 is an int* that points to the first element in ia
ia2 = 42;       // error: ia2 is a pointer, and we can't assign an int to a pointer
auto ia2(&ia[0]);   // now it's clear that ia2 has type int*
// ia3 is an array of ten ints
decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
ia3 = p;    // error: can't assign an int* to an array
ia3[4] = i;     // ok: assigns the value of i to an element in ia3
```

C++11在头文件`iterator`中定义了两个名为`begin`和`end`的函数，功能与容器中的两个同名成员函数类似，参数是一个数组。

```c++
int ia[] = {0,1,2,3,4,5,6,7,8,9};   // ia is an array of ten ints
int *beg = begin(ia);   // pointer to the first element in ia
int *last = end(ia);    // pointer one past the last element in ia
```

两个指针相减的结果类型是`ptrdiff_t`，这是一种定义在头文件`cstddef`中的带符号类型。

标准库类型限定使用的下标必须是无符号类型，而内置的下标运算无此要求。

![image-20240424194713520](C:\Users\15525\AppData\Roaming\Typora\typora-user-images\image-20240424194713520.png)

加括号就是位移4个，不加括号就是数值+4

### C风格字符串（C-Style Character Strings）

C风格字符串是将字符串存放在字符数组中，并以空字符结束（null terminated）。这不是一种类型，而是一种为了表达和使用字符串而形成的书写方法。

C++标准支持C风格字符串，但是最好不要在C++程序中使用它们。对大多数程序来说，使用标准库`string`要比使用C风格字符串更加安全和高效。

C风格字符串的函数：

|       操作       |                                        含义                                         |
| :--------------: | :---------------------------------------------------------------------------------: |
|   `strlen(p)`    |                                    返回`p`的长度                                    |
| `strcmp(p1, p2)` | 比较`p1`和`p2`。若`p1 == p2`，返回`0`；若`p1 > p2`，返回正数；若`p1 < p2`，返回负数 |
| `strcat(p1, p2)` |                                  将`p2`拼接至`p1`                                   |
| `strcpy(p1, p2)` |                                  将`p2`拷贝至`p1`                                   |

C风格字符串函数不负责验证其参数的正确性，传入此类函数的指针必须指向以空字符作为结尾的数组。

### 与旧代码的接口（Interfacing to Older Code）

任何出现字符串字面值的地方都可以用以空字符结束的字符数组来代替：

- 允许使用以空字符结束的字符数组来初始化`string`对象或为`string`对象赋值。

- 在`string`对象的加法运算中，允许使用以空字符结束的字符数组作为其中一个运算对象（不能两个运算对象都是）。

- 在`string`对象的复合赋值运算中，允许使用以空字符结束的字符数组作为右侧运算对象。

不能用`string`对象直接初始化指向字符的指针。为了实现该功能，`string`提供了一个名为`c_str`的成员函数，返回`const char*`类型的指针，指向一个以空字符结束的字符数组，数组的数据和`string`对象一样。

```c++
string s("Hello World");    // s holds Hello World
char *str = s;  // error: can't initialize a char* from a string
const char *str = s.c_str();    // ok
```

针对`string`对象的后续操作有可能会让`c_str`函数之前返回的数组失去作用，如果程序想一直都能使用其返回的数组，最好将该数组重新拷贝一份。

可以使用数组来初始化`vector`对象，但是需要指明要拷贝区域的首元素地址和尾后地址。

```c++
int int_arr[] = {0, 1, 2, 3, 4, 5};
// ivec has six elements; each is a copy of the corresponding element in int_arr
vector<int> ivec(begin(int_arr), end(int_arr));
```

在新版本的C++程序中应该尽量使用`vector`、`string`和迭代器，避免使用内置数组、C风格字符串和指针。

## 多维数组（Multidimensional Arrays）

C++中的多维数组其实就是数组的数组。当一个数组的元素仍然是数组时，通常需要用两个维度定义它：一个维度表示数组本身的大小，另一个维度表示其元素（也是数组）的大小。通常把二维数组的第一个维度称作行，第二个维度称作列。

多维数组初始化的几种方式：

```c++
int ia[3][4] =
{   // three elements; each element is an array of size 4
    {0, 1, 2, 3},   // initializers for the row indexed by 0
    {4, 5, 6, 7},   // initializers for the row indexed by 1
    {8, 9, 10, 11}  // initializers for the row indexed by 2
};
// equivalent initialization without the optional nested braces for each row
int ib[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
// explicitly initialize only element 0 in each row
int ic[3][4] = {{ 0 }, { 4 }, { 8 }};
// explicitly initialize row 0; the remaining elements are value initialized
int id[3][4] = {0, 3, 6, 9};
```

可以使用下标访问多维数组的元素，数组的每个维度对应一个下标运算符。如果表达式中下标运算符的数量和数组维度一样多，则表达式的结果是给定类型的元素。如果下标运算符数量比数组维度小，则表达式的结果是给定索引处的一个内层数组。

```c++
// assigns the first element of arr to the last element in the last row of ia
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1];  // binds row to the second four-element array in ia
```

使用范围`for`语句处理多维数组时，为了避免数组被自动转换成指针，语句中的外层循环控制变量必须声明成引用类型。

```c++
for (const auto &row : ia)  // for every element in the outer array
    for (auto col : row)    // for every element in the inner array
        cout << col << endl;
```

如果`row`不是引用类型，编译器初始化`row`时会自动将数组形式的元素转换成指向该数组内首元素的指针，这样得到的`row`就是`int*`类型，而之后的内层循环则试图在一个`int*`内遍历，程序将无法通过编译。

```c++
for (auto row : ia)
    for (auto col : row)
```

使用范围`for`语句处理多维数组时，除了最内层的循环，其他所有外层循环的控制变量都应该定义成引用类型。

因为多维数组实际上是数组的数组，所以由多维数组名称转换得到的指针指向第一个内层数组。

```c++
int ia[3][4];       // array of size 3; each element is an array of ints of size 4
int (*p)[4] = ia;   // p points to an array of four ints
p = &ia[2];         // p now points to the last element in ia
```

声明指向数组类型的指针时，必须带有圆括号。

```c++
int *ip[4];     // array of pointers to int
int (*ip)[4];   // pointer to an array of four ints
```

使用`auto`和`decltype`能省略复杂的指针定义。

```c++
// print the value of each element in ia, with each inner array on its own line
// p points to an array of four ints
for (auto p = ia; p != ia + 3; ++p)
{
    // q points to the first element of an array of four ints; that is, q points to an int
    for (auto q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
    cout << endl;
}
```