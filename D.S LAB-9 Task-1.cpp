#include <iostream>
using namespace std;
class Applicant {
public:
    int applicant_id;
    float height, weight, eyesight;
    string status;

    Applicant(int id, float h, float w, float e) {
        applicant_id = id;
        height = h;
        weight = w;
        eyesight = e;
        status = "Waiting";
    }
};
class Node {
public:
    Applicant data;
    Node* next;
    Node* prev;

    Node(Applicant a) : data(a), next(NULL), prev(NULL) {}
};
class QueueDLL {
    Node* front;
    Node* rear;
public:
    QueueDLL() {
        front = rear = NULL;
    }
    // Enqueue
    void enqueue(Applicant a) {
        Node* temp = new Node(a);

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // Dequeue from front
    void dequeue() {
        if (front == NULL) {
            cout << "Line is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Applicant " << temp->data.applicant_id << " completed test and left.\n";

        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }
    // Remove 2nd position
    void removeSecond() {
        if (front == NULL || front->next == NULL) {
            cout << "Not enough applicants to remove 2nd.\n";
            return;
        }

        Node* second = front->next;
        cout << "Applicant " << second->data.applicant_id << " left due to urgency.\n";

        front->next = second->next;
        if (second->next != NULL)
            second->next->prev = front;
        else
            rear = front;

        delete second;
    }
    // Display queue
    void display() {
        Node* temp = front;
        cout << "\nCurrent Applicants in Line:\n";
        while (temp != NULL) {
            cout << "ID: " << temp->data.applicant_id
                 << " | Height: " << temp->data.height
                 << " | Weight: " << temp->data.weight
                 << " | Eyesight: " << temp->data.eyesight
                 << " | Status: " << temp->data.status <<endl;
            temp = temp->next;
        }
        cout << "----------------------------------------------------------------------\n";
    }
};
int main() {
    QueueDLL q;
    // 7 applicants
    q.enqueue(Applicant(1, 5.7, 65, 1.0));
    q.enqueue(Applicant(2, 5.8, 70, 1.1));
    q.enqueue(Applicant(3, 5.6, 68, 0.9));
    q.enqueue(Applicant(4, 5.9, 72, 1.2));
    q.enqueue(Applicant(5, 5.5, 66, 1.0));
    q.enqueue(Applicant(6, 5.7, 69, 1.3));
    q.enqueue(Applicant(7, 5.8, 71, 1.1));
    q.display();
    // Front leaves after test
    q.dequeue();
    q.display();

    // 2nd person leaves urgently
    q.removeSecond();
    q.display();

    // New entry at end
    q.enqueue(Applicant(8, 6.0, 75, 1.0));
    q.display();
    return 0;
}