#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
// Display list
void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Insert at beginning
void addAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert after value 45
void addAfter45(int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value 45 not found in list.\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}
// Delete at beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}
// Delete node after value 45
void deleteAfter45() {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "No node exists after 45.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = temp;

    delete delNode;
}
int main() {
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        addAtBeginning(value);
    }
    display();

    cout << "\nInsert value at beginning: ";
    cin >> value;
    addAtBeginning(value);
    display();

    cout << "\nInsert value after 45: ";
    cin >> value;
    addAfter45(value);
    display();

    cout << "\nDelete node at beginning\n";
    deleteBeginning();
    display();

    cout << "\nDelete node after 45\n";
    deleteAfter45();
    display();

    return 0;
}