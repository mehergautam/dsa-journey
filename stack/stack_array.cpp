#include <iostream>
using namespace std;

#define SIZE 5

int stackArr[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = value;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top Element: " << stackArr[top] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << endl;
}

int main() {

    push(10);
    push(20);
    push(30);
    pop();
    peek();
    display();

    return 0;
}
