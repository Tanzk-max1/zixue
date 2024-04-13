#include <iostream>
#include "Sales_item.h"
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

//class Person{
//public:
//  Person() {
//    cout << "无参构造函数！" << endl;
//  }
//  Person(int a) {
//    age = a;
//    cout<< "有参构造函数!" << endl;
//
//  }
//  Person(const Person& p){
//    age = p.age;
//    cout << "拷贝构造函数!" << endl;
//  }
//
//  ~Person() {
//    cout << "析构函数!" << endl;
//  }
//
//public:
//  int age;
//};
//
//void test01()
//{
//  Person p1(18);
//  //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
//  Person p2(p1);
//
//  cout << "p2的年龄为： " << p2.age << endl;
//}
//
//void test02(){
//  Person p1;
//  Person p2(10);
//  Person p3(p2);
//
//  Person p4; //此时如果用户自己没有提供默认构造，会出错
//  Person p5(10); //此时如果用户自己没有提供有参，会出错
//  Person p6(p5); //用户自己提供拷贝构造
//}

//class Person {
//public:
//  //无参（默认）构造函数
//  Person() {
//    cout << "无参构造函数!" << endl;
//  }
//  //有参构造函数
//  Person(int a) {
//    age = a;
//    cout << "有参构造函数!" << endl;
//  }
//  //拷贝构造函数
//  Person(const Person& p) {
//    age = p.age;
//    cout << "拷贝构造函数!" << endl;
//    //p.age的意识是创建一个新的对象，然后将传入的兑现的值赋值给新的兑现，通过使用p.age，我们可以访问参数p的长远变量age，
//  }
//  //析构函数
//  ~Person() {
//    cout << "析构函数!" << endl;
//  }
//public:
//  int age;
//};
//
//void test01()
//{
//  Person p1(18);
//  //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
//  Person p2(p1);
//
//  cout << "p2的年龄为： " << p2.age << endl;
//}
//
//void test02()
//{
//  //如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
//  Person p1; //此时如果用户自己没有提供默认构造，会出错
//  Person p2(10); //用户提供的有参
//  Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供
//
//  //如果用户提供拷贝构造，编译器不会提供其他构造函数
//  Person p4; //此时如果用户自己没有提供默认构造，会出错
//  Person p5(10); //此时如果用户自己没有提供有参，会出错
//  Person p6(p5); //用户自己提供拷贝构造
//  Person p7(p6);
//}

//class Person{
//public:
//  Person(){
//    cout << "无参构造函数!" << endl;
//  }
//  Person(int age ,int height){
//    cout << "有参构造函数!" << endl;
//    m_age = age;
//    m_height = new int(height);
//  }
//  Person(const Person& p){
//    cout << "拷贝构造函数" << endl;
//    m_age = p.m_age;
//    m_height = new int (*p.m_height);
//  }
//  ~Person() {
//    cout << "析构函数!" << endl;
//    if (m_height != NULL) {
//      delete m_height;
//    }
//  }
//public:
//  int m_age ;
//  int *m_height;
//};
//
//void test01()
//{
//  Person p1(18, 180);
//
//  Person p2(p1);
//
//  cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
//
//  cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
//}

//class Person{
//public:
//  Person(int a,int b,int c) :m_A(a),m_B(b),m_C(c) {}
//    void PrintPerson(){
//      cout << "ma " <<  m_A << endl;
//      cout << "mb " <<  m_B << endl;
//      cout << "mc " <<  m_C << endl;
//    }
//  private:
//    int m_A;
//    int m_B;
//    int m_C;
//
//};

//class Phone
//{
//public:
//  Phone(string name)
//  {
//    m_PhoneName = name;
//    cout << "Phone构造" << endl;
//  }
//
//  ~Phone()
//  {
//    cout << "Phone析构" << endl;
//  }
//
//  string m_PhoneName;
//
//};
//
//
//class Person
//{
//public:
//
//  //初始化列表可以告诉编译器调用哪一个构造函数
//  Person(string name, string pName) :m_Name(name), m_Phone(pName)
//  {
//    cout << "Person构造" << endl;
//  }
//
//  ~Person()
//  {
//    cout << "Person析构" << endl;
//  }
//
//  void playGame()
//  {
//    cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
//  }
//
//  string m_Name;
//  Phone m_Phone;
//
//};
//void test01()
//{
//  //当类中成员是其他类对象时，我们称该成员为 对象成员
//  //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
//  //析构顺序与构造相反
//  Person p("张三" , "苹果X");
//  p.playGame();
//
//}


