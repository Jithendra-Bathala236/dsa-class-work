// void/genetic pointer

#include <iostream>
using namespace std;

int main()
{

    // int num1 = 3;
    // void *ptr = &num1;

    // // cout << *ptr << endl;

    // cout << *((int *)ptr) << endl;

    // char c = 'A';
    // char *ptr = &c;
    // cout << ptr << endl; -> 'A'
    // cout << *ptr << endl;

    char c = 'A';
    void *ptr = &c;
    cout << ptr << endl;          // -> address of c
    cout << *(char *)ptr << endl; // -> 'A'

    return 0;
}
