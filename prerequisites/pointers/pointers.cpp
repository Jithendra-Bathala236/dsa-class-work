#include <iostream>
using namespace std;

int main()
{

    int num = 3;
    int *ptr = NULL;
    ptr = &num;

    // size of num and pointer
    // cout << "Value that is ptr is pointing is: " << *ptr << endl;
    // cout << "Size of pointer is " << sizeof(ptr) << endl;
    // cout << "Size of num is " << sizeof(num) << endl;
    // cout << "Size of pointer of num is " << sizeof(*ptr) << endl;

    cout << ptr << endl;
    cout << &num << endl;
    cout << &ptr << endl;

    return 0;
}
