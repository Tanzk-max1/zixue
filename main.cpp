#include <iostream>
using namespace std;

//int& test01(){
//  int a = 10;
//  return a; //因为是一个局部变量，局部变量的话在完成引用之后就要被销毁，如果要被合理使用只能是静态变量进行迁移
//}

int& test02(){
  static int a = 20;
  return a;
}

int main() {

//    int & ref = test01();
//    cout << "ref = " << ref << endl;
//    cout << "ref = " << ref << endl;


//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl;

    int & ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;//此处做了左值
    cout << "ref21 = " << ref2 << endl;
    cout << "ref21 = " << ref2 << endl;



    return 0;

}
