#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node{value, top};
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top Element: " << top->data << endl;
}

void display() {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {

    push(5);
    push(15);
    push(25);
    pop();
    peek();
    display();

    return 0;
}
