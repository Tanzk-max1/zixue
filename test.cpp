////
//// Created by 15525 on 2024/6/4.
////
//#include <iostream>
//#include <string>
//#include <typeinfo>
//using namespace std;
////bool compare(int a , int b)
////{
////  cout << "compa" << endl;
////  return  a>b;
////}
////bool compare(double a , double b)
////{
////  cout << "compa double" << endl;
////  return  a>b;
////}
////
////bool compare(char *a , char *b)
////{
////  cout << "compa char*" << endl;
////  return  a>b;
////}
////int main(){
//////  bool compare(int a,int b);
//////  bool compare(int a,double b);
//////  bool compare(char *a , char *b);
//////  compare(10,12);
//////  compare(17.52,15.2);
//////  compare("a","b");
//////cout << "------------------------------------------"<<endl;
//////  int a = 10;
//////   int *p = &a;
//////  const int **q = &p;
//////  cout << **q;
//////  int *p = (int *)malloc(sizeof (int));
//////  if(p == nullptr)
//////  {
//////    return -1;
//////
//////  }
//////  *p = 20;
//////  free(p);
//////
//////
//////  int *p1 = new int(20);
//////
//////  delete p1;
//////  int *q1 = new int[20]();
//////  delete[]q1;
////
////  int *p1 = new int(20);
////  cout << p1 <<endl;
////  cout << *p1 <<endl;
////  int *p2 = new (nothrow) int;
////  cout << p2 <<endl;
////  cout << *p2 <<endl;
////  const int *p3 = new const int(40);
////  cout << p3 <<endl;
////  cout << *p3 <<endl;
////  //定位new
////  int data = 0;
////  int *p4 = new (&data) int(50);//意思就是指定的内存块，定为int类型的值，值为50
////  cout << data <<endl;
////
////  return 0;
////}
//
#include <iostream>
using namespace std;
//class SeqStack
//{
//public:
//  void init(int size = 10)
//  {
//    _pstack = new int[size]; // 动态分配大小为 size 的整型数组作为栈的存储空间
//    _top = -1; // 初始化栈顶指针为 -1，表示栈为空
//    _size = size; // 记录栈的总大小
//  }
//  SeqStack(int size = 10)
//  {
//    cout << this << " SeqStack()" << endl;
//    _pstack = new int[size]; // 动态分配大小为 size 的整型数组作为栈的存储空间
//    _top = -1; // 初始化栈顶指针为 -1，表示栈为空
//    _size = size; // 记录栈的总大小
//  }
//  SeqStack(const SeqStack &src)
//  {
//    cout << this << " &src" <<endl;
//    _pstack = new int[src._size];
//    for (int i = 0; i < src._top; ++i) {
//      _pstack[i] = src._pstack[i];
//    }
//    _top = src._top;
//    _size = src._size;
//  }
//  ~SeqStack()
//  {
//    cout << this << " ~SeqStack()" << endl;
//    delete[] _pstack; // 释放动态分配的数组内存
//    _pstack = nullptr; // 将指针置空，避免悬空指针的问题
//  }
//  //fu'zhi
//  void operator = (const SeqStack &src)
//  {
//    cout << " operator" << endl;
//    if (this == &src)
//      return;//防止自赋值
//    delete[]_pstack;
//    _pstack = new int[src._size];
//    for (int i = 0; i <= src._top; ++i) {
//      _pstack[i] = src._pstack[i];
//    }
//    _top = src._top;
//    _size = src._size;
//  }
//
////  void release(){
////    delete[] _pstack; // 释放动态分配的数组内存
////    _pstack = nullptr; // 将指针置空，避免悬空指针的问题
////  }
//
//  void push(int val)
//  {
//    if (full()) // 检查栈是否已满，如果已满则进行扩容
//      resize();
//    _pstack[++_top] = val; // 将新元素 val 入栈，同时栈顶指针加一
//  }
//
//  void pop()
//  {
//    if (empty()) // 检查栈是否为空，如果为空则不执行出栈操作
//      return;
//    --_top; // 栈顶指针减一，表示将栈顶元素出栈
//  }
//
//  int top()
//  {
//    return _pstack[_top]; // 返回栈顶元素的值，但不修改栈顶指针
//  }
//
//  bool empty() { return _top == -1; } // 检查栈是否为空，栈空时栈顶指针为 -1
//
//  bool full() { return _top == _size - 1; } // 检查栈是否已满，栈满时栈顶指针为总大小减一
//
//private:
//  int* _pstack; // 动态开辟数组，用于存储顺序栈的元素
//  int _top;    // 指向栈顶元素的位置
//  int _size;   // 数组扩容的总大小
//
//  void resize()
//  {
//    int* ptmp = new int[_size * 2]; // 创建一个新的两倍大小的数组
//    for (int i = 0; i < _size; ++i) {
//      ptmp[i] = _pstack[i]; // 将旧数组中的元素复制到新数组
//    }
//    delete[] _pstack; // 释放旧数组的内存
//    _pstack = ptmp; // 更新指针，指向新数组
//    _size *= 2; // 更新栈的总大小为新数组的大小
//  }
//};
//int main()
//{
//  SeqStack S;//没提供任何构造函数的时候，会位移生成默认的构造和析构函数，是空函数
//  SeqStack s1(10);
//  SeqStack s2 = s1;//拷贝构造函数，内存的拷贝
//  SeqStack s3(s1);//拷贝构造函数
//  s2 = s1;
//  return 0;//依次析构函数
//}


