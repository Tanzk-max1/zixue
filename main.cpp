#include <iostream>
#include "vector"
#include <string>
//#include <cname>
#include "Sales_item.h"
#include "ex2_42.h"
//#include "Chapter6.h"
#include "fact.h"

using namespace std;
using std::vector;
#include <algorithm>


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

//typedef double wages;
//typedef wages base, *p;
//typedef char *pstring;
//const pstring cstr = 0;
//const pstring *ps;


//// 顶层 const 指针
//const int* ptr = nullptr;  // ptr 是一个指向常量整数的指针
//const double* constPtr = nullptr;  // constPtr 是一个指向常量 double 的常量指针
//
//int x = 5;
//const int* ptr2 = &x;  // ptr2 指向一个常量整数
//// *ptr2 = 10;  // 错误，不能通过 ptr2 修改所指向的值
////x = 10;  // 可以通过其他方式修改所指向的值
//
//
//// 顶层 const 函数参数
//void printValue(const int value) {
//  // value = 10;  // 错误，不能在函数中修改顶层 const 参数的值
//  std::cout << value << std::endl;
//}

//// 底层 const 指针
//int x = 5;
//const int* constPtr = &x;  // constPtr 是一个指向常量整数的底层 const 指针
//// *constPtr = 10;  // 错误，不能通过 constPtr 修改所指向的值
////x = 10;  // 可以通过其他方式修改所指向的值
//
//const double pi = 3.14159;
//const double* ptr = &pi;  // ptr 是一个指向常量 double 的指针
//// *ptr = 3.14;  // 错误，不能通过 ptr 修改所指向的值
//
//// 底层 const 函数参数
//void printValue(const int* ptr) {
//  // *ptr = 10;  // 错误，不能通过指针修改底层 const 参数所指向的值
//  std::cout << *ptr << std::endl;
//}

//int main() {
  //  using SI = Sales_item;
  //  wages hourly , weekly;
  //  int  val1,val2;
  //  int i = 0,&r = i;
  //  auto a = r;
  //
  //  const int ci = i ,&cr = ci;
  //  auto b = ci;
  //  auto c = cr;
  //  auto d = &i;
  //
  //
  //  const auto f = ci;
  //  cin >> val1 >> val2 ;
  ////  SI item; // 等价于Sales_item item
  //  auto item = val1 + val2;
  //  cout << item << endl;
//  int num = 5;
//  printValue(num); // 传递常量值给 printValue 函数
//  return 0;
//  int num = 5;
//  printValue(&num);  // 传递指向常量整数的指针给 printValue 函数
//  return 0;

//  int i = 0, &r = i;
//  const int ci = i, &cr = ci;
//
//  auto a = r;  // int
//  auto b = ci;  // int
//  auto c = cr;  // int
//  auto d = &i;  // int *
//  auto e = &ci;  // const int *
//  const auto f = ci;  // const int
//  auto &g = ci;  // const int &
//
//  std::cout << "a: before = " << a;
//  a = 42;  // OK
//  std::cout << "\tafter = " << a << std::endl;
//  std::cout << "b: before = " << b;
//  b = 42;  // OK
//  std::cout << "\tafter = " << b << std::endl;
//  std::cout << "c: before = " << c;
//  c = 42;  // OK
//  std::cout << "\tafter = " << c << std::endl;
//  std::cout << "d: before = " << d;
//  //d = 42;  // Error，尝试直接将整数值赋给指针变量 d，即 d = 42;，这是不允许的，因为这会将整数值赋给一个指针类型的变量，这是不匹配的。
//  std::cout << "\tafter = " << d << std::endl;
//  std::cout << "e: before = " << e;
//  //e = 42;  // Error
//  std::cout << "\tafter = " << e << std::endl;
//  std::cout << "f: before = " << f;
//  //f = 42;  // Error，const int，所以是一个常量，所以不能修改
//  std::cout << "\tafter = " << f << std::endl;
//  std::cout << "g: before = " << g;
//  //g = 42;  // Error，因为只是引用关系，引用的话具有只读的特性，因此修改是错误的
//  std::cout << "\tafter = " << g << std::endl;

//  const int i = 42;
//  auto j = i;//int
//  const auto &k = i;//const int &
//  auto *p = &i;
//  const auto j2 = i,&k2 = i;//j2为什么不同是因为会自动忽略顶层const
//  cout << *p <<endl;

