#include <iostream>
using namespace std;

int main() {

  int rows = 0, cols = 0;
  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of cols: ";
  cin >> cols;

  int matrix[rows][cols];

  for (int i = 0; i < rows; i++) {
    cout << "Enter elements of " << i + 1 << "th row: ";
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
    cout << endl;
  }

  for (int i = 0; i < rows; i++) {
    cout << "[ ";
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
