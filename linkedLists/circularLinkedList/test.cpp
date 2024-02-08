#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() {
    this->data = 0;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtStart(Node **start, int data) {
  Node *newNode = new Node(data);
  newNode->next = *start;
  *start = newNode;
}

int main() {
  Node *start = NULL;
  insertAtStart(&start, 10);
  cout << start->data;
  return 0;
}
