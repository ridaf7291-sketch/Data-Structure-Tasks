#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " inserted at rear\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }
    Node* temp = front;
    cout << front->data << " deleted from front\n";
    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();
    dequeue();
    display();

    return 0;
}