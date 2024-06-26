#### ch3

默认已经

```c++
#include <iostream>
#include "vector"
#include <string>
#include "Sales_item.h"
using namespace std;

```

ex3.6

```c++
#include <iostream>
#include <string>

int main() {
  std::string s;
  if (std::cin >> s) {
    for (auto &c : s)  // `c` is `char &`
      c = 'X';
  }
  std::cout << s << std::endl;

  return 0;
}
```

ex3.7

```c++
int main(){
  string s;
    if (cin >> s){
      for(char c : s){
        c = 'X';//因为for循环里面改变的话只能两种方法，一个是引用，一个是下标循环
          //此处修改的只是副本c
      }
    }
    cout << s << endl;
    return 0;
}
```

3.8

```
void change_with_while(){
  string s;
  if (cin >> s){
    string :: size_type pos = 0;
    while (pos!=s.size())
      s[pos++] = 'x';
  }
  cout << s << endl;
}
void change_with_for(){
  string s;
  if (cin >> s) {
    string ::size_type pos = 0;
    for (pos; pos != s.size(); ++pos) {
      s[pos] = 'x';
    }
    cout << s << endl;
  }
}
int main(){
  change_with_while();
  cout << "ssssssssssss" << endl;
  change_with_for();
  return 0;
}
```

3.10

```
void cin_zifuchuan() {
  string s="hello,hehll!";
    string  pos;
    for (auto c : s) {
      if (!s.empty() && !ispunct(c))
        pos += c;

    }
    cout << pos ;
}

int main(){
  cin_zifuchuan();
  cout << "\n"<<"ssssssssssss" << endl;
  return 0;
}

```

3.11

```
const string s = "Keep out!";
for (auto &c : s) {
// 代码逻辑
}
给定的范围 for 语句是合法的。

在这个范围 for 语句中，使用 auto &c 来声明循环变量。这意味着循环变量 c 是一个引用，它会绑定到字符串 s 中的每个字符上。

循环变量 c 的类型是 const char &（常量引用）。由于字符串 s 是一个常量字符串，因此在范围 for 循环中，每个字符都被视为常量字符。这意味着你不能通过引用 c 来修改字符串中的字符。

在代码逻辑中，你可以使用循环变量 c 来访问和处理每个字符的值，但不能修改字符串 s 中的字符。

总结：给定的范围 for 语句是合法的，循环变量 c 的类型是 const char &（常量引用），用于访问字符串 s 中的每个字符。
```

3.12

```c++
(a) vector<vector<int>> ivec;
这是正确的。它定义了一个名为 ivec 的 vector 对象，其中的元素是 vector<int> 类型的向量。这种定义创建了一个空的二维整数向量。

执行结果：ivec 是一个空的二维整数向量。

(b) vector<string> svec = ivec;
这是不正确的。这行代码尝试将一个 vector<vector<int>> 类型的向量 ivec 赋值给一个 vector<string> 类型的向量 svec。由于类型不匹配，这个赋值操作是不合法的。

错误的原因：类型 vector<vector<int>> 和 vector<string> 是不同的类型，不能直接进行赋值。

(c) vector<string> svec(10, "null");
这是正确的。它定义了一个名为 svec 的 vector 对象，其中包含了 10 个字符串元素。每个元素都被初始化为值为 "null" 的字符串。

执行结果：svec 是一个包含 10 个字符串元素的向量，每个元素都被初始化为 "null"。
```

3.13

```c++
(a) vector<int> v1;//0
(b) vector<int> v2(10);//10个元素，全部0
(c) vector<int> v3(10,42);//10个42
(d) vector<int> v4{10};//1个元素，元素10
(e) vector<int> v5{10,42};//2个，元素10，42
(f) vector<string> v6(10);//10个元素，空字符串
(g)vector<string> v7{10,"hi"};//10个hi
```

3.16

```c++
void print_vector_int(const vector<int> &v) {
  for (const auto & elem : v)
    std::cout << elem << " ";
  std::cout << std::endl;
}

void print_vector_string(const vector<string> &v) {
  for (const auto & elem : v)
    std::cout << elem << " ";
  std::cout << std::endl;
}
int main() {
  vector<int> v1;               // 0  element
  vector<int> v2(10);           // 10 elements, values are all 0
  vector<int> v3(10, 42);       // 10 elements, values are all 42
  vector<int> v4{10};           // 1  element,  value  is  10
  vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
  vector<string> v6{10};        // 10 elements, values are all empty string
  vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"

  print_vector_int(v1);
  print_vector_int(v2);
  print_vector_int(v3);
  print_vector_int(v4);
  print_vector_int(v5);
  print_vector_string(v6);
  print_vector_string(v7);

  return 0;
}
```

3.17

```c++
int main() {
  vector<string> vString;     // 元素类型为 string 的 vector 对象
  string s;                   // 记录用户的输入值
  char cont = 'y';            // 与用户交互，决定是否继续输入
  cout << "请输入第一个词：" << endl;
  while (cin >> s) {
    vString.push_back(s);   // 向 vector 对象中添加元素
    cout << "您要继续吗（y or n）？" << endl;
    cin >> cont;
    if (cont != 'y' && cont != 'Y')
      break;
    cout << "请输入下一个词：" << endl;
  }
  cout << "转换后的结果是：" << endl;
  for (auto &mem : vString) { // 使用范围 for 循环语句遍历 vString 中的每个元素
    for (auto &c : mem)     // 使用范围 for 循环语句遍历 mem 中的每个字符
      c = toupper(c);     // 改写为大写字母形式
    cout << mem << endl;
  }

  return 0;
}

```

```c++
int main() {
  std::vector<std::string> sv;
  std::string s;
  while (std::cin >> s){
    sv.push_back(s);
    for (auto &elem : sv)
      for (auto &c : elem)
        c = toupper(c);
    if (sv.size() == 8)
      break;

    continue;

  }
  for (decltype(sv.size()) i = 0; i != sv.size(); ++i) {
    std::cout << sv[i] << '\t';
    if ((i + 1) % 8 == 0)
      std::cout << std::endl;
  }
  return 0;
}

```

3.18

```
vector<int> ivec;
ivec[0]= 42;//错误，因为ivec是一个空vector
对于一个空的 vector<int>，不能直接通过索引进行元素赋值，因为该索引位置上的元素并不存在。

要向空的 vector<int> 添加元素并进行更改，可以使用 push_back() 函数将元素添加到向量的末尾。
```

3.19

```c++
int main(){
  vector<int> v1(10,42);
  vector<int> v2 { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
  vector<int> v3;
  for (int i = 0; i < 10; ++i) {
    v3.push_back(42);
  }
}
```

3.20

```c++
void sum_xianglin(vector<int> &v){
  if (v.size()<2)
    return;
  for (decltype(v.size()) i = 0; i < v.size()-1; ++i) {
    cout << v[i] + v[i + 1] << endl;
  }
}
void  sum_shouwei(vector<int> &v){
  if (v.size()<2)
    return;
  auto mid = (v.size() + 1)/2;
  for (decltype(mid) i = 0; i < mid; ++i) {
    cout << v[i] + v[v.size() - 1 - i] << '\t';
  }
}
int main(){
  vector<int> iv;
  int i ;
  while (cin >> i)
    iv.push_back(i);
  sum_adjacent(iv);
  sum_shouwei(iv);
  return 0;
}

```

3.21

```c++
void print_vector_int(const vector<int> &v){
  for (auto it = v.cbegin(); it != v.cend() ; ++it) {
    cout << *it << " " << endl;
  }
}
void print_vector_string(const vector<string> &v){
  for (auto it = v.cbegin(); it != v.cend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
int main(){
  vector<int> v1;               // 0  element
  vector<int> v2(10);           // 10 elements, values are all 0
  vector<int> v3(10, 42);       // 10 elements, values are all 42
  vector<int> v4{10};           // 1  element,  value  is  10
  vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
  vector<string> v6{10};        // 10 elements, values are all empty string
  vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"

  print_vector_int(v1);
  print_vector_int(v2);
  print_vector_int(v3);
  print_vector_int(v4);
  print_vector_int(v5);
  print_vector_string(v6);
  print_vector_string(v7);
  return 0;
}
```

