#include <iostream>
#include <algorithm>
using namespace std;

class Stack {
    private:
        int stack[100];
        int top;

    public:

        Stack() {
            top = -1;
            for (int i = 0; i < 100; i++)
                stack[i] = -1;
        }

        void dislay() {
            cout << "Stack: [ ";
            for (int i = 0; i <= this->top; i++) {
                cout << stack[i] << ", ";
            }

            cout << "]" << endl;
        }

        void push(int val) {
            if (top == 99) {
                cout << "Stack is full" << endl;
                return ;
            }
            this->top++;
            stack[this->top] = val;
        }

        int pop() {
            if (this->top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            int val = stack[this->top];
            this->top--;
            return val;

        }

        int peek() {
            int top = this->top;
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return stack[top];
        }

        int length() {
            return this->top;
        }

        void reverse() {
            int tempStack[100];
            int tempTop = this->top;
            for (int i = 0; i <= tempTop; i++) {
                tempStack[i] = this->pop();
            }

            for (int i = 0; i <= tempTop; i++) {
                this->push(tempStack[i]);
            }
        }


};

int main() {

    Stack myStack;
    myStack.push(12);
    myStack.push(13);
    myStack.push(14);
    myStack.dislay();
    myStack.reverse();
    myStack.dislay();

    return 0;
}