// Singly Linked List - Create and Display
// Time Complexity:
// Insert at end -> O(n)
// Display -> O(n)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display linked list
void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    int n, value;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    display();
    return 0;
}
