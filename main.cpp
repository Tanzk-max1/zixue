#include <iostream>
using namespace std;

//int& test01(){
//  int a = 10;
//  return a; //因为是一个局部变量，局部变量的话在完成引用之后就要被销毁，如果要被合理使用只能是静态变量进行迁移
//}

//int& test02(){
//  static int a = 20;
//  return a;
//}
//
//void showValue(const int& v){
//  cout << v << endl;
//}
//
//
//
//int func2(int a = 10,int b = 10);
//int func2(int a,int b){
//  return a+b;
//}

//void func(int a, int) {
//  cout << "this is func" << endl;
//}


void func(int &a)
{
  cout << "func (int &a) 调用 " << endl;
}

void func(const int &a)
{
  cout << "func (const int &a) 调用 " << endl;
}


void func2(int a, int b = 10)
{
  cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
  cout << "func2(int a) 调用" << endl;
}

int main() {

  int a = 10;
  func(a); //调用无const
  func(10);//调用有const
  func2(11,8748);
  return 0;
}