//  const int ci1 = 0, &cj = ci1;
//  decltype(ci1) x = 0;     // x 类型 const int
//  decltype(cj) y = x;     // y 类型 const int&   ---y绑定到变量 x
////  decltype(cj) z;     // error ：z是一个引用，必须初始化
//  cout << ci1 << "-----" << x << "-----" << y << endl;
//  int i = 42, *p = &i , &r = i;
//  decltype(r + 0) b;
////  declval(*p) c;
//cout <<  b << endl;

//  int a = 3, b = 4;
//  decltype(a) c = a;  // `c` is `int`
//  std::cout << a << " " << b << " " << c << " " << std::endl;
//  decltype(a = b) d = a;  // `d` is `int &` to a, the expression is not evaluated
//  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 3 4 3 3

//  Sales_data data1,data2;
//  double price1,price2;
//  std::cin >> data1.bookNo >> data1.units_sold >> price1;
//  std::cin >> data2.bookNo >> data2.units_sold >> price2;
//  data1.CalcRevenue(price1);
//  data2.CalcRevenue(price2);
//
//  if (data1.bookNo == data2.bookNo)
//  {
//    data1.AddData(data2);
//    data1.Print();
//    return 0;
//  }
//  else
//  {
//    std::cerr << "Data must refer to same ISBN" << std::endl;
//    return -1;  // indicate failure
//  }

//  int sum = 0;
//  for (int val = 0; val <= 10; ++val) { sum += val;
//
//
//  }
//  cout << "sum " << sum <<endl;
//  return 0;
//  string s1,s2;
//  cin >> s1 >> s2;
//  cout << s1 << s2 << endl;
//  return 0;
//  string line;
//  getline(cin,line);
//  cout << line << endl;
//  auto len = line.size();
//  cout << size_t(len) << endl;

//  string str = "hello";
//  string phrase = "h2llo world";
//  string slang = "h1ya";
//
//  if (str == phrase) {
//    std::cout << "str1 is equal to phrase" << std::endl;
//  } else if (str != phrase) {
//    std::cout << "str1 is not equal to phrase" << std::endl;
//  }
//
//  if (str == slang) {
//    std::cout << "str1 is equal to slang" << std::endl;
//  } else if (str != slang) {
//    std::cout << "str1 is not equal to slang" << std::endl;
//  }
//
//  if (str > phrase)
//    cout << "1>2" << endl;
//  else if (str < phrase){
//    cout << "1<2" << endl;
//  }
//  if (str > slang)
//    cout << "1>3" << endl;
//  else if (str < slang){
//    cout << "1<3" << endl;
//  }
//  if (phrase > slang)
//    cout << "2>3" << endl;
//  else if (phrase < slang){
//    cout << "2<3" << endl;
//  }
//  string s1 = "hello";
//  string s6 = ", " + "world"+s1;
//  cout <<s6 << endl;

//  return 0;
//
//}

//void sum_adjacent(const std::vector<int> &v) {
//  if (v.size() < 2)
//    return;
//  for (decltype(v.size()) i = 0; i < v.size() - 1; ++i)
//    std::cout << v[i] + v[i + 1] << '\t';
//  std::cout << std::endl;
//}
//
//void sum_symmetric(const std::vector<int> &v) {
//  // If the vector has odd size, element in the middle will add to itself.
//  auto mid = (v.size() + 1) / 2;
//  for (decltype(mid) i = 0; i != mid; ++i)
//    std::cout << v[i] + v[v.size() - 1 - i] << '\t';
//  std::cout << std::endl;
//}

//int main(){
//  std::vector<int> iv;
//  int i;
//  while (std::cin >> i)
//    iv.push_back(i);
//
//  sum_adjacent(iv);
//  sum_symmetric(iv);
//
//  return 0;
//}


//int main(){
//  string word , line;
//  cout << "请输入读取字符串的方式 ：1.按照此进行读取。2.按照整行进行读取" << endl;
//  char ch;
//  cin >> ch;
//  if (ch == '1') {
//    cout << "请输入字符串：    Welcome to C++ family!  " << endl;
//    cin >> word;
//    cout << "系统读取的有效字符串是：" << endl;
//    cout << word << endl;
//    return 0;
//  }
//
//  cin.clear();
//  cin.ignore();
//  if (ch == '2') {
//    cout << "请输入字符串：    Welcome to C++ family!  " << endl;
//    getline(cin, line);
//    cout << "系统读取的有效字符串是：" << endl;
//    cout << line << endl;
//    return 0;
//  }
//  cout << "您的输入有误！";
//
//  return -1;
//
//
//}

