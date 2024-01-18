#include <iostream>
#include <vector>
using namespace std;

struct SubMarks {
    string sub;
    int marks;

    void getSubMarks(int marks, string sub) {
        this->sub = sub;
        this->marks = marks;
    }

    void displaySubMarks() {
        cout << "Subject: " << sub << endl;
        cout << "Marks: " << marks << endl;
    }

    void updateMarks(int *marks) {
        cout << "Enter the updated "<< this->sub <<" marks: ";
        cin >> *marks;
    }
};

struct StudentMarks {
    struct SubMarks regularMarks[5];

    void getStudentSubjects() {
        for (int i = 0; i<5; i++) {
            cout << "Enter the " << i+1 << "th subject detailes" << endl;
            string sub;
            int marks;
            cout << "Enter the subject: ";
            cin >> sub;
            regularMarks[i].getSubMarks(0, sub);
        }
    }

    void getFailedSubjects() {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (regularMarks[i].marks < 35) {
                regularMarks[i].displaySubMarks();
                count++;
            }
        }
        if (count == 0) {
            cout << "No failed subjects found" << endl;
        }
    }

    void displayMarks() {
        for (int i = 0; i < 5; i++) {
            regularMarks[i].displaySubMarks();
        }
    }

    void updateFailedSubjects() {
        for (int i = 0; i < 5; i++){
            if (regularMarks[i].marks < 35) {
                regularMarks[i].updateMarks(&regularMarks[i].marks);
            }
        }
    }
};

int main() {

    vector<struct StudentMarks> students;
    int toggle = 1;
    while (toggle)
    {
        int choice = 0, internalChoice = 0;
        cout << "1. Enroll for exam" << endl;
        cout << "2. Marks Entry" << endl;
        cout << "0. exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                internalChoice = 0;
                cout << "1. Regular: " << endl;
                cout << "2. Re exam: " << endl;
                cin >> internalChoice;
                if (internalChoice == 1) {
                    struct StudentMarks tempData;
                    tempData.getStudentSubjects();
                    students.push_back(tempData);
                }
                else if (internalChoice == 2) {
                    if (students.size() == 0) {
                        cout << "No data found!!!" << endl;
                        break;
                    }
                    for (int i = 0; i < students.size(); i++) {
                        students[i].getFailedSubjects();
                    }
                }
                break;
            
            case 2:
                internalChoice = 0;
                cout << "1. Regular: " << endl;
                cout << "2. Re exam: " << endl;
                cin >> internalChoice;
                if (internalChoice == 1) {
                    if (students.size() == 0) {
                        cout <<"No data found!!!" << endl;
                        break;
                    }
                    for (int i = 0; i < students.size(); i++) {
                        students[i].displayMarks();
                    }

                }
                else if (internalChoice == 2) {
                    if (students.size() == 0) {
                        cout << "No data found!!!" << endl;
                        break;
                    }
                    for (int i = 0; i < students.size(); i++) {
                        students[i].updateFailedSubjects();
                    }
                }
                break;
            case 0:
                toggle = 0;
                cout << "exiting..." << endl;
                break;
            default:
                cout << "Invalid input!!!" << endl;
                break;
        }
    }


    return 0;
}
