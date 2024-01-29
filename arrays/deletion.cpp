#include <iostream>
#include <algorithm>
using namespace std;

void deletion(int *arr, int pos,int &n) {
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void displayArr(int *arr, int n) {
    cout << "Array : [ ";
    for ( int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << arr[i] << " ]" << endl;
        } else {
            cout << arr[i] << ", " ;
        }
    }
}


int main() {

    int arr[100];
    fill_n(arr, 100, -1);

    int num = 0;
    cout << "Enter the length of the array: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int pos = 0;
    cout << "Enter index postion: ";
    cin >> pos;

    deletion(arr, pos, num);
    displayArr(arr, num);

    return 0;
}