3.22

```c++
int main(){
  vector<string> text ;
  string line;
  while(getline(cin,line)&& !line.empty())
    text.push_back(line);
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    for (auto &c : *it) {
      c = toupper(c);

    }
  for (auto &elem: text)
    if (elem.empty())
      cout << endl;
    else
      cout << elem << " ";
//  vector<string> text;
//  string s;
//  // 利用 getline 读取一句话，直接回车产生一个空串，表示段落结束
//  while (getline(cin, s))
//    text.push_back(s);              // 逐个添加到 text 中
//  // 利用迭代器遍历全部字符串，遇空串停止循环
//  for (auto it = text.begin(); it != text.end() && !it -> empty(); it++) {
//    // 利用迭代器遍历当前字符串
//    for (auto it2 = it->begin(); it2 != it->end(); it2++)
//      *it2 = toupper(*it2);       // 利用 toupper 改写成大写形式
//    cout << *it << endl;
//  }

  return 0;
}
```

3.24

```c++
void sum_adjacent(const vector<int> &v){
  if (v.size() < 2)
    return;
  for (auto it = v.cbegin(); it!=v.cend() - 1 ;++it) {
    std::cout << *it + *(it + 1) << '\t';
    std::cout << std::endl;
  }
}
void sum_symmetric(const std::vector<int> &v) {
  // If the vector has odd size, element in the middle will add to itself.
  auto mid = v.cbegin() + (v.cend() - v.cbegin() + 1) / 2;
  for (auto it = v.cbegin(); it != mid; ++it)
    std::cout << *it + *(v.cend() - 1 - (it - v.cbegin())) << '\t';
  std::cout << std::endl;
}
//位置进行迁移



int main(){
  std::vector<int> iv;
  int i;
  while (std::cin >> i)
    iv.push_back(i);

  sum_adjacent(iv);
  sum_symmetric(iv);

  return 0;
}
```

3.26

```
在二分搜索程序中，计算中间位置的索引时，通常使用 mid = beg + (end - beg) / 2 而不是简单的 (beg + end) / 2 的原因是为了避免整数溢出的问题。

当 beg 和 end 都是很大的整数时，它们的和可能会超过整数类型的表示范围，导致溢出。这会导致计算的结果不正确，产生错误的中间位置。

通过使用 beg + (end - beg) / 2 的方式，我们先计算 end - beg，得到两个索引之间的距离。然后再将这个距离除以 2，确保结果不会溢出。

这种方式可以有效地避免整数溢出的问题，确保在计算中间位置时得到准确的结果。这在处理大范围的索引或数组时尤其重要，以保证二分搜索算法的正确性和稳定性。
```



3.27

```c++

int main(){
  unsigned buf_size = 1024;
  //int ia1[buf_size];            // //在声明数组时，数组的大小必须是编译时常量，而 constexpr 是用于定义编译时常量的关键字。如果 buf_size 不是一个 constexpr 值，那么在编译时无法确定数组的大小，因此会导致错误。
  int ia2[4 * 7 - 14];          // OK
  //int ia3[txt_size()];          // 这个语句错误的原因是 txt_size() 不是一个 constexpr 函数。与第一个错误类似，数组的大小必须在编译时确定，而 constexpr 函数是用于定义编译时常量的函数。如果 txt_size() 不是一个 constexpr 函数，那么在编译时无法确定数组的大小，因此会导致错误。
//如果要声明一个大小为非常量的数组，可以使用动态内存分配，如使用 new 运算符分配堆上的内存，或者使用标准库提供的容器类（如 std::vector）来代替数组。
  //char st[11] = "fundamental";  // Error: the size of string is 12 with a trailing '\0'
//这个语句错误的原因是字符串字面量 "fundamental" 的长度为 12，包括表示字符串结束的空字符 '\0'。然而，数组 st 的大小被指定为 11，比字符串长度小 1。这会导致字符串无法完全存储在数组中，超出数组边界，因此会产生错误。
  return 0;
}

```

3.28

```c++
string sa[10];
int ia[10];
int main(){
  string sa2[10];
  int ia2[10];
  cout << sa << endl;
  cout << sa2 << endl;
  cout << ia << endl;
  cout << ia2 << endl;
  return 0;
}
//0x7ff68fdd8040
//0x5ffd10
//0x7ff68fdd8180
//0x5ffce0

```

3.30

```c++
int main(){
  constexpr size_t array_size = 10;
  int ia[array_size];
  for (size_t ix = 0; ix != array_size ; ++ix) {
    ia[ix] = ix +1;
    cout << ia[ix] << endl;
  }
}//ix = array——size是错误的，下标只能是0-9，10个数字
```

3.31

```c++
int main(){
  int ia[10];
  for (size_t i = 0; i < 10; ++i) {
    ia[i] = i;
  }
  return 0;
}
```

3.32

```c++
int main(){
  int ia[10];
  for (size_t i = 0; i < 10; ++i) {
    ia[i] = i;
  }
  int ia2[10];
  for (size_t i = 0; i != 10; ++i)
    ia2[i] = ia[i];

  std::vector<int> iv;
  for (int i = 0; i != 10; ++i)
    iv.push_back(i);
  return 0;
}

```

3.33

```
如果scores数组在函数内部定义，则每个元素的值是未定义的。如果scores数组在任何函数外部定义，则每个元素的值为0。
```

3.34

```
将代码中的p1移动到p2，与p1 = p2是相同的。

只要p1和p2都指向同一个数组中的元素，任何值都是合法的。
```

3.35

```c++
int ia[10];
int main(){
  int ia[10];
  for (const auto &e : ia) {
    std::cout << e << ' ';

  }
  cout << endl;
  for (auto *bg = begin(ia),*ed = end(ia);bg != ed;++bg) {
    *bg = 0;
  }
  for (const auto &e : ia) {
    cout<< e << ' ';
    cout << endl;
  }

  return 0;
}
//因为初始没有对数组进行定义，意味着ia可以是任何元素，所以会导致打印出任何值，包垃圾值和之前存储在栈上面其他变量的值
```

3.41

```c++
int ia[10] = {1,2,3,4,5,6,7,8};
  vector<int> iv(begin(ia),end(ia));
  for (const auto &i: iv) {
    cout << i <<" " << endl;

  }
```

3.42

```c++
vector<int> iv = {1,2,3,4,5,6,7,8,9};
  int ia[10];
  int *bg = ia;
  int *ed = ia + iv.size();
  for(const auto &i:iv)
    *bg++ = i;
  for ( bg = ia; bg != ed ; ++bg) {
    cout << *bg << " " << endl;
  }
```

#### ch4

4.1

```
105
```

4.2

```c++
* vec.begin()  ==>  * ((vec.begin)())
    
* vec.begin() + 1  ==>  ( * ((vec.begin)())) + 1


```

4.3

```
我认为这是一个可以接受的权衡。当一个表达式引用并修改同一个对象时，我们总是可以将该表达式分成几个表达式，以避免这种情况，除非以下情况之一：

涉及的运算符是 &&、||、条件 ?:、逗号 , 运算符之一。
修改操作数的子表达式本身是另一个子表达式的操作数。
```

4.8

```markdown
逻辑与（logical AND）和逻辑或（logical OR）运算符在求值时都会先评估左操作数，然后再评估右操作数。此外，只有在左操作数无法确定结果时才会评估右操作数。这种策略被称为短路评估（short-circuit evaluation）。

具体翻译如下：

逻辑与运算符：仅当左侧为真时，才会评估右操作数。
逻辑或运算符：仅当左侧为假时，才会评估右操作数。
等式运算符：仅当两个操作数具有相同的值时，才返回 true；否则返回 false。

简而言之，逻辑与和逻辑或运算符在求值时会根据左侧操作数的结果来决定是否继续求值右侧操作数。当左侧操作数的结果能够决定整个表达式的结果时，右侧操作数将不会被求值。这种机制有助于提高运行时的效率和避免不必要的计算。
```

4.9

