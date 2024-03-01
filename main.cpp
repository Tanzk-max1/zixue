#include <iostream>
using namespace std;

int* func(){
    int* a = new int(10);
    return a;
}

void increment(int& num) {
    num++;
}

int main() {

    int a = 10;
    int b = 20;
    int &c = a;
    c = b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    return 0;

}
