#include <iostream>
using namespace std;

int binarySearch(int *arr, int start, int end, int query) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == query) {
            return mid;
        }
        if (arr[mid] > query) {
            return binarySearch(arr,start, mid-1, query);
        } else {
            return binarySearch(arr, mid+1, end, query);
        }
    }
    return -1;
}

int main() {

    int arr[5] = {1,2,3,4,5};
    cout << binarySearch(arr, 0, 4, 4);

    return 0;
}