```
cp 是一个指向常量字符（const char*）的指针，并且它不是 nullptr。正确。

*cp 是一个常量字符：'H'，它被明确地赋予了一个非零值。正确。

true && true => true.

翻译如下：

cp 是一个指向常量字符指针，且不为 nullptr。正确。
*cp 是一个常量字符 'H'，且它明确地赋值为一个非零值。正确。
true && true => true。
```

4.10

```c++
int i = 0;
while(cin >> i && i != 42)
```

4.11

```c++
a > b && b > c && c > d
```

4.12

```c++
i != j && j < k
```

4.13

```c++
int i;   double d;
d = i = 3.5; // i = 3, d = 3.0
i = d = 3.5; // d = 3.5, i = 3
```

4.14

```c++
if (42 = i)   // compile error: expression is not assignable
if (i = 42)   // true.
```

4.15

```c++

double dval; int ival; int *pi;
dval = ival = pi = 0;
// pi is a pointer to int.
// 不可以把指针int*的值赋给int
// correct it:
dval = ival = 0;
pi = 0;
```

4.16

```c++
if (p = getPtr() != 0)

//这个条件语句中，赋值操作符 = 的优先级比相等比较操作符 != 低。因此，它首先执行 getPtr() != 0 的比较操作，然后将比较结果赋值给变量 p。如果 getPtr() 返回一个非零值，则条件为真，否则条件为假。这可能与预期的结果不同，因为实际上我们想要将 getPtr() 的返回值赋给 p，然后判断 p 是否为非零值。要修正这个问题，可以使用括号明确指定赋值操作的优先级，如 if ((p = getPtr()) != 0)。
if (i = 1024)
// 这个条件语句中，赋值操作符 = 将整数值 1024 赋给变量 i，然后条件判断的结果是赋值操作的结果，即 1024。因此，条件始终为真，无论 i 原来的值是什么。如果你想要进行相等比较操作，应使用相等比较操作符 ==，如 if (i == 1024)。
if ((p = getPtr()) != 0)
if (i == 1024)
```

4.17

```c++
前置是递增之后的值
后置是递增之前的值
```

4.18

```c++
会得到从第二个元素开始到最后一个元素
```

4.19

```c++
ptr != 0 && *ptr++  // 检查指针 ptr 不是空指针（nullptr），并检查指针的值。
ival++ && ival // 检查 ival 和 ival+1 是否都等于零。
vec[ival++] <= vec[ival] // 首先，使用 ival 索引访问 vec 容器中的元素 vec[ival]。
    
//接着，ival 的值不会自增，因为后缀自增运算符 ++ 在此表达式中是后置的，所以 vec[ival++] 的结果仍然是 vec[ival]。
    
//最后，比较 vec[ival] 和 vec[ival+1] 的值是否满足小于或等于的关系。
// correct:
vec[ival] <= vec[ival+1]
```

4.20

 

```c++
(a) *iter++;
这个表达式是合法的。它的含义是先解引用 iter 指向的元素，然后将 iter 自增到下一个元素。这样做会返回当前元素的值，并将 iter 向后移动一个位置。
(b) (*iter)++;
这个表达式是不合法的。原因是 *iter 的结果是一个 std::string 对象，而后缀自增运算符 ++ 不能应用于 std::string 类型。
    
(c) *iter. empty();
这个表达式是合法的。它的含义是先解引用 iter 指向的元素，并返回该元素的值。然后，逗号运算符 , 用于分隔表达式，继续执行 empty() 函数调用。这假设被迭代的元素是 std::string 类型或具有 empty() 成员函数的类型。
    
(d) iter->empty();
这个表达式是合法的。它的含义是通过迭代器 iter 访问其指向的元素，并调用该元素的 empty() 成员函数。这假设被迭代的元素是 std::string 类型或具有 empty() 成员函数的类型。



(e) ++*iter;
这个表达式是不合法的。原因是 *iter 的结果是一个 std::string 对象，而前缀自增运算符 ++ 不能应用于 std::string 类型。


(f) iter++->empty();
这个表达式是合法的。它的含义是先使用迭代器 iter 访问其指向的元素，并调用该元素的 empty() 成员函数。然后，迭代器 iter 执行后缀自增运算符 ++，将迭代器移动到下一个位置。
```

4.21

```c++
std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto& i : ivec) i = (i % 2) ? (i * 2) : i;
  std::cout << std::endl;
  // Check
  for (auto i : ivec) std::cout << i << " ";
  std::cout << std::endl;
```

4.22

```c++
第二段，因为这种结构太常见，并且直观很多，不影响易读性
```

4.23

```c++
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;//错误的
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;//修改后
```

4.24

```c++
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
//这条代码使用了左结合律。根据左结合律，条件运算符 ?: 从左到右进行计算。首先，它判断 grade > 90 的结果，如果为真，则将 "high pass" 赋值给 finalgrade。如果为假，则进一步判断 grade < 60 的结果，如果为真，则将 "fail" 赋值给 finalgrade。如果两个条件都不满足，则将 "pass" 赋值给 finalgrade。

finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
//这条代码使用了右结合律。根据右结合律，条件运算符 ?: 从右到左进行计算。首先，它判断 (grade > 90) ? "high pass" : (grade < 60) 的结果，如果为真，则将 "fail" 赋值给 finalgrade。如果为假，则将 "pass" 赋值给 finalgrade。
```

4.25

```c++
'q' == 01110001

~ 'q' == ~ 00000000000000000000000001110001

~ 'q' == 11111111111111111111111110001110

//看到 的值为~ 'q'负数。左移负值具有未定义的行为 
```

4.26

```c++
本节示例中有 30 名学生。unsigned long任何机器上至少有 32 位。因此，可以确保这些位以明确定义的值开始。unsigned int保证保存 16 位的标准定义。如果unsigned int采用，结果是不确定的。
```

4.27

```c++
unsigned long ul1 = 3, ul2 = 7;//3是0011，7是0111
ul1 & ul2 // == 3，0011 & 0110，或的话是同位置同1才是1
ul1 | ul2 // == 7，0011 | 0110，0111，至少有一个是1才是1
ul1 && ul2 // == true ，两个都是真值
ul1 || ul2 // == ture，两个都是真值
```

4.28

```c++

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "bool\t\tis " << sizeof(bool) << "bytes." << endl;
    cout << "char\t\tis " << sizeof(char) << "bytes." << endl;
    cout << "wchar_t\t\tis " << sizeof(wchar_t) << "bytes." << endl;
    cout << "char16_t\tis " << sizeof(char16_t) << "bytes." << endl;
    cout << "char32_t\tis " << sizeof(char32_t) << "bytes." << endl;
    cout << "short\t\tis " << sizeof(short) << "bytes." << endl;
    cout << "int\t\tis " << sizeof(int) << "bytes." << endl;
    cout << "long\t\tis " << sizeof(long) << "bytes." << endl;
    cout << "long long\tis " << sizeof(long long) << "bytes." << endl;
    cout << "float\t\tis " << sizeof(float) << "bytes." << endl;
    cout << "double\t\tis " << sizeof(double) << "bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << "bytes." << endl;
    cout << endl;

    return 0;
}

// Print
/**************************/
// bool            is 1bytes.
// char            is 1bytes.
// wchar_t         is 2bytes.
// char16_t        is 2bytes.
// char32_t        is 4bytes.
// short           is 2bytes.
// int             is 4bytes.
// long            is 4bytes.
// long long       is 8bytes.
// float           is 4bytes.
// double          is 8bytes.
// long double     is 16bytes.
```

4.29

```c++
int x[10];   int *p = x;
  cout << sizeof(x)/sizeof(*x) << endl;
  cout << sizeof(p)/sizeof(*p) << endl;
  return 0;
//第一个结果是 10。它返回 x 中的元素数量。但第二个结果取决于你的机器。在 64 位计算机上为 2，在 32 位计算机上为 1。因为不同机器上指针的大小是不同的。
```

