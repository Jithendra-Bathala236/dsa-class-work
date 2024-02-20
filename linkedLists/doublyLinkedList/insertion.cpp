#include <iostream>
using namespace std;

class Node {
public:
  Node *prev;
  int data;
  Node *next;

  Node(int data) {
    this->prev = NULL;
    this->data = data;
    this->next = NULL;
  }
};

Node *insertAtStart(Node *start, int data) {
  Node *newNode = new Node(data);
  newNode->prev = NULL;
  newNode->next = start;
  if (start != NULL) {
    start->prev = newNode;
  }
  return newNode;
}

void insertAtEnd(Node *start, int data) {
  Node *current = start;
  Node *newNode = new Node(data);
  while (current->next != NULL) {
    current = current->next;
  }
  newNode->prev = current;
  newNode->next = NULL;
  current->next = newNode;
}

void insertAfter(Node *start, int data, int ref) {
  Node *current = start;
  Node *newNode = new Node(data);
  while (current->data != ref) {
    current = current->next;
  }
  newNode->next = current->next;
  newNode->prev = current;
  current->next->prev = newNode;
  current->next = newNode;
}

void insertBefore(Node *start, int data, int ref) {
  Node *current = start;
  Node *newNode = new Node(data);
  while (current->data != ref) {
    current = current->next;
  }
  newNode->next = current;
  newNode->prev = current->prev;
  current->prev->next = newNode;
  current->prev = newNode;
}

void displayLinkedList(Node *start) {
  cout << "Linked List: ";
  Node *current = start;
  while (current != NULL) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node *start = NULL;
  start = insertAtStart(start, 11);
  start = insertAtStart(start, 22);
  start = insertAtStart(start, 33);
  insertAtEnd(start, 44);
  insertAfter(start, 10, 11);
  insertBefore(start, 21, 11);
  displayLinkedList(start);
  return 0;
}