//test 3.5
//int main(){
//  string result,s;
//  char ac = 'y';
//  while (cin >> s){
//    if (!result.size()){
//      result += s;
//    }
//    else
//      result = result + " " + s;
//    cout << "是否继续（yes or no）" << endl;
//    cin >>ac;
//    if(ac == 'y' || ac == 'Y')
//      cout << "请输入下一个字符串：" << endl;
//    else
//      break;
//
//  }
//  cout << result  << endl;
//  return 0;
//}

//int main() {
//  string str("some string");
//  for (auto c : str)
//    cout << c << endl;
//  return 0;
//}
//int main()
//{
//  string str("123456");
//  for (auto c : str)
//    cout << c << endl;
//  std::vector<double> values = {1.5, 2.7, 3.2};
//  for (auto val : values)
//  {
//    // val 的类型是 double
//    cout << val << endl;
//  }

//  string s("hello world!!!");
//  decltype(s.size()) punct_cnt = 0;
//
//  for(auto c : s)
//    if (ispunct(c))
//      ++punct_cnt;
//  cout << punct_cnt
//      << " punctuation character in " << s << endl;
//  string s = "hello world!!!";
//  if (!s.empty())//ture->1,此处为false->0,然后取反为1
//    cout << s[0] << endl;
//  for(decltype(s.size()) index = 0;
//     index!=s.size() && !isspace(s[index]); ++index)//判断体是字符串非空或者
//  {
//    s[index] = toupper(s[index]);
//    cout << s[index] ;
//
//  }
//  const string hexdigits = "0123456789ABCDEF";
//  cout <<"Enter a series of numbers between 0 and 15"
//       <<" separated by apaces. Hit ENTER when finished:"
//       << endl;
//  string result;
//  string :: size_type  n;
//  while (cin >> n)
//    if (n < hexdigits.size())
//      result += hexdigits[n];
//  cout << "your hex number is: " << result << endl;
//  return 0;
//  string s;
//  if (cin >> s){
//    for(auto &c : s){
//      c = 'X';
//    }
//  }
//  cout << s << endl;
//  return 0;
//}
//void change_with_while(){
//  string s;
//  if (cin >> s){
//    string :: size_type pos = 0;
//    while (pos!=s.size())
//      s[pos++] = 'x';
//  }
//  cout << s << endl;
//}
//void change_with_for(){
//  string s;
//  if (cin >> s) {
//    string ::size_type pos = 0;
//    for (pos; pos != s.size(); ++pos) {
//      s[pos] = 'x';
//    }
//    cout << s << endl;
//  }
//}

//void cin_zifuchuan() {
//  string s="hello,hehll!";
//    string  pos;
//    for (auto c : s) {
//      if (!s.empty() && !ispunct(c))
//        pos += c;
//
//    }
//    cout << pos ;
//}

//int main(){
//  vector<int> v2;
//  for (int i = 0; i != 100; ++i) {
//    v2.push_back(i);
//    cout << v2[i] << endl;
//  }
//  return 0;
//}
//int main(){
//  vector<unsigned> score(11,0);
//  unsigned grade;
//  while (cin>>grade){
//    if (grade > 100) {
//      cout << "成绩有误" << endl;
//      continue;
//    }
//    ++score[grade / 10];
//    cout << "分数段" << grade / 10 << " "
//         << "score : " << score[grade / 10] << endl;
//
//  }
//  return 0;
//}

//void print_vector_int(const vector<int> &v) {
//  for (const auto & elem : v)
//    std::cout << elem << " ";
//  std::cout << std::endl;
//}
//
//void print_vector_string(const vector<string> &v) {
//  for (const auto & elem : v)
//    std::cout << elem << " ";
//  std::cout << std::endl;
//}
//int main() {
//  vector<int> v1;               // 0  element
//  vector<int> v2(10);           // 10 elements, values are all 0
//  vector<int> v3(10, 42);       // 10 elements, values are all 42
//  vector<int> v4{10};           // 1  element,  value  is  10
//  vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
//  vector<string> v6{10};        // 10 elements, values are all empty string
//  vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"
//
//  print_vector_int(v1);
//  print_vector_int(v2);
//  print_vector_int(v3);
//  print_vector_int(v4);
//  print_vector_int(v5);
//  print_vector_string(v6);
//  print_vector_string(v7);
//
//  return 0;
//}

