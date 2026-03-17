#include <iostream>
using namespace std;

// Inventory Class
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;
public:
    // Setter
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }
    // Getter / Display
    void display() {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Year: " << manufactYear << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};
// Node for Linked List
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory obj) {
        data = obj;
        next = NULL;
    }
};

// Stack Class
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(Inventory obj) {
        Node* newNode = new Node(obj);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory.\n";
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Inventory is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemoved Part Details:\n";
        temp->data.display();

        top = top->next;
        delete temp;
    }
    // Display all
    void displayAll() {
        if (top == NULL) {
            cout << "No parts remaining in inventory.\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Parts in Inventory:\n";
        while (temp != NULL) {
            cout << "----------------------\n";
            temp->data.display();
            temp = temp->next;
        }
    }
};

// Main Program
int main() {
    Stack s;
    int choice;

    do {
        cout << "\n1. Add Part\n2. Remove Part\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int sNum, year, lot;

            cout << "Enter Serial Number: ";
            cin >> sNum;
            cout << "Enter Manufacture Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory obj;
            obj.setData(sNum, year, lot);

            s.push(obj);
        }
        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 3);

    // Display remaining parts
    s.displayAll();

    return 0;
}