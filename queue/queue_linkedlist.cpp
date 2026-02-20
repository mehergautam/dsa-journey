#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontNode = NULL;
Node* rearNode = NULL;

void enqueue(int value) {
    Node* newNode = new Node{value, NULL};

    if (rearNode == NULL) {
        frontNode = rearNode = newNode;
        return;
    }

    rearNode->next = newNode;
    rearNode = newNode;
}

void dequeue() {
    if (frontNode == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == NULL)
        rearNode = NULL;

    delete temp;
}

void display() {
    Node* temp = frontNode;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    enqueue(5);
    enqueue(15);
    enqueue(25);
    dequeue();
    display();

    return 0;
}