//int main(){
//  vector<string> str;
//  string s;
//  while (cin >> s)
//    str.push_back(s);
//    for (auto &a:str) {
//      for (auto &b : a)
//        b = toupper(b);
//    for (decltype(str.size()) i = 0 ; i != str.size();++i) {
//      cout << str[i] << '\t';
//      if ((i+1) % 8 == 0)
//        cout << endl;
//    }
//  }
//  return 0;
//}
//int main() {
//  std::vector<std::string> sv;
//  std::string s;
//  while (std::cin >> s){
//    sv.push_back(s);
//    for (auto &elem : sv)
//      for (auto &c : elem)
//        c = toupper(c);
//    if (sv.size() == 8)
//      break;
//
//    continue;
//
//  }
//  for (decltype(sv.size()) i = 0; i != sv.size(); ++i) {
//    std::cout << sv[i] << '\t';
//    if ((i + 1) % 8 == 0)
//      std::cout << std::endl;
//  }
//  return 0;
//}

//void sum_xianglin(vector<int> &v){
//  if (v.size()<2)
//    return;
//  for (decltype(v.size()) i = 0; i < v.size()-1; ++i) {
//    cout << v[i] + v[i + 1] << endl;
//  }
//}
//void  sum_shouwei(vector<int> &v){
//  if (v.size()<2)
//    return;
//  auto mid = (v.size() + 1)/2;
//  for (decltype(mid) i = 0; i < mid; ++i) {
//    cout << v[i] + v[v.size() - 1 - i] << '\t';
//  }
//}
//int main(){
////  vector<int> iv;
////  int i ;
////  while (cin >> i)
////    iv.push_back(i);
////  sum_adjacent(iv);
////  sum_shouwei(iv);
//
//  string text ("some string");
//
//  for (auto it = text.cbegin();it != text.cend() && !it->empty() ;++it)
//    cout << *it <<endl;
//
//
//  return 0;
//}
//void print_vector_int(const vector<int> &v){
//  for (auto it = v.cbegin(); it != v.cend() ; ++it) {
//    cout << *it << " " << endl;
//  }
//}
//void print_vector_string(const vector<string> &v){
//  for (auto it = v.cbegin(); it != v.cend(); ++it)
//    std::cout << *it << " ";
//  std::cout << std::endl;
//}
//int main(){
//  vector<int> v1;               // 0  element
//  vector<int> v2(10);           // 10 elements, values are all 0
//  vector<int> v3(10, 42);       // 10 elements, values are all 42
//  vector<int> v4{10};           // 1  element,  value  is  10
//  vector<int> v5{10, 42};       // 2  elements, values are 10 and 42
//  vector<string> v6{10};        // 10 elements, values are all empty string
//  vector<string> v7{10, "hi"};  // 10 elements, values are all "hi"
//
//  print_vector_int(v1);
//  print_vector_int(v2);
//  print_vector_int(v3);
//  print_vector_int(v4);
//  print_vector_int(v5);
//  print_vector_string(v6);
//  print_vector_string(v7);
//  return 0;
////}
//int main(){
//  vector<string> text ;
//  string line;
//  while(getline(cin,line)&& !line.empty())
//    text.push_back(line);
//  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
//    for (auto &c : *it) {
//      c = toupper(c);
//
//    }
//  for (auto &elem: text)
//    if (elem.empty())
//      cout << endl;
//    else
//      cout << elem << " ";
////  vector<string> text;
////  string s;
////  // 利用 getline 读取一句话，直接回车产生一个空串，表示段落结束
////  while (getline(cin, s))
////    text.push_back(s);              // 逐个添加到 text 中
////  // 利用迭代器遍历全部字符串，遇空串停止循环
////  for (auto it = text.begin(); it != text.end() && !it -> empty(); it++) {
////    // 利用迭代器遍历当前字符串
////    for (auto it2 = it->begin(); it2 != it->end(); it2++)
////      *it2 = toupper(*it2);       // 利用 toupper 改写成大写形式
////    cout << *it << endl;
////  }
//
//  return 0;
//}

