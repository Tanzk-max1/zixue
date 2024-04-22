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

