#include <iostream>
#include <algorithm>
using namespace std;

int linearSearch(int *arr, int q,int n) {
    for ( int i = 0; i < n; i++) {
        if (arr[i] == q) {
            return i;
        }
    }
    return -1;
}

void insertAtBeginning(int* arr, int ele, int n) {
    for (int i = n-1; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = ele;
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

int getNumberOfElements(int *arr) {
    int i = 0;
    while (arr[i] != -1){
        i++;
    }
    return i;
}

void implimentInsertAtBeginning() {
    int numOfEleInArr; 
    cout << "Enter the length of the array: ";
    cin >> numOfEleInArr;

    int arr[100];
    fill_n(arr, 100, -1);
    for (int i = 0; i < numOfEleInArr; i++) {
        cin >> arr[i];
    }

    cout << "current ";
    displayArr(arr, getNumberOfElements(arr));

    int newEle = 0;
    cout << "Enter the element to append: ";
    cin >> newEle;

    insertAtBeginning(arr,newEle, getNumberOfElements(arr));

    cout << "New ";
    displayArr(arr, getNumberOfElements(arr));
}

void insertAtEnd(int *arr, int ele, int n) {
    arr[n] = ele;
}

void implimentInsertAtEnd() {
    int numOfEleInArr = 0; 
    cout << "Enter the length of the array: ";
    cin >> numOfEleInArr;

    int arr[100];
    fill_n(arr, 100, -1);

    for (int i = 0; i < numOfEleInArr; i++) {
        cin >> arr[i];
    }

    cout << "current ";
    displayArr(arr, getNumberOfElements(arr));

    int newEle = 0;
    cout << "Enter the element to append: ";
    cin >> newEle;

    insertAtEnd(arr,newEle, getNumberOfElements(arr));

    displayArr(arr, getNumberOfElements(arr));
}

void insertAtPos(int *arr, int ele, int pos, int n) {
    for (int i = n-1; i >= pos; i--) {
        arr[i+1]=arr[i];
    }
    arr[pos] = ele;
}

void implimentInsertAtPos() {
    int numOfEleInArr = 0; 
    cout << "Enter the length of the array: ";
    cin >> numOfEleInArr;

    int arr[100];
    fill_n(arr, 100, -1);

    for (int i = 0; i < numOfEleInArr; i++) {
        cin >> arr[i];
    }

    cout << "current ";
    displayArr(arr, getNumberOfElements(arr));

    int newEle = 0, pos = 0;
    cout << "Enter the element to append: ";
    cin >> newEle;
    
    cout << "Enter index position: ";
    cin >> pos;
    while(pos < 0 || pos >= getNumberOfElements(arr)) {
        cout << "Invalid input!!!" << endl;
        cout << "Enter index position: ";
        cin >> pos;
    }

    insertAtPos(arr,newEle, pos - 1, getNumberOfElements(arr));

    displayArr(arr, getNumberOfElements(arr));
}

void insertAfter(int *arr, int ele, int posValue, int n) {
    int pos = linearSearch(arr, posValue, n);
    if (pos != -1) {
        insertAtPos(arr, ele, pos + 1, n);
    }

}

void implimentInsertAfter() {
    int numOfEleInArr = 0; 
    cout << "Enter the length of the array: ";
    cin >> numOfEleInArr;

    int arr[100];
    fill_n(arr, 100, -1);

    for (int i = 0; i < numOfEleInArr; i++) {
        cin >> arr[i];
    }

    cout << "current ";
    displayArr(arr, getNumberOfElements(arr));

    int newEle = 0, pos = 0;
    cout << "Enter the element to append: ";
    cin >> newEle;
    
    cout << "Enter position: ";
    cin >> pos;

    insertAfter(arr,newEle, pos - 1, getNumberOfElements(arr));

    displayArr(arr, getNumberOfElements(arr));
}



int main() {

    // implimentInsertAtBeginning();
    // implimentInsertAtEnd();
    implimentInsertAtPos();

    return 0;
}
