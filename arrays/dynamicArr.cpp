#include <iostream>

using namespace std;

int main() {
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int *dynamicArray = (int *)(calloc(size, sizeof(int)));

  if (dynamicArray == nullptr) {
    cerr << "Memory allocation" << endl;
    return 1;
  }

  for (int i = 0; i < size; i++) {
    cin >> dynamicArray[i];
  }

  cout << "Dynamic Array Elements: ";
  for (int i = 0; i < size; i++) {
    cout << dynamicArray[i] << ", ";
  }

  free(dynamicArray);

  return 0;
}
