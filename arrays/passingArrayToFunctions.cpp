#include <iostream>
using namespace std;

void swapMaxNMin(int *arr, int n) {

  int maxIndex = 0;
  int minIndex = 0;

  for (int i = 0; i < n; i++) {
    if (arr[maxIndex] < arr[i]) {
      maxIndex = i;
    }
    if (arr[minIndex] > arr[i]) {
      minIndex = i;
    }
  }

  int temp = arr[maxIndex];
  arr[maxIndex] = arr[minIndex];
  arr[minIndex] = temp;

  // swap(arr[maxIndex], arr[minIndex]);
}

void displayArr(int *arr, int n) {
  cout << "Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int num = 0;
  cout << "Enter the length of the array: ";
  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }
  swapMaxNMin(arr, num);
  displayArr(arr, num);

  return 0;
}
