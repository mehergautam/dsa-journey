#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
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

    int peek() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    cout << "Top: " << s.peek();
    return 0;
}
