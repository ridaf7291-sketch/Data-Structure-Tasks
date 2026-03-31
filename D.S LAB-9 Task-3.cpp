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

    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int countElements() {
    int count = 0;
    Node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void display() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    cout << "Queue elements: ";
    display();

    cout << "Number of elements in queue: " << countElements();

    return 0;
}