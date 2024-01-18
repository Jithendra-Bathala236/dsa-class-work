#include <iostream>
// a <- ptr <- ptr2

using namespace std;

int main()
{

    int num = 3;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    cout << "address stored in ptr2: " << *ptr2 << endl;
    cout << "address of ptr1: " << ptr1 << endl;
    cout << **ptr2 << endl;

    return 0;
}