//void sum_adjacent(const vector<int> &v){
//  if (v.size() < 2)
//    return;
//  for (auto it = v.cbegin(); it!=v.cend() - 1 ;++it) {
//    std::cout << *it + *(it + 1) << '\t';
//    std::cout << std::endl;
//  }
//}
//void sum_symmetric(const std::vector<int> &v) {
//  // If the vector has odd size, element in the middle will add to itself.
//  auto mid = v.cbegin() + (v.cend() - v.cbegin() + 1) / 2;
//  for (auto it = v.cbegin(); it != mid; ++it)
//    std::cout << *it + *(v.cend() - 1 - (it - v.cbegin())) << '\t';
//  std::cout << std::endl;
//}
////位置进行迁移
//
//
//
//int main(){
//  std::vector<int> iv;
//  int i;
//  while (std::cin >> i)
//    iv.push_back(i);
//
//  sum_adjacent(iv);
//  sum_symmetric(iv);
//
//  return 0;
//}
//string sa[10];
class Solution {
public:
  string baseNeg2(int n) {
    if (n == 0 || n == 1) {
      return to_string(n);
    }
    string res;
    while (n != 0) {
      int remainder = n & 1;
      res.push_back('0' + remainder);
      n -= remainder;
      n /= -2;
    }
    reverse(res.begin(), res.end());
    return res;


  }
};
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

//int main(){
////  int ia[10];
////  for (const auto &e : ia) {
////    std::cout << e << ' ';
////
////  }
////  cout << endl;
////  for (auto *bg = begin(ia),*ed = end(ia);bg != ed;++bg) {
////    *bg = 0;
////  }
////  for (const auto &e : ia) {
////    cout<< e << ' ';
////    cout << endl;
////  }
////  int a1[5];
////  int a2[5];
////  for (int i = 0; i != 5; ++i) {
////    cin >>a1[i];
////  }
////  for (int i = 0; i != 5; ++i) {
////    cin >>a2[i];
////  }
////  int ia[10] = {1,2,3,4,5,6,7,8};
////  vector<int> iv(begin(ia),end(ia));
////  for (const auto &i: iv) {
////    cout << i <<" " << endl;
////
////  }
////  vector<int> iv = {1,2,3,4,5,6,7,8,9};
////  int ia[10];
////  int *bg = ia;
////  int *ed = ia + iv.size();
////  for(const auto &i:iv)
////    *bg++ = i;
////  for ( bg = ia; bg != ed ; ++bg) {
////    cout << *bg << " " << endl;
////  }
////  int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
////  size_t cnt = 0;
////  for (auto &row : ia) {
////    for (auto &col : row) {
////      col = cnt ;
////      ++cnt;
////      cout << col << endl;
////    }
////  }
////  for(char a = '1';a <= '9';a++)
////    cout<<  a << endl;
////
////  return 0;
////  Solution solution;
////  int input;
////  std::cout << "Enter an integer: ";
////  std::cin >> input;
////
////  solution.baseNeg2(input);
////  int grade = 90;
////  cout <<((grade<60) ? "fail":"pass");//输出pass或者fail
////  cout << endl;
////  cout <<(grade< 60) ? "fail":"pass";//输出1或者0! "
////  cout << grade< 60 ? "fall":"pass"; //错误：试图比较 cout 和 60
////  std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
////  for (auto& i : ivec) i = (i % 2) ? (i * 2) : i;
////  string s = "wordas";
////  std::cout << std::endl;
////  // Check
//////  for (auto i : ivec) std::cout << i << " ";
////  string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;//修改后
////  std::cout <<pl << std::endl;
////  int x[10];   int *p = x;
////  cout << sizeof(x)/sizeof(*x) << endl;
////  cout << sizeof(p)/sizeof(*p) << endl;
////  constexpr int size = 5;
////  int ia[size] = {1,2,3,4,5};
////  for (int *ptr = ia, ix = 0;
////       ix != size && ptr != ia+size;
////       ++ix, ++ptr) { int a = 0;
////    a++;
////    cout << a << endl;
////  }
////  int grade;
////
////  const vector<string> scores = {"F","E","D","C","B","A"};
////  string lettergrade;
////  cin >> grade;
//////  if (grade < 60)
//////    lettergrade = scores[0];
//////  else
//////    lettergrade = scores [(grade - 50) / 10];
//////  cout << lettergrade;
////  if (grade < 60)
////    lettergrade = scores[0];
////  else {
////    lettergrade = scores [(grade - 50) / 10];//获得字母形式的成绩
////    if (grade != 100)
////      if (grade % 10 > 7)
////        lettergrade += '+';
////      else if (grade % 10 < 3)
////        lettergrade += '-';
////  }
////  cout << lettergrade;
////  vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
////
////  int grade{0};
////  while (cin >> grade) {
//////    string lettergrade;
//////    if (grade < 60)
//////      lettergrade = scores[0];
//////    else {
//////      lettergrade = scores[(grade - 50) / 10];
//////      if (grade != 100) {
//////        if (grade % 10 > 7)
//////          lettergrade += "+";
//////        else if (grade % 10 < 3)
//////          lettergrade += "-";
//////      }
//////    }
////    string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
////    lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
////
////    cout << lettergrade << endl;
////  }
//  switch (ch) { case 'a':case 'b':case 'c':case 'd':case 'e':
//  ++vowelcnt;
//  break;}
//
//
//  return 0;
//
//
//}