```markdown
指针的大小不必是 32 位 - 实现会将指针的大小设置为平台体系结构规定的任何值。在具有 64 位寻址的系统上，指针的大小通常为 64 位。

但是，您还应该注意，即使在单个实现上，不同类型的指针也可能具有不同的大小。特别是，指向成员类型的指针（我承认它们是奇怪的指针）可能与指向对象的普通旧指针具有不同的大小。

指向普通旧函数的指针也是如此 - 它们的大小可能与指向对象的指针不同（这适用于 C 和 C++）。然而，在现代桌面系统上，您通常会发现指向函数的指针与指向对象的指针大小相同。
```

4.30

```c++
sizeof x + y      // (sizeof x)+y . "sizeof" has higher precedence than binary`\+`.
sizeof p->mem[i]  // sizeof(p->mem[i])
sizeof a < b      // sizeof(a) < b
sizeof f()        // if`f()`returns`void`, this statement is undefined, otherwise it returns the size of return type.

```

4.31

```c++
我们使用前缀而不是后缀，只是因为Advice: Use Postfix Operators only When Necessaryon 4.5. Increment and Decrement Operators。

建议：仅在必要时使用 Postfix 运算符

原因很简单：前缀版本避免了不必要的工作。它递增值并返回递增的版本。后缀运算符必须存储原始值，以便它可以返回未递增的值作为结果。如果我们不需要未递增的值，则不需要后缀运算符完成额外的工作。

对于整数和指针，编译器可以优化掉这些额外的工作。对于更复杂的迭代器类型，这项额外的工作可能成本更高。通过习惯性地使用前缀版本，我们不必担心性能差异是否重要。此外——也许更重要的是——我们可以更直接地表达我们程序的意图。

所以，这只是一个好习惯。如果我们必须使用后缀版本，则无需进行任何更改。改写：

for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
这不是讨论前缀和后缀差异的合适示例。查看此页Built-in comma operator上的部分。
```

4.32

```c++
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

`ptr`并`ix`具有相同的功能。前者使用指针，后者使用数组的索引。我们使用循环来遍历数组。（只需从`ptr`和中选择一个`ix`）

4.33

```c++
someValue ? ++x, ++y : --x, --y
    与
    (someValue ? ++x, ++y : --x), --y
    效果相同，因为逗号运算符的优先级最低，
    如果 someValue 为 true，则++x，结果为y，如果 someValue 为 false，则--x，结果为--y。所以它也与：
    someValue ? (++x, y) : (--x, --y);
    
```

4.34

```c++
if (fval) // fval 转换为 bool
dval = fval + ival; //ival 转换为 fval，然后 fval add ival 转换为 double 的结果。
dval + ival * cval; // CVAL 转换为 Int，然后 int 和 ival 转换为 double。
```

4.35

```c++
char cval; int ival; unsigned int ui; float fval; double dval;
```

识别正在发生的隐式类型转换（如果有）：

```c++
cval = 'a' + 3; // ‘a’提升为 int，则 （'a' + 3）（int） 的结果转换为 char。
fval = ui - ival * 1.0; // ival 转换为 double，ui 也转换为 double。然后，双倍转换（通过截断）为浮动。
dval = ui * fval; // UI 提升为浮点数。然后，浮点数转换为双倍。
cval = ival + fval + dval;  // ival 转换为 float，然后 float 和 fval 转换为 double。最后，该双精度转换为 char（通过截断）。
```



4.36

```c++
i *= static_cast<int>(d);
```

4.37

```c++
int i; double d; const string *ps; char *pc; void *pv;
pv = (void*)ps; // pv = const_cast<string*>(ps); or pv = static_cast<void*>(const_cast<string*>(ps));
i = int(*pc);   // i = static_cast<int>(*pc);
pv = &d;        // pv = static_cast<void*>(&d);
pc = (char*)pv; // pc = reinterpret_cast<char*>(pv);
```

4.38

```c++
double slope = static_cast<double>(j/i);
//j/i是一个 int（通过截断），然后转换为 double 并分配给斜率。
```

#### ch5

5.01

null 语句是空语句。像这样：

```c++
; // null statement
```

当语言需要语句但程序逻辑不需要时，我可能会使用空语句。例如：

```c++
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

5.02

```c++
while (val <= 10)
{
    sum += val;
    ++val;
}
```

5.03

```c++
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
```

这种重写降低了代码的可读性。逗号运算符始终保证顺序并丢弃前面的结果。但这个例子没有任何意义，也令人难以理解。



5.04

解释以下每个示例，并纠正您发现的任何问题

```c++
- (a) while (string::iterator iter != s.end()) { /* . . . */ }
- (b) while (bool status = find(word)) { /* . . . */ }
     if (!status) { /* . . . */ }
```

(a) iter 没有指向任何内容。无效的。

```c++
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }

```

(b) if 语句不在 while 块中。所以`status`是无效的。如果 find(word) 返回 true，它将遍历 while 块。我们应该在一会儿之前声明状态。

```c++
bool status;
while ((status = find(word))) {/* ... */}
if (!status) {/* ... */}
```

`!status`是没有必要的。如果`status=false`，我们离开 while，且`!status`始终为真。

5.05

```c++
int main(){
      vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

  int grade{0};
  while (cin >> grade) {
    string lettergrade;
    if (grade < 60)
      lettergrade = scores[0];
    else {
      lettergrade = scores[(grade - 50) / 10];
      if (grade != 100) {
        if (grade % 10 > 7)
          lettergrade += "+";
        else if (grade % 10 < 3)
          lettergrade += "-";
      }
    }

    cout << lettergrade << endl;
  }

  return 0;


}
```

5.06

```c++
vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

  int grade{0};
  while (cin >> grade) {
//    string lettergrade;
//    if (grade < 60)
//      lettergrade = scores[0];
//    else {
//      lettergrade = scores[(grade - 50) / 10];
//      if (grade != 100) {
//        if (grade % 10 > 7)
//          lettergrade += "+";
//        else if (grade % 10 < 3)
//          lettergrade += "-";
//      }
//    }
    string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
    lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
    
    cout << lettergrade << endl;
  }

  return 0;
```

5.07

更正以下每个代码片段中的错误：

```c++
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

```c++
(a) if (ival1 != ival2) ival1 = ival2; // lost semicolon.
    else ival1 = ival2 = 0;
