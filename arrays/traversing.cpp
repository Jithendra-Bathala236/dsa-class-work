#include <iostream>
using namespace std;

// write a cpp program to read, display n numbers (take n from user) and find mean of n numbers using an array

void displayArr(int *arr, int n) {
    cout << "Array: [ ";
    for (int i = 0; i<n; i++) {
        if (i == n-1){
            cout << arr[i] << "] " << endl;
        } else {
            cout << arr[i] << ", ";
        }
    }
}

int main() {

    int n = 0, mean = 0;
    cout << "Enter the numbers the elements: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mean += arr[i];
    }

    mean /= n;
    displayArr(arr, n);
    cout <<"mean: " << mean << endl;

    return 0;
}
