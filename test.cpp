//
// Created by 15525 on 2024/6/4.
//
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
//bool compare(int a , int b)
//{
//  cout << "compa" << endl;
//  return  a>b;
//}
//bool compare(double a , double b)
//{
//  cout << "compa double" << endl;
//  return  a>b;
//}
//
//bool compare(char *a , char *b)
//{
//  cout << "compa char*" << endl;
//  return  a>b;
//}
//int main(){
////  bool compare(int a,int b);
////  bool compare(int a,double b);
////  bool compare(char *a , char *b);
////  compare(10,12);
////  compare(17.52,15.2);
////  compare("a","b");
////cout << "------------------------------------------"<<endl;
////  int a = 10;
////   int *p = &a;
////  const int **q = &p;
////  cout << **q;
////  int *p = (int *)malloc(sizeof (int));
////  if(p == nullptr)
////  {
////    return -1;
////
////  }
////  *p = 20;
////  free(p);
////
////
////  int *p1 = new int(20);
////
////  delete p1;
////  int *q1 = new int[20]();
////  delete[]q1;
//
//  int *p1 = new int(20);
//  cout << p1 <<endl;
//  cout << *p1 <<endl;
//  int *p2 = new (nothrow) int;
//  cout << p2 <<endl;
//  cout << *p2 <<endl;
//  const int *p3 = new const int(40);
//  cout << p3 <<endl;
//  cout << *p3 <<endl;
//  //定位new
//  int data = 0;
//  int *p4 = new (&data) int(50);//意思就是指定的内存块，定为int类型的值，值为50
//  cout << data <<endl;
//
//  return 0;
//}

class SeqStack
{
public:
  void init(int size = 10)
  {
    _pstack = new int[size]; // 动态分配大小为 size 的整型数组作为栈的存储空间
    _top = -1; // 初始化栈顶指针为 -1，表示栈为空
    _size = size; // 记录栈的总大小
  }

  void release(){
    delete[] _pstack; // 释放动态分配的数组内存
    _pstack = nullptr; // 将指针置空，避免悬空指针的问题
  }

  void push(int val)
  {
    if (full()) // 检查栈是否已满，如果已满则进行扩容
      resize();
    _pstack[++_top] = val; // 将新元素 val 入栈，同时栈顶指针加一
  }

  void pop()
  {
    if (empty()) // 检查栈是否为空，如果为空则不执行出栈操作
      return;
    --_top; // 栈顶指针减一，表示将栈顶元素出栈
  }

  int top()
  {
    return _pstack[_top]; // 返回栈顶元素的值，但不修改栈顶指针
  }

  bool empty() { return _top == -1; } // 检查栈是否为空，栈空时栈顶指针为 -1

  bool full() { return _top == _size - 1; } // 检查栈是否已满，栈满时栈顶指针为总大小减一

private:
  int* _pstack; // 动态开辟数组，用于存储顺序栈的元素
  int _top;    // 指向栈顶元素的位置
  int _size;   // 数组扩容的总大小

  void resize()
  {
    int* ptmp = new int[_size * 2]; // 创建一个新的两倍大小的数组
    for (int i = 0; i < _size; ++i) {
      ptmp[i] = _pstack[i]; // 将旧数组中的元素复制到新数组
    }
    delete[] _pstack; // 释放旧数组的内存
    _pstack = ptmp; // 更新指针，指向新数组
    _size *= 2; // 更新栈的总大小为新数组的大小
  }
};