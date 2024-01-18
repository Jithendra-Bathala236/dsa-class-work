#include <iostream>
using namespace std;

int main()
{

    int num1 = 3;
    int *ptr1 = NULL;
    ptr1 = &num1;

    int num2 = 4;
    int *ptr2 = &num2;

    int sum = *ptr1 + *ptr2;
    cout << sum << endl;
    // *ptr1++;
    (*ptr1)++;
    cout << *ptr1 << endl;

    return 0;
}
