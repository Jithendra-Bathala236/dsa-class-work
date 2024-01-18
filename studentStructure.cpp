#include <iostream>
using namespace std;

struct Student {
    int rollno;
    string name;
    int dob;
};

int main() {

    int n = 0;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i<n; i++ ) {
        cout << "Enter " << i+1 <<"th student Name: ";
        cin >> students[i].name;
        cout << "Enter " << i+1 <<"th student Roll Number: ";
        cin >> students[i].rollno;
        cout << "Enter " << i+1 <<"th student dob(DDMMYYYY): ";
        cin >> students[i].dob;
    }

    for (int i = 0; i < n; i++) {
        cout << "Detailes of " << i+1 << " student: " << endl;
        cout << "student Name: " << students[i].name << endl;
        cout << "student Roll Number: " << students[i].rollno << endl;
        cout << "student dob(DDMMYYYY): " << students[i].dob << endl;
    }

    return 0;
}