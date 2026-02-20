#include <iostream>
using namespace std;

#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    arr[rear] = value;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow\n";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }

    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();

    return 0;
}