//int main(){
//  unsigned acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0;
//  char ch;
//  while (cin >> ch){
//    if (ch == 'a'|| ch == 'A')
//      ++acnt;
//    else if (ch == 'e' || ch == 'E')
//      ++ecnt;
//    else if (ch == 'i' || ch == 'I')
//      ++icnt;
//    else if (ch == 'o' || ch == 'O')
//      ++ocnt;
//    else if (ch == 'u' || ch == 'U')
//      ++ucnt;
//    else if (ch == 'q' || ch == 'Q')
//      break;
//  }
//  cout << "Number of vowel a: \t" << acnt << '\n' << "Number of vowel e: \t"
//       << ecnt << '\n' << "Number of vowel i: \t" << icnt << '\n'
//       << "Number of vowel o: \t" << ocnt << '\n' << "Number of vowel u: \t"
//       << ucnt << endl;
//
//
//  return 0;
//}
//int main()
//{
//  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
//  char ch;
////  bool quit = false;
////  while (cin >> ch && !quit)
//  while (cin >> ch)
//    switch (ch) {
//    case 'a':
//    case 'A':
//      ++aCnt;
//      break;
//    case 'e':
//    case 'E':
//      ++eCnt;
//      break;
//    case 'i':
//    case 'I':
//      ++iCnt;
//      break;
//    case 'o':
//    case 'O':
//      ++oCnt;
//      break;
//    case 'u':
//    case 'U':
//      ++uCnt;
//      break;
//    case 'q':
//    case 'Q':
//
//      cout << "Number of vowel a(A): \t" << aCnt << '\n'
//           << "Number of vowel e(E): \t" << eCnt << '\n'
//           << "Number of vowel i(I): \t" << iCnt << '\n'
//           << "Number of vowel o(O): \t" << oCnt << '\n'
//           << "Number of vowel u(U): \t" << uCnt << endl;
//      quit = true; // 设置标志变量为 true，以退出循环
//
//      return 0;
//
//    }
//
//
//
//
////  cout << "Number of vowel a(A): \t" << aCnt << '\n'
////       << "Number of vowel e(E): \t" << eCnt << '\n'
////       << "Number of vowel i(I): \t" << iCnt << '\n'
////       << "Number of vowel o(O): \t" << oCnt << '\n'
////       << "Number of vowel u(U): \t" << uCnt << endl;
//
//
//}

