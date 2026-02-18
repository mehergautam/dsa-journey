#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Search
bool search(int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Length
int length() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at Position
void insertAtPosition(int value, int position) {
    if (position == 1) {
        Node* newNode = new Node{value, head};
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) return;

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

// Delete at Position
void deleteAtPosition(int position) {
    if (head == NULL) return;

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp->next != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Reverse
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Display
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Length: " << length() << endl;
    cout << "Search 20: " << (search(20) ? "Found" : "Not Found") << endl;

    insertAtPosition(15, 2);
    deleteAtPosition(3);

    reverseList();

    display();

    return 0;
}
