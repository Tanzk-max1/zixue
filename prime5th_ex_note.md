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

