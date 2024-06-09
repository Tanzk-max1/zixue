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
int main(){
//  bool compare(int a,int b);
//  bool compare(int a,double b);
//  bool compare(char *a , char *b);
//  compare(10,12);
//  compare(17.52,15.2);
//  compare("a","b");
//cout << "------------------------------------------"<<endl;
//  int a = 10;
//   int *p = &a;
//  const int **q = &p;
//  cout << **q;
//  int *p = (int *)malloc(sizeof (int));
//  if(p == nullptr)
//  {
//    return -1;
//
//  }
//  *p = 20;
//  free(p);
//
//
//  int *p1 = new int(20);
//
//  delete p1;
//  int *q1 = new int[20]();
//  delete[]q1;

  int *p1 = new int(20);
  cout << p1 <<endl;
  cout << *p1 <<endl;
  int *p2 = new (nothrow) int;
  cout << p2 <<endl;
  cout << *p2 <<endl;
  const int *p3 = new const int(40);
  cout << p3 <<endl;
  cout << *p3 <<endl;
  //定位new
  int data = 0;
  int *p4 = new (&data) int(50);//意思就是指定的内存块，定为int类型的值，值为50
  cout << data <<endl;

  return 0;
}