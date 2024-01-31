#include "iostream"
using namespace std;

float passingPercentageOfSubject(int **data, int nOfStudents, int subject) {
  int passingStundets = 0;

  for (int i = 0; i < nOfStudents; i++) {
    if (data[subject][i] >= 33) {
      passingStundets++;
    }
  }

  float passingPercentage = (float)passingStundets / nOfStudents * 100;
  return passingPercentage;
}

float failingPercentageOfSubject(int **data, int nOfStudents, int subject) {
  int failingStundets = 0;

  for (int i = 0; i < nOfStudents; i++) {
    if (data[subject][i] < 33) {
      failingStundets++;
    }
  }

  float failingPercentage = (float)failingStundets / nOfStudents * 100;
  return failingPercentage;
}

int topperOfSubject(int **data, int nOfStudents, int subject) {
  int topperIndex = 0;
  for (int i = 0; i < nOfStudents; i++) {
    if (data[subject][i] > data[subject][topperIndex]) {
      topperIndex = i;
    }
  }
  return topperIndex;
}

int main() {

  int nOfSubjects = 0, nOfStudents = 0;
  cout << "Enter the number of subjects: ";
  cin >> nOfSubjects;
  cout << "Enter the number of students: ";
  cin >> nOfStudents;

  int **marks = new int *[nOfSubjects];
  for (int i = 0; i < nOfSubjects; i++) {
    marks[i] = new int[nOfStudents];
  }

  for (int i = 0; i < nOfSubjects; i++) {
    cout << "Enter the marks of " << i + 1 << "th subject" << endl;
    for (int j = 0; j < nOfStudents; j++) {
      cout << "Enter the Marks of " << j + 1 << "th student: ";
      cin >> marks[i][j];
    }
    cout << endl;
  }

  cout << "Passing Percentages: " << endl;
  for (int i = 0; i < nOfSubjects; i++) {
    cout << "The passing Percentage of Subject " << i + 1
         << " is: " << passingPercentageOfSubject(marks, nOfStudents, i) << "%"
         << endl;
    ;
  }
  cout << endl;

  cout << "Failing Percentages: " << endl;
  for (int i = 0; i < nOfSubjects; i++) {
    cout << "The Failing Percentage of Subject " << i + 1
         << " is: " << failingPercentageOfSubject(marks, nOfStudents, i) << "%"
         << endl;
    ;
  }
  cout << endl;

  for (int i = 0; i < nOfSubjects; i++) {
    int topperIndex = topperOfSubject(marks, nOfStudents, i);
    cout << "The topper of subject " << i + 1 << " is: " << topperIndex + 1
         << " with " << marks[i][topperIndex] << " marks " << endl;
  }

  return 0;
}
