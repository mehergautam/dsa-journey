#include <iostream>
using namespace std;

#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1) front = 0;
    arr[++rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    display();

    return 0;
}
