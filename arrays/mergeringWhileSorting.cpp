#include <iostream>
using namespace std;

int main() {
    int numOfGirls = 0;
    cout << "Enter number of girls: ";
    cin >> numOfGirls;
    int girls[numOfGirls];

    for (int i = 0; i < numOfGirls; i++) {
        cin >> girls[i];
    }

    int numOfBoys = 0;
    cout << "Enter number of boys: ";
    cin >> numOfBoys;
    int boys[numOfBoys];

    for (int i = 0; i < numOfBoys; i++) {
        cin >> boys[i];
    }

    int studentData[numOfBoys + numOfGirls], least = 0, highest = 0;

    for (int i = 0; i < numOfBoys + numOfGirls; i++) {
        if (least < numOfGirls && (highest == numOfBoys || girls[least] < boys[highest])) {
            studentData[i] = girls[least];
            least++;
        } else {
            studentData[i] = boys[highest];
            highest++;
        }
    }

    for (int i = 0; i < numOfBoys + numOfGirls; i++) {
        cout << studentData[i] << " ";
    }

    return 0;
}
