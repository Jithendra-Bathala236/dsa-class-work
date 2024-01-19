#include <iostream>
using namespace std;

void getPassedAndFailedStudents(int *sub1, int *sub2, int *sub3, int size){
    int passedStudents=0;
    for (int i = 0; i < size; i++) {
        if (sub1[i] >= 40 && sub2[i] >= 40 && sub3[i] >= 40) {
            passedStudents++;
        }
    }

    int passedStudentsPrecentage = float(passedStudents)/size * 100;
    int failedStudentsPrecentage = 100 - passedStudentsPrecentage;
    cout << "Passed students precentage: " << passedStudentsPrecentage << endl;
    cout << "Failed students precentage: " << failedStudentsPrecentage << endl;

    return ;
}

int main() {

    int n = 0;
    cout << "Enter the number of students: ";
    cin >> n;

    int dsa[n];
    int html[n];
    int css[n];
    for  (int i = 0; i < n; i++) {
        cout << endl << "Enter marks of " << i+1 << "th student" << endl;
        cout << "Enter dsa marks: ";
        cin >> dsa[i];
        while (dsa[i] > 100 || dsa[i] < 0){
            cout << "invalid input" << endl;
            cout << "Enter dsa marks: ";
            cin >> dsa[i];
        }
        cout << "Enter html marks: ";
        cin >> html[i];
        while (html[i] > 100 || html[i] < 0){
            cout << "invalid input" << endl;
            cout << "Enter dsa marks: ";
            cin >> html[i];
        }
        cout << "Enter css marks: ";
        cin >> css[i];
        while (css[i] > 100 || css[i] < 0){
            cout << "invalid input" << endl;
            cout << "Enter dsa marks: ";
            cin >> css[i];
        }
    }

    getPassedAndFailedStudents(dsa, html, css, n);

    return 0;
}