//  class MyClass {
//  private:
//    int _value;
//    const double _doubleValue;
//  public:
//    // 构造函数的初始化列表用于初始化成员变量和常量成员变量
//    MyClass(int value, double doubleValue) :_doubleValue(doubleValue) , _value(value) {
//      // 构造函数体
//    }
//
//    void printValues() {
//      std::cout << "Value: " << _value << std::endl;
//      std::cout << "Double Value: " << _doubleValue << std::endl;
//    }
//  };
//
//  int main() {
//    MyClass obj(42, 3.14);
//    obj.printValues();
//
//    return 0;
//  }

#include <cstring>
#include <string>
//class Date {
//private:
//  int _year;
//  int _month;
//  int _day;
//public:
//  Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}
//
//  void printDate() {
//    std::cout << "Date: " << _year << "-" << _month << "-" << _day << std::endl;
//  }
//};
//
//class Goods {
//private:
//  char* _name;
//  int _amount;
//  double _price;
//  Date _data;
//public:
//  Goods(char* name, int amount, double price, int year, int month, int day)
//      : _data(year, month, day), _amount(amount), _price(price) {
//    // 对 _name 进行内存分配，并将 name 的内容复制到 _name
//    _name = new char[strlen(name) + 1];
//    strcpy(_name, name);
//  }
//
//  void printDetails() {
//    std::cout << "Name: " << _name << std::endl;
//    std::cout << "Amount: " << _amount << std::endl;
//    std::cout << "Price: " << _price << std::endl;
//    _data.printDate();
//  }
//
//  ~Goods() {
//    delete[] _name; // 释放 _name 的内存
//  }
//};
//
//int main() {
//  Goods item("Example Item", 10, 2.99, 2024, 6, 12);
//  item.printDetails();
//
//  return 0;
//}

//template<typename T>
//bool compare(T a,T b)
//{
//  cout << "heloo" << endl;
//  return a>b;
//}
//int main(){
//  compare<int>(10,20);
//  compare(10,20);//模板的实参生成
//  return 0;
//}

//template<typename T>
//class SeqStack // 模板名称+类型参数列表=类名称
//{
//public:
//  SeqStack(int size=10)
//      :_pstack(new T[size]),_top(0)
//      ,_size(size);
//  ~SeqStack();
//  SeqStack(const SeqStack<T> &stack);
//  SeqStack<T>& operator=(const SeqStack<T> &stack);
//
//private:
//  T *_pstack;
//  int _top;
//  int _size;
//
//};
//int main()
//{
//  return 0;
//}
//


//类模板实现一个stl的vector向量容器

template<typename T>
class vector
{
public:
  vector(int size = 10)
  {
    _first = new T[size];
    _last = _first;
    _end = _first + size;

  }
  ~vector(){
      delete[]_first;
      _first = _last = _end = nullptr;
  };
  vector(const vector<T>)
private:
  T *_first;//指向数组起始位置
  T *_last;//有效元素后继位置
  T *_end;//数组空间的后继位置

};
int main(){

}