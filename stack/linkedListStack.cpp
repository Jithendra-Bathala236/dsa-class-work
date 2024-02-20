#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
    private:
        
        Node* top;
    public:
        LinkedListStack() {
            top = NULL;
        }

        void display() {
            Node* current = top;
            cout << "Stack: [ ";
            while (current) {
                cout << current->data << ", ";
                current = current->next;
            }
            cout << "]" << endl;
        }

        void push(int val) {
            Node* newNode = new Node;
            if (newNode == NULL) {
                cout << "Stack is full" << endl;
                return ;
            }
            newNode->data = val;
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            Node* popedNode = top;
            int val = popedNode->data;
            top = top->next;
            delete popedNode;
            return val;
        }

        int peek() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }

        int length() {
            Node* current = top;
            int count = 0;
            while (current) {
                count++;
                current = current->next;
            }
            return count;
        }

        void reverse() {
            Node* current = top;
            Node* prev = NULL;
            Node* temp = NULL;
            while (current) {
                temp = prev;
                prev = current;
                current = current->next;
                prev->next = temp;
            }
            top = prev;
        }

};

int main() {

    LinkedListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << "Beofre reversing: ";
    stack.display();
    cout << "After reversing: ";
    stack.reverse();
    stack.display();

    return 0;
}