(b) if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
(c) int val;
    if (ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
(d) if (ival == 0)
    ival = get_value();
```

5.08

```c++
//什么是“悬空其他”？ C++ 中的 else 子句是如何解析的？
//口语术语，用于指如何处理 if 多于 else 的嵌套 if 语句的问题。在 C++ 中，else 总是与最前面的不匹配的 if 配对。
```

5.09

```c++
int main(){
  unsigned acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0;
  char ch;
  while (cin >> ch){
    if (ch == 'a')
      ++acnt;
    else if (ch == 'e')
      ++ecnt;
    else if (ch == 'i')
      ++icnt;
    else if (ch == 'o')
      ++ocnt;
    else if (ch == 'u')
      ++ucnt;
    else if (ch == 'q')
      break;
  }
  cout << "Number of vowel a: \t" << acnt << '\n' << "Number of vowel e: \t"
       << ecnt << '\n' << "Number of vowel i: \t" << icnt << '\n'
       << "Number of vowel o: \t" << ocnt << '\n' << "Number of vowel u: \t"
       << ucnt << endl;


  return 0;
}


```

5.10

```C++
//P1
int main(){
  unsigned acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0;
  char ch;
  while (cin >> ch){
    if (ch == 'a'|| ch == 'A')
      ++acnt;
    else if (ch == 'e' || ch == 'E')
      ++ecnt;
    else if (ch == 'i' || ch == 'I')
      ++icnt;
    else if (ch == 'o' || ch == 'O')
      ++ocnt;
    else if (ch == 'u' || ch == 'U')
      ++ucnt;
    else if (ch == 'q' || ch == 'Q')
      break;
  }
  cout << "Number of vowel a: \t" << acnt << '\n' << "Number of vowel e: \t"
       << ecnt << '\n' << "Number of vowel i: \t" << icnt << '\n'
       << "Number of vowel o: \t" << ocnt << '\n' << "Number of vowel u: \t"
       << ucnt << endl;


  return 0;
}
```

```C++
//P2
int main()
{
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  char ch;
//  bool quit = false;
//  while (cin >> ch && !quit)
  while (cin >> ch)
    switch (ch) {
    case 'a':
    case 'A':
      ++aCnt;
      break;
    case 'e':
    case 'E':
      ++eCnt;
      break;
    case 'i':
    case 'I':
      ++iCnt;
      break;
    case 'o':
    case 'O':
      ++oCnt;
      break;
    case 'u':
    case 'U':
      ++uCnt;
      break;
    case 'q':
    case 'Q':

      cout << "Number of vowel a(A): \t" << aCnt << '\n'
           << "Number of vowel e(E): \t" << eCnt << '\n'
           << "Number of vowel i(I): \t" << iCnt << '\n'
           << "Number of vowel o(O): \t" << oCnt << '\n'
           << "Number of vowel u(U): \t" << uCnt << endl;
      quit = true; // 设置标志变量为 true，以退出循环

      return 0;

    }




//  cout << "Number of vowel a(A): \t" << aCnt << '\n'
//       << "Number of vowel e(E): \t" << eCnt << '\n'
//       << "Number of vowel i(I): \t" << iCnt << '\n'
//       << "Number of vowel o(O): \t" << oCnt << '\n'
//       << "Number of vowel u(U): \t" << uCnt << endl;


}

```

5.11

```c++
int main()
{
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
           tabCnt = 0, newLineCnt = 0;
  char ch;
  while (cin >> std::noskipws >> ch) switch (ch) {
    case 'a':
    case 'A':
      ++aCnt;
      break;
    case 'e':
    case 'E':
      ++eCnt;
      break;
    case 'i':
    case 'I':
      ++iCnt;
      break;
    case 'o':
    case 'O':
      ++oCnt;
      break;
    case 'u':
    case 'U':
      ++uCnt;
      break;
    case ' ':
      ++spaceCnt;
      break;
    case '\t':
      ++tabCnt;
      break;
    case '\n':
      ++newLineCnt;
      break;
    case 'q':
          case 'Q':

//            cout << "Number of vowel a(A): \t" << aCnt << '\n'
//                 << "Number of vowel e(E): \t" << eCnt << '\n'
//                 << "Number of vowel i(I): \t" << iCnt << '\n'
//                 << "Number of vowel o(O): \t" << oCnt << '\n'
//                 << "Number of vowel u(U): \t" << uCnt << endl;
cout << "Number of vowel a(A): \t" << aCnt << '\n'
     << "Number of vowel e(E): \t" << eCnt << '\n'
     << "Number of vowel i(I): \t" << iCnt << '\n'
     << "Number of vowel o(O): \t" << oCnt << '\n'
     << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of space: \t"
     << spaceCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
     << "Number of new line: \t" << newLineCnt << endl;
//            quit = true; // 设置标志变量为 true，以退出循环

            return 0;
    }



  return 0;
}
```

5.12

```c++
int main()
{
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
           tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
  char ch, prech = '\0';
  while (cin >> std::noskipws >> ch) {
    switch (ch) {
    case 'a':
    case 'A':
      ++aCnt;
      break;
    case 'e':
    case 'E':
      ++eCnt;
      break;
    case 'i':
      if (prech == 'f') ++fiCnt;
    case 'I':
      ++iCnt;
      break;
    case 'o':
    case 'O':
      ++oCnt;
      break;
    case 'u':
    case 'U':
      ++uCnt;
      break;
    case ' ':
      ++spaceCnt;
      break;
    case '\t':
      ++tabCnt;
      break;
    case '\n':
      ++newLineCnt;
      break;
    case 'f':
      if (prech == 'f') ++ffCnt;
      break;
    case 'l':
      if (prech == 'f') ++flCnt;
      break;
    case 'q':
    case 'Q':
      cout << "Number of vowel a(A): \t" << aCnt << '\n'
           << "Number of vowel e(E): \t" << eCnt << '\n'
           << "Number of vowel i(I): \t" << iCnt << '\n'
           << "Number of vowel o(O): \t" << oCnt << '\n'
           << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of space: \t"
           << spaceCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
           << "Number of new line: \t" << newLineCnt << '\n' << "Number of ff: \t"
           << ffCnt << '\n' << "Number of fl: \t" << flCnt << '\n'
           << "Number of fi: \t" << fiCnt << endl;
      return 0;
    }
    prech = ch;
  }



  return 0;
}
```

5.13

```c++
//下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

```c++
//answer
(a) // Error: should have a break statement
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default : iouCnt++; break;
    }
(b) // Error: ix 不在范围内。
    unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
(c) // Error: 案例标签语法错误
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
(d) // Error: case 标签必须是常量表达式
    const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

5.14

```c++
int main()
{
  string pre_word, word, max_repeat_word;
  int repeat_times = 0, max_repeat_times = 0;

  while (cin >> word) {
    if (word == pre_word) {
      ++repeat_times;
    } else {
      repeat_times = 1;
      pre_word = word;
    }

    if (max_repeat_times < repeat_times) {
      max_repeat_times = repeat_times;
      max_repeat_word = pre_word;
    }
//    if (word == 'q')
    if (max_repeat_times > 3)
      break;
  }

  if (max_repeat_times <= 1){
    cout << "no word was repeated" << endl;
  } else {
    cout << "the word '" << max_repeat_word << "' occurred " << max_repeat_times << " times" << endl;
  }
}
```

5.15

```c++
//p1
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```

```c++
//p2
(a)int ix; // 将 ix 声明在 for 循环之前

for (ix = 0; ix != sz; ++ix) {
  // 循环体代码
}

if (ix != sz) {
  // if 语句中可以使用 ix 变量
  // ...
}
//存在一个错误，即作用域问题导致变量 ix 在 if 语句中无法访问。变量 ix 定义在 for 循环的初始化部分，并且其作用域仅限于 for 循环的花括号内部。

(b) int ix;
    for (; ix != sz; ++ix) { /* ... */ }
//少了一个，for是三个部分传入参数
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ }
//三个参数不是四个参数
```

5.16

```c++
// while idiomatic
int i;
while ( cin >> i )
    // ...

// same as for
for (int i = 0; cin >> i;)
    // ...

// for idiomatic
for (int i = 0; i != size; ++i)
    // ...

// same as while
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
//while 更好，不会陷入参数命名的问题

```

5.17

```c++
int main()
{
  vector<int> vec1{0, 1, 1, 2};
  vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

  auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
  for (decltype(vec1.size()) i = 0; i != size; ++i) {
    if (vec1[i] != vec2[i]) {
      cout << "false" << endl;
      return 0;
    }
  }
  cout << "true" << endl;
  return 0;
}
```

5.18

```c++
(a) do { // 添加了括号.{}
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);
(b) int ival;
    do {
        // . . .
    } while (ival = get_response()); // 不应在此范围内声明。，原来是有个int ival=
(c) int ival = get_response();
    do {
        ival = get_response();
    } while (ival); // IVAL 未在此范围内声明。
```

5.19

```c++
int main(){
  string rsp;
  do{
    cout << "Input two strings: ";
    string str1,str2;
    cin >> str1 >> str2;
    cout << (str1 <= str2 ? str1 : str2) << " is less than the other. "
         << "\n\n"
         << "More? Enter yes or no: ";
    cin >> rsp;
  } while (!rsp.empty() && rsp[0] == 'y');
  return 0;
}
```

5.20

```c++
int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp)
            break;
        else
            tmp = read;

    if (cin.eof())//是否到达文件末尾
        cout << "no word was repeated." << endl;
    else
        cout << read << " occurs twice in succession." << endl;
    return 0;
}
```

5.21

```c++
int main() {
  string curr, prev;
  bool no_twice = false;

  while (cin >> curr) {
    if (!isupper(curr[0])) {
      prev = "";
      continue;
    }
    if (prev == curr) {
      cout << curr << " occurs twice in succession." << endl;
      no_twice = true;
      break;
    }
    prev = curr;
  }

  if (!no_twice) cout << "no word was repeated." << endl;
}
```

5.22

```c++
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
//for代替goto
for（int sz = get_size() ;sz <= 0 ;sz = get_size())
```

5.23

```c++
int main(){
  int a,b;
  cin >> a >> b;
  cout << static_cast<double>(a) / b  <<endl;
  return 0;
}
```

5.24

```c++
int main(){
  int a,b;
  cin >> a >> b;
  if (b == 0) throw std::runtime_error("divisor is 0");
  cout << static_cast<double>(a) / b  <<endl;
  return 0;
}
```

5.25

```c++
int main(void)
{
    int a, b;
    cout << "Input two integers: ";
    while (cin >> a >> b) {
        try {
            if (b == 0) throw runtime_error("divisor is 0");
            cout << static_cast<double>(a) / b << endl;
            cout << "Input two integers: ";
        }
        catch (runtime_error err) {
            cout << err.what() ;
            cout << "\nTry Again? Enter y or n:" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else
                cout << "Input two integers: ";
        }
    }

    return 0;
}
```

#### ch6

1

```c++
形参：形参变量只有在被调用时才分配内存单元，在调用结束时， 即刻释放所分配的内存单元。因此，形参只有在函数内部有效。 函数调用结束返回主调函数后则不能再使用该形参变量。