//int main()
//{
//  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
//           tabCnt = 0, newLineCnt = 0;
//  char ch;
//  while (cin >> std::noskipws >> ch) switch (ch) {
//    case 'a':
//    case 'A':
//      ++aCnt;
//      break;
//    case 'e':
//    case 'E':
//      ++eCnt;
//      break;
//    case 'i':
//    case 'I':
//      ++iCnt;
//      break;
//    case 'o':
//    case 'O':
//      ++oCnt;
//      break;
//    case 'u':
//    case 'U':
//      ++uCnt;
//      break;
//    case ' ':
//      ++spaceCnt;
//      break;
//    case '\t':
//      ++tabCnt;
//      break;
//    case '\n':
//      ++newLineCnt;
//      break;
//    case 'q':
//          case 'Q':
//
////            cout << "Number of vowel a(A): " << aCnt << ' '
////                 << "Number of vowel e(E): " << eCnt << ' '
////                 << "Number of vowel i(I): " << iCnt << ' '
////                 << "Number of vowel o(O): " << oCnt << ' '
////                 << "Number of vowel u(U): " << uCnt << endl;
//cout << "Number of vowel a(A): \t" << aCnt << '\n'
//     << "Number of vowel e(E): \t" << eCnt << '\n'
//     << "Number of vowel i(I): \t" << iCnt << '\n'
//     << "Number of vowel o(O): \t" << oCnt << '\n'
//     << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of space: \t"
//     << spaceCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
//     << "Number of new line: \t" << newLineCnt << endl;
////            quit = true; // 设置标志变量为 true，以退出循环
//
//            return 0;
//    }
//
//
//
//  return 0;
//}
//int main()
//{
//  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
//           tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
//  char ch, prech = '\0';
//  while (cin >> std::noskipws >> ch) {
//    switch (ch) {
//    case 'a':
//    case 'A':
//      ++aCnt;
//      break;
//    case 'e':
//    case 'E':
//      ++eCnt;
//      break;
//    case 'i':
//      if (prech == 'f') ++fiCnt;
//    case 'I':
//      ++iCnt;
//      break;
//    case 'o':
//    case 'O':
//      ++oCnt;
//      break;
//    case 'u':
//    case 'U':
//      ++uCnt;
//      break;
//    case ' ':
//      ++spaceCnt;
//      break;
//    case '\t':
//      ++tabCnt;
//      break;
//    case '\n':
//      ++newLineCnt;
//      break;
//    case 'f':
//      if (prech == 'f') ++ffCnt;
//      break;
//    case 'l':
//      if (prech == 'f') ++flCnt;
//      break;
//    case 'q':
//    case 'Q':
//      cout << "Number of vowel a(A): \t" << aCnt << '\n'
//           << "Number of vowel e(E): \t" << eCnt << '\n'
//           << "Number of vowel i(I): \t" << iCnt << '\n'
//           << "Number of vowel o(O): \t" << oCnt << '\n'
//           << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of space: \t"
//           << spaceCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
//           << "Number of new line: \t" << newLineCnt << '\n' << "Number of ff: \t"
//           << ffCnt << '\n' << "Number of fl: \t" << flCnt << '\n'
//           << "Number of fi: \t" << fiCnt << endl;
//      return 0;
//    }
//    prech = ch;
//  }
//
//
//
//  return 0;
//}
//int main()
//{
//  string pre_word, word, max_repeat_word;
//  int repeat_times = 0, max_repeat_times = 0;
//
//  while (cin >> word) {
//    if (word == pre_word) {
//      ++repeat_times;
//    } else {
//      repeat_times = 1;
//      pre_word = word;
//    }
//
//    if (max_repeat_times < repeat_times) {
//      max_repeat_times = repeat_times;
//      max_repeat_word = pre_word;
//    }
////    if (word == 'q')
//    if (max_repeat_times > 3)
//      break;
//  }
//
//  if (max_repeat_times <= 1){
//    cout << "no word was repeated" << endl;
//  } else {
//    cout << "the word '" << max_repeat_word << "' occurred " << max_repeat_times << " times" << endl;
//  }
//}

//int main()
//{
//  vector<int> vec1{0, 1, 1, 2};
//  vector<int> vec2{0, 1, 1, 2, 3, 5, 8};
//
//  auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
//  for (decltype(vec1.size()) i = 0; i != size; ++i) {
//    if (vec1[i] != vec2[i]) {
//      cout << "false" << endl;
//      return 0;
//    }
//  }
//  cout << "true" << endl;
//  return 0;
//}
//int main(){
//  string rsp;
//  do{
//    cout << "Input two strings: ";
//    string str1,str2;
//    cin >> str1 >> str2;
//    cout << (str1 <= str2 ? str1 : str2) << " is less than the other. "
//         << "\n\n"
//         << "More? Enter yes or no: ";
//    cin >> rsp;
//  } while (!rsp.empty() && rsp[0] == 'y');
//  return 0;
//}
//int main()
//{
//  string read, tmp;
//  while (cin >> read)
//    if (read == tmp)
//      break;
//    else
//      tmp = read;
//
//  if (cin.eof())
//    cout << "no word was repeated." << endl;
//  else
//    cout << read << " occurs twice in succession." << endl;
//  return 0;
//}
//int main() {
//  string curr, prev;
//  bool no_twice = false;
//
//  while (cin >> curr) {
//    if (!isupper(curr[0])) {
//      prev = "";
//      continue;
//    }
//    if (prev == curr) {
//      cout << curr << " occurs twice in succession." << endl;
//      no_twice = true;
//      break;
//    }
//    prev = curr;
//  }
//
//  if (!no_twice) cout << "no word was repeated." << endl;
//}
//int main(){
//  int a,b;
//  cin >> a >> b;
//  if (b == 0) throw std::runtime_error("divisor is 0");
//  cout << static_cast<double>(a) / b  <<endl;
//  return 0;
//}
//int main(void)
//{
//  int a, b;
//  cout << "Input two integers: ";
//  while (cin >> a >> b) {
//    try {
//      if (b == 0) throw runtime_error("divisor is 0");
//      cout << static_cast<double>(a) / b << endl;
//      cout << "Input two integers: ";
//    }
//    catch (runtime_error err) {
//      cout << err.what() ;
//      cout << "\nTry Again? Enter y or n:" << endl;
//      char c;
//      cin >> c;
//      if (!cin || c == 'n')
//        break;
//      else
//        cout << "Input two integers: ";
//    }
//  }
//
//  return 0;
//}

