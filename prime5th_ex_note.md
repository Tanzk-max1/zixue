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