实参：实参可以是常量、变量、表达式、函数等， 无论实参是何种类型的量，在进行函数调用时，它们都必须具有确定的值， 以便把这些值传送给形参。 因此应预先用赋值，输入等办法使实参获得确定值。
```

2.

```c++
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }//缺少返回类型
(c) int calc(int v1, int v2) { /* ... */ }//参数名字重复了
(d) double square (double x) { return x * x; }//ok
```

3.

```c++
int fact(int val)
{
    if (val == 0 || val == 1) return 1;
    else return val * fact(val-1);
}

int main()
{
    int j = fact(5);  // j equals 120, i.e., the result of fact(5)
    std::cout << "5! is " << j << std::endl;
    return 0;
}
```

4.

```c++
int fact(int val){
  int ret = 1;
  while (val > 1) ret *= val--;
  return ret;
}
void factorial_with_interacts()
{
  for (int val = 0; cout << "Enter a number within [0, 13): ", cin >> val;) {
    if (val < 0 || val > 12) continue;
    cout << val << "! =" << fact(val) << endl;
  }
}
int main()
{
  factorial_with_interacts();
}
```

5.

```c++
template <typename T>
T abs(T i)
{
    return i >= 0 ? i : -i;
}
```

6.

**局部变量：****块**内定义的变量；

**参数**：在**函数参数列表**中声明的**局部变量**

**局部静态变量**：**局部静态变量（对象）**在第一次执行通过对象的定义之前初始化。当函数结束时，**局部静态不会被破坏； 当程序终止时 ** 它们被销毁。

```c++
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```

7.

```c++
size_t generate()
{
    static size_t ctr = 0;
    return ctr++;
}
```

8.

```c++
template <typename T> T abs(T i)
{
    return i >= 0 ? i : -i;
}
```

11

```c++
void reset(int& i)
{
    i = 0;
}

int main()
{
    int i = 42;
    reset(i);
    std::cout << i << std::endl;
}
```

12

```c++
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void swap(int& lhs, int& rhs)
{
    auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    for (int left, right; cout << "Please Enter:\n", cin >> left >> right;) {
        swap(left, right);
        cout << left << " " << right << endl;
    }
}
//这个版本更简单
```



13

```c++
//前者是按照值进行传递参数，函数对形参所作的任何事都不会影响实参，
//后者是做一个引用，绑定我们传递的任何T对象
```

14

```c++
//参数应该是引用类型：
void reset(int &i)
{
    i = 0;
}
//参数不能是引用类型的
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
    std::cout << *iter << std::endl;
}
//迭代器作为非引用类型是更为合适的选择，他保证了函数的独立性，并且不会产生意外的副作用
```

15

```c++
//为什么是s对 const 的引用却occurs是普通引用？
//因为s此函数是不做更改的，但是occurs是由函数计算得到更改的
//为什么这些参数是引用，而char参数c不是？
//在这里使用 const 引用是可以的，但是char直接复制 a 会更节省内存。
//s如果我们简单地引用会发生什么？如果我们引用occurs是常量引用 会怎样？
//s可以在函数中改变，也occurs可以不改变。occurs = 0;错误也是如此。
```

16

```c++
//为什么是s对 const 的引用却occurs是普通引用？
//由于该函数不会改变参数，因此应在 string&s 之前添加“const”，否则该函数会产生误导，不能与 const string 或 const 函数一起使用。
bool is_empty(const string& s) { return s.empty(); }
```

17

```c++
不一样。对于第一个，使用了“const”，因为不需要对参数进行任何更改。对于第二个函数，不能使用“const”，因为要更改参数的内容。
```

18

```c++
bool compare(const matrix &m1,const matrix &m2);
vector<int> :: iterator change_val(int value,vector<int > ::iterator it)
 
    //迭代器两个里欸行，一个iterator 一个const_iterator
//前者可读可写，后者可读
```

19

```c++
a非法，只有一个参数
    b合法
    c合法
    d合法，但是不推荐，因为会有浮点数丢失
```

20

```c++
//使用const的时候是常量引用
  //  当你不确定是否需要修改对象时，建议使用常量引用作为函数形参。
#include <iostream>

void printNumber(const int& num) {
    std::cout << num << std::endl;
}

void modifyNumber(int& num) {
    num = 10;  // 修改传递的对象
}

int main() {
    int number = 5;

    printNumber(number);  // 使用常量引用，不修改对象
    modifyNumber(number); // 使用普通引用，修改对象
    printNumber(number);  // 对象已被修改

    return 0;
}
```

21

```c++
#include <iostream>

int LargerOne(int i, const int* const ip)
{
    return (i > *ip) ? i : *ip;
}

int main()
{
    int c = 6;
    std::cout << LargerOne(7, &c) << std::endl;
}

//可以防止指针指向的值被修改：const int* const ip 中的第一个 const 表示指针指向的值是一个常量，即不能通过 ip 修改所指向的整数值。这样可以提供额外的安全性，防止无意中修改了指针所指向的值。
//可以防止指针指向其他对象：第二个 const 表示指针本身是一个常量，即指针 ip 不能指向其他对象。这意味着一旦 ip 被初始化为某个地址，就不能再指向其他地址。这样可以避免在后续代码中无意中修改指针指向的对象。
```

22

```c++
void swap(const int*& lhs, const int*& rhs)
{
    auto temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    const int i = 42, j = 99;
    auto lhs = &i;
    auto rhs = &j;
    swap(lhs, rhs);
    std::cout << *lhs << " " << *rhs << std::endl;
}
```

23

```c++
#include <iostream>

using std::begin;
using std::cout;
using std::end;
using std::endl;

void print(int* const pi)
{
    if (pi) cout << *pi << endl;
}

void print(const char* p)
{
    if (p)
        while (*p) cout << *p++;
    cout << endl;
}

void print(const int* beg, const int* end)
{
    while (beg != end) cout << *beg++ << " ";
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
    cout << endl;
}
//size_t size这种就是给
 
void print(const int (&arr)[2])
{
    for (auto i : arr) cout << i << " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    char ch[5] = "pezy";

    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j) - begin(j));
    print(const_cast<const int(&)[2]>(j));
}
```

24

```c++
//数组有两个特殊属性，它们影响我们如何定义和使用对数组进行操作的函数：我们无法复制数组，并且当我们使用数组时，它（通常）会转换为指针。
所以我们不能按值传递数组，当我们将数组传递给函数时，我们实际上传递了一个指向数组第一个元素的指针。
    
    在这个问题中，const int ia[10]实际上与 相同const int*，并且数组的大小无关紧要。我们可以通过const int ia[3]或者const int ia[255]，没有区别。如果我们想传递一个大小为 10 的数组，我们应该像这样使用引用：
void print10(const int (&ia)[10]) { /*...*/ }
```

25-26

```c++
int main(int argc,char** argv)
{
  string str;
  for (int i = 1; i != argc; ++i) {
    str += argv[i];
    str += " ";
  }
  cout << str << endl;
}
```



27

```c++
int sum(const std::initializer_list<int>& il)
{
  int sum = 0;
  for (auto i : il) sum += i;
  return sum;
}

