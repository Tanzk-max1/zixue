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

//
//class Person {
//public:
//  Person() {
//    cout << "无参构造函数!" << endl;
//    mAge = 0;
//  }
//  Person(int age) {
//    cout << "有参构造函数!" << endl;
//    mAge = age;
//    cout << "  age : "<< age << endl;
//  }
//  Person(const Person& p) {
//    cout << "拷贝构造函数!" << endl;
//    mAge = p.mAge;
//    cout << "  age : "<<p.mAge << endl;
//  }
//  //析构函数在释放内存之前调用
//  ~Person() {
//    cout << "析构函数!" << endl;
//  }
//public:
//  int mAge;
//};
//
//void test01(){
//  Person ma;
//  Person man(100);
//  Person newman(man);
//  Person newman2 = man;
//}
//
//void doWork(Person p1){}
//void test02() {
//  Person p;
//  doWork(p);
//}
//
////3. 以值方式返回局部对象
//Person doWork2()
//{
//  Person p1;
//  cout << (int *)&p1 << endl;
//  return p1;
//}
//
//void test03()
//{
//  Person p = doWork2();
//  cout << (int *)&p << endl;
//}


int main() {

  test01();

  cout << "-----------------------------------" << "\n" <<endl;
  test02();
  cout << "-----------------------------------" << "\n" <<endl;
  test03();


  return 0;
}
