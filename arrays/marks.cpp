#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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

void insertAtPos(int *arr, int ele, int pos, int &n) {
    for (int i = n-1; i >= pos; i--) {
        arr[i+1]=arr[i];
    }
    arr[pos] = ele;
    n++;
}

int main() {

    int marks[46];
    fill_n(marks, 46, -1);

    int num = 0;
    cout << "Enter the number of students: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> marks[i];
    }

    bubbleSort(marks, num);

    int newMark = 0, toggle = 1;
    cout << "Enter the new student marks: ";
    cin >> newMark;

    for ( int i = 0; i < num; i++) {
        if (newMark < marks[i]) {
            insertAtPos(marks, newMark, i, num);
            toggle = 0;
            break;
        }
    }

    if (toggle) {
        marks[num] = newMark;
        num++;
    }

    displayArr(marks, num);


    return 0;
}
