#include <iostream>
using namespace std;
// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class CircularLinkedList {
    Node* last;   // pointer to last node

public:
    CircularLinkedList() {
        last = NULL;
    }
    // Insert Before (at beginning)
    void insertBefore(int val) {
        Node* newNode = new Node(val);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }

        cout << val << " inserted at beginning.\n";
    }
    // Insert After (at end)
    void insertAfter(int val) {
        Node* newNode = new Node(val);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }

        cout << val << " inserted at end.\n";
    }
    // Delete node (all cases)
    void deleteNode(int key) {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *curr = last->next, *prev = last;
        // Single node case
        if (curr == last && curr->data == key) {
            delete curr;
            last = NULL;
            cout << "Node deleted.\n";
            return;
        }

        // Search node
        do {
            if (curr->data == key) {

                // Deleting first node
                if (curr == last->next) {
                    last->next = curr->next;
                }
                // Deleting last node
                else if (curr == last) {
                    prev->next = curr->next;
                    last = prev;
                }
                // Middle node
                else {
                    prev->next = curr->next;
                }

                delete curr;
                cout << "Node deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;

        } while (curr != last->next);

        cout << "Value not found!\n";
    }
    // Display
    void display() {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = last->next;
        cout << "Circular List: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);

        cout << endl;
    }
};
// Main
int main() {
    CircularLinkedList cll;

    cll.insertBefore(10);
    cll.insertBefore(5);
    cll.insertAfter(20);
    cll.insertAfter(30);

    cll.display();

    cll.deleteNode(5);   // delete beginning
    cll.display();

    cll.deleteNode(30);  // delete last
    cll.display();

    cll.deleteNode(20);  // delete middle
    cll.display();

    return 0;
}