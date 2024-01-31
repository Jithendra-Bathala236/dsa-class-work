#include <iostream>
using namespace std;

float passingPercentageOfSubject(int data[][50], int nOfStudents, int subject) {
  float passingStudents = 0;
  for (int i = 0; i < nOfStudents; i++) {
    if (data[i][subject] >= 33) {
      passingStudents++;
    }
  }
  float passingPercentage = (passingStudents / nOfStudents) * 100;
  return passingPercentage;
}

float failingPercentageOfSubject(int data[][50], int nOfStudents, int subject) {
  float failingStudents = 0;
  for (int i = 0; i < nOfStudents; i++) {
    if (data[i][subject] < 33) {
      failingStudents++;
    }
  }
  float failingPercentage = (failingStudents / nOfStudents) * 100;
  return failingPercentage;
}

int topperOfSubject(int data[][50], int nOfStudents, int subject) {
  int topperIndex = 0;
  for (int i = 1; i < nOfStudents; i++) {
    if (data[i][subject] > data[topperIndex][subject]) {
      topperIndex = i;
    }
  }
  return topperIndex;
}

int main() {
  int nOfStudents = 0, nOfSubjects = 0;
  cout << "Enter the number of subjects: ";
  cin >> nOfSubjects;
  cout << "Enter the number of students: ";
  cin >> nOfStudents;

  int studentsData[50][50];

  for (int i = 0; i < nOfStudents; i++) {
    cout << "Enter the data of student " << i + 1 << ": " << endl;
    for (int j = 0; j < nOfSubjects; j++) {
      cout << "Enter the marks of subject " << j + 1 << ": ";
      cin >> studentsData[i][j];
    }
    cout << endl;
  }

  cout << "Passing percentage of following subjects: " << endl;
  for (int i = 0; i < nOfSubjects; i++) {
    cout << "Subject " << i + 1 << ": "
         << passingPercentageOfSubject(studentsData, nOfStudents, i)
         << "% passed." << endl;
  }

  cout << "Failing percentage of following subjects: " << endl;
  for (int i = 0; i < nOfSubjects; i++) {
    cout << "Subject " << i + 1 << ": "
         << failingPercentageOfSubject(studentsData, nOfStudents, i)
         << "% failed." << endl;
  }

  cout << "Topper of each subject: " << endl;
  for (int i = 0; i < nOfSubjects; i++) {
    int topperIndex = topperOfSubject(studentsData, nOfStudents, i);
    cout << "Subject " << i + 1 << ": Student " << topperIndex + 1
         << " with marks " << studentsData[topperIndex][i] << endl;
  }

  cout << "Total marks and percentage of each student: " << endl;
  for (int i = 0; i < nOfStudents; i++) {
    cout << "Student " << i + 1
         << ": Total Marks: " << studentsData[i][nOfSubjects]
         << ", Percentage: " << studentsData[i][nOfSubjects + 1] << "%" << endl;
  }

  return 0;
}