//class Person{
//public:
//  static int m_A;
//
//private:
//  static int m_B;
//
//
//};
//
//int Person::m_A = 10;
//int Person::m_B = 11;
//
//void test01(){
//  Person p1;
//  p1.m_A = 100;
//  cout << "p1.m-a = " << p1.m_A <<endl;
//
//  Person p2;
//  p2.m_A = 200;
//  cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
//  cout << "p2.m_A = " << p2.m_A << endl;
//
//  cout << "m_A = " << Person::m_A << endl;
//
//  //cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
//}

//class Person{
//public:
//  static void func()
//  {
//    cout << "func调用" << endl;
//
//    m_A = 100;
////    m_B = 100; //错误，不可以访问非静态成员变量
//
//    cout << m_A << endl;
//
//  }
//  void funb()//这个是静态的成员变量
//  {
//    cout << "func调用" << endl;
//    m_A = 100;
//    m_B = 100; //错误，不可以访问非静态成员变量
//    cout << m_A << endl;
//
//    cout << m_B  <<" M-B"<< endl;
//
//  }
//  static int m_A;
//  int m_B;
//private:
//  static void fun2(){
//    cout<<"fun2" << endl;
//
//  }
//};
//int Person::m_A = 10;
//
//void test01()
//{
//  //静态成员变量两种访问方式
//
//  //1、通过对象
//  Person p1;
//  p1.func();
//cout << "aaaaaaaaaaaaaaaaaaaaaaaaaa" <<endl;
//  //2、通过类名
//  Person::func();
//  cout << "aaaaaaaaaaaaaaaaaaaaaaaaaa" <<endl;
//  p1.funb();
//
//
//  //Person::func2(); //私有权限访问不到
//}
//
//class Person{
//public:
//    Person() {
//    mA = 0;
//
//  }
//
//  int mA;
//  static int mB;
//  void func() {
//
//    cout << "mA: " << this->mA << endl;
//    cout << "mB: " << Person::mB << endl;
//    cout << "hhh" << endl;
//
//  }
//  static void sfunc(){
//
//  }
//
//};
//
//int Person::mB = 0;
//
//
//
//class Person {
//public:
//  void ShowClassname(){
//    cout << "woshi person lei" << endl;
//  }
//  void ShowPerson() {
//    if (this == NULL) {
//      return;
//    }
//    cout << mAge << endl;
//  }
//private:
//  int mAge;
//};
//
//void test01()
//{
//  Person * p = NULL;
//  p->ShowClassname(); //空指针，可以调用成员函数
//  cout << "-----------------AAAAAAAAAAAAA-------------" << "\n" <<endl;
//  p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
//}
//
//int main() {
//
////  Person p(1, 2, 3);
////  test01();
//
//  cout << "-----------------------------------" << "\n" <<endl;
//  test01();
//  cout << "-----------------------------------" << "\n" <<endl;
//
//
//
//  return 0;
//}

//    int small = 0,big = 0;
//    std::cout << "please";
//    std::cin >> small >> big;
//
//    if (small > big){
//      int tmp = small;
//      small = big;
//      big = tmp;
//    }
//    while (small <= big){
//      std::cout << small << " ";
//      ++small;
//    }
//    std::cout <<std::endl;
//    return 0;





//int main(){
//    const double pi = 3.14;
////    double *ptr = &pi;
//    const double *cqptr = &pi;
////    *ptr = 42
//    double *cptr;
//    double dval = 3.19;
//
//    cqptr = &dval;
//    cout << cqptr <<endl;
//
//    cout << *cqptr <<endl;
//
//
//
//
//}


//class Person {
//public:
//  Person() {
//    m_A = 0;
//    m_B = 0;
//  }
//
//  //this指针的本质是一个指针常量，指针的指向不可修改
//  //如果想让指针指向的值也不可以修改，需要声明常函数
//  void ShowPerson() const {
//    //const Type* const pointer;
//    //this = NULL; //不能修改指针的指向 Person* const this;
//    //this->mA = 100; //但是this指针指向的对象的数据是可以修改的
//
//    //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
//    this->m_B = 100;
//  }
//
//  void MyFunc() const {
//    //mA = 10000;
//  }
//
//public:
//  int m_A;
//  mutable int m_B; //可修改 可变的
//};
//
//
////const修饰对象  常对象
//void test01() {
//
//  const Person person; //常量对象
//  cout << person.m_A << endl;
//  //person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
//  person.m_B = 100; //但是常对象可以修改mutable修饰成员变量
//
//  //常对象访问成员函数
//  person.MyFunc(); //常对象不能调用const的函数
//
//}


//静态成员变量是所有对象共享一个

//

typedef double wages;
typedef wages base, *p;
typedef char *pstring;
const pstring cstr = 0;
const pstring *ps;


int main(){
  using SI = Sales_item;
  wages hourly , weekly;
//  SI item; // 等价于Sales_item item
  auto item = val1 + val2;



}