#include <iostream>
using namespace std;

void largestNumber(int *arr, int size) {
    int max1=arr[0], max2=arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && max1 != arr[i]) {
            max2 = arr[i];
        }
    }
    cout << max1 << " " << max2 << endl;
    return;
}

int main() {

    int n = 0;
    cout << "Enter the length of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    largestNumber(arr,n);

    return 0;
}
