#include <iostream>
using namespace std;
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

    //局部变量
    int a = 10;
    int b = 10;
    int *d1 = &a;
    uintptr_t addressValue = reinterpret_cast<uintptr_t>(&a);
    uintptr_t addressValue1 = reinterpret_cast<uintptr_t>(&b);
    //打印地址
    cout << "局部变量a地址为： " << addressValue << endl;
    cout << "局部变量a地址为： " << addressValue1 << endl;


    return 0;

}