//int fact(int val){
//  if (val == 0 || val == 1) return 1;
//  else return val* fact(val-1);
//
//}

//size_t count_calls()
//{
//    static size_t ctr = 0;
//    return ++ctr;
//}
//int main(){
//    //  int j = fact(5);
//    //  cout << j << endl;
//    for (size_t i = 0; i != 10; ++i) {
//      cout << count_calls() << endl;
//
//    }
//    return 0;
//
//}
//int fact(int val){
//  int ret = 1;
//  while (val > 1) ret *= val--;
//  return ret;
//}
//void factorial_with_interacts()
//{
//  for (int val = 0; cout << "Enter a number within [0, 13): ", cin >> val;) {
//    if (val < 0 || val > 12) continue;
//    cout << val << "! =" << fact(val) << endl;
//  }
//}
//void  reset(int  &ip)
//{
////  *ip = 0;//改变指针ip所指对象的值
////  ip = 0;//只改变了ip的局部拷贝，实参未被改变
////  ip = 0;
// ip = 0;
//}
//int main()
//{
////  std::cout << "5! is " << fact(5) << std::endl;
////  std::cout << func() << std::endl;
////  std::cout << abs(-9.78) << std::endl;
//  int j = 42;
//  reset(j);
//  cout  << j << endl;
////  int *p = &n,*q = &i;
////  *p = 42;
////  p = q;
////  int &r = n;
////  r = 42;
////  cout <<" n= "<< n <<" r= "<<  r <<" i= "<< i << endl;
//
////  r = i;
////  cout <<" n= "<< n <<" r= "<<  r <<" i= "<< i << endl;
////  i = r;
////  cout <<" n= "<< n <<" r= "<<  r <<" i= "<< i << endl;
//
//}
//void print(const int *beg,const int *end) {
////  for (int i = 0; i < 10; i++) {
////    std::cout << arr[i] << " ";
////  }
////  std::cout << std::endl;
////if (arr)
////  while (*arr)
////    cout << *arr++;
//
//while (beg != end)
//  cout << *beg++ << endl;
//
//}

//void print(int (&ia)[10])
//{
////  for (size_t i = 0; i != size ; ++i) {
////    cout << ia[i] << endl;
////  }
//for (auto elem : ia) {
//  cout << elem << endl;
//}
//}


int largerone(int i,const int* const ip)
{
  return (i > *ip) ? i : *ip;
}


int main(){
//  const int ci = 42;
//  //ci是一个 const int 类型的常量，它的值为 42。当你打印 &ci 时，你会看到 ci 的地址。
//  cout << ci <<endl;
//  cout << &ci <<endl;
//
//  int i = ci;
//  cout << i <<endl;
//  int *const p = &i;
//  cout << p <<endl;
//  cout << *p <<endl;
//  *p = 0;
//  cout << *p <<endl;
//  cout << ci <<endl;
//
//  cout <<"i= "<< i <<endl;
//  cout << &i <<endl;
//int i=42;
//const int *cp=&i;//正确：但是cp不能改变i(参见2.4.2节，第56页)
//const int &r=i;//正确：但是r不能改变i(参见2.4.1节，第55页)
//cout << "r = " << r << " &r= " << &r << endl;
//const int &r2=45;// 正确：(参见2.4.1节，第55页)
//cout << "r2 = " << r2 << " &r2= " << &r2 << endl;

//错误：p的类型和cp的类型不匹配(参见2.4.2节，第56页)
//int *p=cp;
//int &r3=r; //错误：r3的类型和r的类型不匹配(参见2.4.1节，第55页)
//int &r4 = 42;
//bool compare(const matrix &m1, const matrix &m2);
//  void print(const int*);
//  void print(const int[]);
//  int i = 0;
//  int j[] = {0,1};
//  int k[10] = {0,1,2,3,4,5,6,7,8,9};
//  cout<<end(j)<<endl;
//  cout<<begin(j)<<endl;
//  print(k);
int c = 6;
std::cout << largerone(7, &c) << std::endl;

  return 0;

}