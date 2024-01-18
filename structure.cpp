#include <iostream>

using namespace std;

struct List {
    int value;
    struct List *next;
};

int main() {

    struct List data;
    data.value = 33;
    cout << data.value << endl;
    cout << data.next;


    return 0;
}