int main(void)
{
  std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
}
```

28

```c++
elem循环中的类型for是const std::string&。
```

29

```c++
取决于 的元素类型initializer_list。当类型为PODType时，不需要引用。因为复制成本低廉POD（例如）。否则，使用reference( )是更好的选择。int const
```

30

```c++
非空函数“str_subrange”应该返回一个值。 // 错误 #1

控制可能到达非 void 函数的末尾。 // 错误 #2
```

31

```c++
//什么情况下返回的引用无效?什么情况下返回常量的引用无效?
//返回局部变量的引用：当函数返回一个指向局部变量的引用时，该局部变量的生命周期在函数结束后结束，引用将指向无效的内存位置。这会导致未定义行为。
  int& getLocalRef() {
  int x = 5;
  return x;  // 返回局部变量的引用
}

int main() {
  int& ref = getLocalRef();  // 引用指向无效的内存位置
  // ...
}  
    
//返回临时对象的引用：当函数返回一个指向临时对象的引用时，临时对象的生命周期仅限于表达式的求值过程。在表达式求值完成后，临时对象将被销毁，引用将指向无效的内存位置。

const std::string& getTempRef() {
  return "temporary string";  // 返回临时字符串的引用
}

int main() {
  const std::string& ref = getTempRef();  // 引用指向无效的内存位置
  // ...
}

//返回常量的引用无效的情况包括：
//返回指向非常量的引用，但将其绑定到常量引用：如果函数返回一个指向非常量的引用，但将其绑定到常量引用变量上，那么通过该常量引用修改变量的值将导致编译错误。
int x = 5;

const int& getRefToNonConst() {
  return x;  // 返回非常量的引用
}

int main() {
  const int& ref = getRefToNonConst();  // 将非常量引用绑定到常量引用变量
  // ref = 10;  // 编译错误，无法通过常量引用修改变量的值
}

//返回常量的引用，并尝试修改其值：如果函数返回一个指向常量的引用，并尝试通过该引用修改其值，将导致编译错误。

const int& getConstRef() {
  static const int x = 5;
  return x;  // 返回常量的引用
}

int main() {
  const int& ref = getConstRef();
  // ref = 10;  // 编译错误，无法通过常量引用修改常量的值
}


```

33

```c++
using std::cout;
using std::vector;
using Iter = vector<int>::iterator;

void print(Iter beg, Iter end)
{
    if (beg != end) {
        cout << *beg << " ";
        print(std::next(beg), end);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec.begin(), vec.end());
}
```

34

```c++
//当递归终止条件变为 时var != 0，可能会发生两种情况： 
  //  第一种情况：如果参数为正，则递归在 0 处停止。这正是@shbling 所指出的。
  //  情况 2：如果参数为负，则递归将永远不会停止。结果，就会发生堆栈溢出。

```

35

```c++
递归函数将始终用作val参数。会发生递归循环。
```

36

```c++
string (&func(string (&arrStr)[10]))[10]
```

37

```c++
using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);
```

38

```c++
decltype(arrStr)& arrPtr(int i)
{
          return (i % 2) ? odd : even;
}
```

39

```c++
a.非法的（因为签名相同
    b. 非法的（错误在，必须有不同给调用左区分，应该停工不同的函数铭或者参数类型，顺序，个数
    c. 合法的（
```

40

```c++
char *init(int ht=24,int wd,char bckgrnd);//像这样的是错误的
//如果前面给bckgrnd = "a"这样，下面是正确的
char* init(int wd, int ht = 24, char bckgrnd);//正确的
char* init(int ht = 24, int wd = 0, char bckgrnd);//正确的
因为一个默认值后面的参数必须有默认参数值，这是因为在函数调用时，参数的传递是按照位置顺序进行的，没有默认参数值的参数必须在有默认参数值的参数之前。
    否则就是全部有参数或者全部无参数
```

41

```c++
a，非法的，对于给定的函数声明 char* init(int ht, int wd = 80, char bckgrnd = ' ');，在调用函数 init() 时将会出错。

调用 init() 时出错的原因是函数声明中的第一个参数 ht 没有默认参数值，而在函数调用中没有为其提供参数值。

默认参数的作用是在函数调用时，如果没有提供对应的参数值，将使用默认参数值作为替代。但是，对于没有默认参数值的参数，必须显式地在函数调用中提供参数值，否则将会导致编译错误。
    b,合法的
c,按顺序提供，第一个时14，第二个时42，wd将设置为‘*’
```

42

```c++
string make_plural(size_t ctr,const string &word ,const string &ending = "s"){
  return (ctr>1)?word+ending:word;
}
int main()
{
  cout << "singual: " << make_plural(1, "success", "es") << " "
       << make_plural(1, "failure") << endl;
  cout << "plural : " << make_plural(2, "success", "es") << " "
       << make_plural(2, "failure") << endl;
}
```

43

```c++
内联函数一般是塞在头文件，函数声明也是头文件
```

44

```c++
inline bool isShoter(const string & s1,const string& s2){
  return s1.size() < s2.size();
}

int main()
{
  std::cout << isShoter("pezy", "mooophy") << std::endl;
}
```

45

```c++
练习 6.38和练习 6.42中arrPtr的函数应定义为。但练习 6.4中的函数不应该这样。因为它只被调用一次并且函数中的代码太多。make_pluralinlinefunc
```

46

```c++
不能，因为constexpr函数是用来返回字面值类型，例如int，char这种的，string是标准库语言，不是字面值类型
```

47

```c++
void printVec(vector<int>& vec)
{
#ifndef NDEBUG
  cout << "vector size: " << vec.size() << endl;
#endif
  if (!vec.empty()) {
    auto tmp = vec.back();
    vec.pop_back();
    printVec(vec);
    cout << tmp << " ";
  }
}
int main()
{
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  printVec(vec);
  cout << endl;
}
```

48

```c++
这个循环让用户一直输入一个单词，直到找到该单词。

这不是一个很好的用途assert。该assert宏通常用于检查“不可能发生”的情况。但当assert用户直接输入时总会发生这种情况EOF。这种行为很自然，所以检查没有意义。使用assert(!cin || s == sought)越多越好。
```

49

候选函数：

> 解析函数调用时考虑的函数集。 （具有调用中使用的名称的所有函数，其声明在调用时处于作用域内。）

可行的功能：

> 可以匹配给定调用的候选函数的子集。它具有与调用的参数相同数量的参数，并且每个参数类型都可以转换为相应的参数类型。

50

（a）非法。2.56 匹配`double`，但 42 匹配`int`。

(b) 匹配`void f(int)`。

（c）匹配`void f(int, int)`。

（d）`void f(double, double = 3.14)`。

52

```c++
(a) manip('a', 'z'):

第一个参数：字符字面值 'a' 的类型是 char，与 int 参数不匹配。
标准转换（Standard Conversion）：字符类型可以隐式地转换为整数类型。
第二个参数：字符字面值 'z' 的类型是 char，与 int 参数不匹配。
标准转换：字符类型可以隐式地转换为整数类型。
因此，两个字符字面值都会经过标准转换，将它们从 char 类型转换为 int 类型。

(b) manip(55.4, dobj):

第一个参数：浮点字面值 55.4 的类型是 double，与 int 参数不匹配。
标准转换：浮点类型可以隐式地转换为整数类型。
第二个参数：全局变量 dobj 的类型是 double，与 int 参数不匹配。
用户定义的转换（User-defined Conversion）：如果存在从 double 到 int 的用户定义的转换函数，可以进行转换。
```

53



```c++
(a) //没有影响，根据实参类型，可以是const型也可以是非const型
	int calc(int &, int &);
	int calc(const int &, const int &);
(b) //没有影响，根据实参类型，可以是const型也可以是非const型
	int calc(char*, char*);
	int calc(const char*, const char*);
(c) //不合法，实参是char*型时，不确定是哪个函数
	int calc(char*, char*);
	int calc(char* const, char* const);

```

54

```c++
int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

然后，定义了以下类型别名：

