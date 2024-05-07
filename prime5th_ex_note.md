

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

```c++

```

5.08

5.09

5.10

5.11

5.12

5.13

5.14

5.15

5.16

5.17

5.18

5.19

5.20

5.21

5.22

5.23

5.24

5.25

