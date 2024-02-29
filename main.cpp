#include <iostream>
using namespace std;

int* func(){
    int* a = new int(10);
    return a;
}

int main() {

    int * arr = new int [10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 100;

    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << endl;

    }
    delete[] arr;



    return 0;

}
