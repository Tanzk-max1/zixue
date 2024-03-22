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


//void func(int &a)
//{
//  cout << "func (int &a) 调用 " << endl;
//}
//
//void func(const int &a)
//{
//  cout << "func (const int &a) 调用 " << endl;
//}
//
//
//void func2(int a, int b = 10)
//{
//  cout << "func2(int a, int b = 10) 调用" << endl;
//}
//
//void func2(int a)
//{
//  cout << "func2(int a) 调用" << endl;
//}
//class Person{
//  //姓名 公共权限
//public:
//  string m_Name;
//
//protected:
//  string m_car;
//
//private:
//  int m_Password;
//
//public:
//  void func(){
//    m_Name = "张三";
//    m_car = "拖拉机";
//    m_Password = 1213456;
//  }
//};



//class Person{
//public:
//  void  setName(string name){
//    m_Name = name;
//  }
//  string getName()
//  {
//    return  m_Name;
//  }
//
//  int getAge(){
//    return m_Age;
//  }
//
//  void setAge(int age){
//    if (age < 0 || age > 150){
//      cout << "hahahhah" << endl;
//      return;
//    }
//    m_Age = age;
//  }
//
//  void setLover(string lover){
//    cout << "sahfui" <<endl;
//
//    m_Lover = lover;
//
//
//
//  }
//  string getLover()
//  {
//    return  m_Lover;
//  }
//
//private:
//  string m_Name;
//  int m_Age;
//  string m_Lover;
//
//};


//class Student{
//public:
//
//  string m_name;
//  int m_id;
//
//  void setName(string name){
//    m_name = name;
//
//  }
//  void setId(int id){
//    m_id = id;
//  }
//  void showStudent(){
//    cout << "dddd" << m_name << "id: " << m_id <<endl;
//  }


//class Person{
//public:
//  string m_name;
//
//  void showStudent(string m_car) {
//    cout << "car:" << m_car << endl;
//  }
//
//protected:
//  string m_car;
//
//
//private:
//  int m_password;
//
//public:
//  void func(){
//    m_name = "zhangsan ";
//    m_car = "tuolaji ";
//    m_password = 123456;
//  }
//};

class c1{
  int m_a;
};

struct c2{
  int m_a;
};


int main() {
  c1 c3;

  c2 c4;
  c4.m_a = 10;

  return 0;


}