- `pFunc1`：使用 `decltype` 推导出函数 `func` 的指针类型，即 `int (*)(int, int)`。
- `pFunc2`：使用 `typedef` 定义的函数指针类型，与 `pFunc1` 相同。
- `pFunc3`：使用函数指针语法定义的函数指针类型，即 `int (*)(int, int)`。
- `pFunc4`：使用函数类型语法定义的函数指针类型，即 `int(int, int)`。
- `pFunc5`：使用 `typedef` 定义的函数指针类型，与 `pFunc4` 相同。
- `pFunc6`：使用 `decltype` 推导出函数 `func` 的类型，即 `int(int, int)`。

接下来，定义了多个向量，每个向量的元素类型是不同的函数指针类型：

- `std::vector<pFunc1>`：元素类型是 `pFunc1`，即 `int (*)(int, int)`。
- `std::vector<pFunc2>`：元素类型是 `pFunc2`，即 `int (*)(int, int)`。
- `std::vector<pFunc3>`：元素类型是 `pFunc3`，即 `int (*)(int, int)`。
- `std::vector<pFunc4*>`：元素类型是 `pFunc4*`，即 `int (*)(int, int)*`，函数指针的指针类型。
- `std::vector<pFunc5>`：元素类型是 `pFunc5`，即 `int (*)(int, int)`。
- `std::vector<pFunc6*>`：元素类型是 `pFunc6*`，即 `int (*)(int, int)*`，函数指针的指针类型。





当我们看到这些代码中的不同指针类型时，可以根据以下几个要点来进行分辨：

1. `pFunc1`、`pFunc2`、`pFunc6*`：这些类型使用了 `decltype(func) *` 或 `decltype(func)` 来定义指针类型。这表示它们是函数指针类型，可以用来指向具有相同函数签名的函数。例如，`pFunc1` 和 `pFunc2` 都是指向具有函数签名 `int(int, int)` 的函数指针类型，而 `pFunc6*` 是指向具有函数签名 `int(int, int)` 的函数指针的指针类型。
2. `pFunc3`：这个类型使用了函数指针语法 `int (*)(int a, int b)` 来定义指针类型。它表示一个指向具有函数签名 `int(int, int)` 的函数指针。
3. `pFunc4`：这个类型使用了函数类型语法 `int(int a, int b)` 来定义指针类型。请注意，这种语法在 C++ 中并不常见，但是在某些上下文中可以用于声明函数指针类型。它也表示一个指向具有函数签名 `int(int, int)` 的函数指针。
4. `pFunc5`：这个类型使用了 `typedef` 来定义函数指针类型，它与 `pFunc4` 具有相同的函数签名 `int(int, int)`。
5. `std::vector` 中的模板参数：这些模板参数指定了向量中元素的类型。根据不同的指针类型定义，我们可以得出以下规律：
   - `std::vector<pFunc1>`：元素类型为 `pFunc1`，即 `int (*)(int, int)`，表示存储指向具有函数签名 `int(int, int)` 的函数指针的向量。
   - `std::vector<pFunc2>`：元素类型为 `pFunc2`，即 `int (*)(int, int)`，与 `pFunc1` 相同。
   - `std::vector<pFunc3>`：元素类型为 `pFunc3`，即 `int (*)(int, int)`，表示存储指向具有函数签名 `int(int, int)` 的函数指针的向量。
   - `std::vector<pFunc4*>`：元素类型为 `pFunc4*`，即 `int (*)(int, int)*`，表示存储指向具有函数签名 `int(int, int)` 的函数指针的指针的向量。
   - `std::vector<pFunc5>`：元素类型为 `pFunc5`，即 `int (*)(int, int)`，表示存储指向具有函数签名 `int(int, int)` 的函数指针的向量。
   - `std::vector<pFunc6*>`：元素类型为 `pFunc6*`，即 `int (*)(int, int)*`，表示存储指向具有函数签名 `int(int, int)` 的函数指针的指针的向量。







66

```c++
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main(){
  int func(int a, int b);

  using pFunc1 = decltype(func) *;
  typedef decltype(func) *pFunc2;
  using pFunc3 = int (*)(int a, int b);
  using pFunc4 = int(int a, int b);
  typedef int(*pFunc5)(int a, int b);
  using pFunc6 = decltype(func);



  std::vector<pFunc1> vec1;
  std::vector<pFunc2> vec2;
  std::vector<pFunc3> vec3;
  std::vector<pFunc4*> vec4;
  std::vector<pFunc5> vec5;
  std::vector<pFunc6*> vec6;
  
  std::vector<decltype(func) *> vec{add, subtract, multiply, divide};
  for (auto f : vec)
    std::cout << f(2, 2) << std::endl;

}


```

#### ch7

2

```c++
#ifndef CP5_ex7_02_h
#define CP5_ex7_02_h

#include <string>

// Add the combine and isbn members to the Sales_data
struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
```

5

```c++
#include <string>

class Person {
    std::string name;
    std::string address;

public:
    const std::string& getName() const { return name; }
    const std::string& getAddress() const { return address; }
};

//是的，参数列表后面的 const 表示这是一个指向常量的指针。
//这些函数可以读取但不能修改调用它的对象的数据成员。
```

09

```c++
#include <string>
#include <iostream>

struct Person {
    const std::string& getName() const { return name; }
    const std::string& getAddress() const { return address; }

    std::string name;
    std::string address;
};

std::istream& read(std::istream& is, Person& person)
{
    is >> person.name >> person.address;
    if (!is) person = Person();
    return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
    os << person.name << " " << person.address;
    return os;
}

```

10

```c++
//等价于
std::istream &firstStep = read(cin, data1);
std::istream &secondStep = read(firstStep, data2);
if (secondStep)
    
    //该语句的条件是一次if读取两个对象。Sales_data
```

11

```c++
int main()
{
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("0-201-78345-X");
    print(std::cout, item2) << std::endl;

    Sales_data item3("0-201-78345-X", 3, 20.00);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;
}
```

13

```c++
int main()
{
    Sales_data total(std::cin);
    if (!total.isbn().empty()) {
        std::istream& is = std::cin;
        while (is) {
            Sales_data trans(is);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
```

14

```c++
Sales_data() : units_sold(0) , revenue(0){}
```

15

```c++
#include <string>
#include <iostream>

struct Person;
istream read(istream ,Person &);
struct Person{
    Person() = default;
    Person(const std::string sname, const std::string saddr)
        : name(sname), address(saddr)
    {
    }
    Person(std::istream& is) { read(is, *this); }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

    std::string name;
    std::string address;
}
std::istream& read(std::istream& is, Person& person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
    os << person.name << " " << person.address;
    return os;
}

```

16

```c++
question：在类的定义中对于访问说明符出现的位置和次数有限定吗?如果有，是什么?什么样的成员应该定义在 public 说明符之后?什么样的成员应该定义在
private 说明符之后

answer：
对于访问说明符出现的频率没有限制。指定的访问级别一直有效，直到下一个访问说明符或类主体结束。

程序所有部分都可以访问的成员应该在公共说明符之后定义。

类的成员函数可以访问但使用该类的代码不能访问的成员应该在 private 说明符后定义。
```

17

```c++
class使用和使用struct定义类之间的唯一区别是默认访问级别。（ class：private，struct：public）
```

18

**封装的含义**

`class`使用和使用`struct`定义类之间的唯一区别是默认访问级别。（ `class`：private，`struct`：public）

用处：

重要优点：

- 用户代码不能无意中破坏封装对象的状态。
- 封装类的实现可以随着时间而改变，而不需要改变用户级代码。



19



- `public`包括：构造函数`getName()`，，`getAddress()`。
- `private`包括：`name`，`address`。

接口应该定义为公共的，数据不应该暴露给类的外部。



20



`friend`是类授予其非公共成员访问权限的一种机制。它们具有与成员相同的权利。

**优点**：

- 有用的函数可以在类范围内引用类成员，而无需在其前面明确加上类名。
- 您可以方便地访问所有非公开成员。
- 有时，对于class用户来说更具可读性。

**缺点**：

- 减少了封装性，从而降低了可维护性。
- 代码详细程度、类内部的声明、类外部的声明。



24

```c++
#include <string>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
    } // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


```

