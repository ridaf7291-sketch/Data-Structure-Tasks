#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    queueArr[++rear] = value;
    cout << value << " enqueued\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << queueArr[front++] << " dequeued\n";
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";
    cout << "\n";
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}