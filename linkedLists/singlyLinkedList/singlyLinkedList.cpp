#include "iostream"
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

void displayMenu() {
  cout << "1. Add data at start" << endl;
  cout << "2. Add data at end" << endl;
  cout << "3. Add data after data" << endl;
  cout << "4. Add data before data" << endl;
  cout << "5. Display Linked List" << endl;
  cout << "6. Delete starting Node" << endl;
  cout << "7. Delete Last Node" << endl;
  cout << "8. Delete Node Before value" << endl;
  cout << "9. Delete Node After value" << endl;
  cout << "10. Delete a node in Linked List" << endl;
  cout << "11. Search A Node" << endl;
  cout << "12. Reverse Linked List" << endl;
  cout << "0. Exit" << endl;
  return;
}

void searchNode(Node *start, int data) {
  if (start == NULL) {
    cout << "Linked List is empty" << endl;
    return;
  }
  Node *current = start;
  int count = 0;
  while (current != NULL) {
    if (current->data == data) {
      cout << data << " is Found in Linked List at Node " << count << endl;
      return;
    }
    count++;
    current = current->next;
  }
  cout << data << "is not found in Linked List" << endl;
  return;
}

Node *insertNodeAtStart(int data, Node *start) {
  Node *newNode = new Node(data);
  newNode->next = start;
  return newNode;
}

void insertNodeAtEnd(int data, Node *start) {
  Node *current = start;
  Node *newNode = new Node(data);
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

void insertNodeAtAfterPos(int data, Node *start, int val) {
  Node *current = start;
  Node *newNode = new Node(data);

  while (current != NULL) {
    if (val == current->data) {
      newNode->next = current->next;
      current->next = newNode;
      break;
    }
    current = current->next;
  }
}

void insertNodeAtBeforePos(int data, Node *start, int val) {
  Node *current = start;
  Node *newNode = new Node(data);
  Node *prev = current;

  while (current->data != val) {
    prev = current;
    current = current->next;
  }
  prev->next = newNode;
  newNode->next = current;
}

void displayLinkedList(Node *start) {
  Node *current = start;
  int count = 0;
  if (start == NULL) {
    cout << "Linked List is empty with the length of " << count << endl;
    return;
  }
  cout << "Linked List: ";
  while (current != NULL) {
    cout << current->data << "->";
    current = current->next;
    count++;
  }
  cout << "NULL" << endl;
  cout << "Length of linked list is " << count << endl;
}

void deleteNode(Node *start, int data) {
  Node *current = start;
  Node *prev = current;
  while (current != NULL) {

    if (current->data == data) {
      if (prev == current) {
        start = current->next;
        delete current;
        break;
      } else {
        prev->next = current->next;
        delete current;
        break;
      }
    }
    prev = current;
    current = current->next;
  }
}

// TODO: This is that function
Node *deleteFirstNode(Node *start) {
  if (start == NULL) {
    cout << "Linked List is empty!!!" << endl;
    return start;
  }

  Node *current = start;
  current = start->next;
  delete start;
  return current;
}

void deleteLastNode(Node *start) {
  if (start == NULL) {
    cout << "Linked List is empty!!!" << endl;
    return;
  }

  if (start->next == NULL) {
    delete start;
    start = NULL;
    return;
  }

  Node *current = start;
  Node *prev = current;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  delete current;
  prev->next = NULL;
}

void deleteNodeBefore(Node *start, int num) {

  Node *current = start;
  Node *prev = NULL;

  while (current->next != NULL && current->next->data != num) {
    prev = current;
    current = current->next;
  }

  Node *temp = prev->next;
  prev->next = current->next;

  delete (temp);
}

void deleteNodeAfter(Node *start, int num) {
  Node *current = start;

  while (current != nullptr && current->data != num) {
    current = current->next;
  }

  Node *temp = current->next;
  current->next = temp->next;

  delete (temp);
}

int main() {
  Node *start = NULL;

  int toggle = 1;

  do {
    int choice = 0;
    displayMenu();
    cin >> choice;

    if (choice == 0) {
      toggle = 0;
      cout << "Exiting..." << endl;
    } else if (choice == 1) {
      int data = 0;
      cout << "Enter the data: ";
      cin >> data;
      start = insertNodeAtStart(data, start);
    } else if (choice == 2) {
      int data = 0;
      cout << "Enter the data: ";
      cin >> data;
      insertNodeAtEnd(data, start);
    } else if (choice == 3) {
      int val = 0, data = 0;
      cout << "Enter the data to append: ";
      cin >> data;
      cout << "Enter the data for the ref: ";
      cin >> val;
      insertNodeAtAfterPos(data, start, val);
    } else if (choice == 4) {
      int val = 0, data = 0;
      cout << "Enter the data to append: ";
      cin >> data;
      cout << "Enter the data for the ref: ";
      cin >> val;
      insertNodeAtBeforePos(data, start, val);
    } else if (choice == 5) {
      displayLinkedList(start);
    } else if (choice == 6) {
      start = deleteFirstNode(start);
    } else if (choice == 7) {
      deleteLastNode(start);
    } else if (choice == 8) {
      int val = 0;
      cout << "Enter the ref: ";
      cin >> val;
      deleteNodeBefore(start, val);
    } else if (choice == 9) {
      int val = 0;
      cout << "Enter the ref: ";
      cin >> val;
      deleteNodeAfter(start, val);
    } else if (choice == 10) {
      int data = 0;
      cout << "Enter the data to delete: ";
      cin >> data;
      deleteNode(start, data);
    } else if (choice == 11) {
      int val = 0;
      cout << "Enter the data to Search: ";
      cin >> val;
      searchNode(start, val);
    } else {
      cout << "Invalid Input!!!" << endl;
    }

  } while (toggle);

  return 0;
}
