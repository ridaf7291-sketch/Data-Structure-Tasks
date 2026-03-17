#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

// Circular Linked List Class
class CircularList {
    Node* last;

public:
    CircularList() {
        last = NULL;
    }

    // Add Employee
    void addEmployee(string name) {
        Node* newNode = new Node(name);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }

        cout << "Employee added successfully.\n";
    }

    // Delete Employee
    void deleteEmployee(string key) {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *curr = last->next, *prev = last;

        do {
            if (curr->name == key) {

                // single node
                if (curr == last && curr->next == last) {
                    last = NULL;
                }
                // first node
                else if (curr == last->next) {
                    last->next = curr->next;
                }
                // last node
                else if (curr == last) {
                    prev->next = curr->next;
                    last = prev;
                }
                // middle node
                else {
                    prev->next = curr->next;
                }

                delete curr;
                cout << "Employee deleted successfully.\n";
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != last->next);

        cout << "Employee not found!\n";
    }

    // Search Employee
    void searchEmployee(string key) {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;

        do {
            if (temp->name == key) {
                cout << "Employee found successfully.\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Employee not found!\n";
    }

    // Update Employee
    void updateEmployee(string oldName, string newName) {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;

        do {
            if (temp->name == oldName) {
                temp->name = newName;
                cout << "Employee updated successfully.\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Employee not found!\n";
    }

    // Display
    void display() {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        cout << "Employees: ";

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != last->next);

        cout << endl;
    }
};

// Main
int main() {
    CircularList cl;
    int choice;
    string name, newName;

    do {
        cout << "\n1. Add Employee\n2. Delete Employee\n3. Search Employee\n4. Update Employee\n5. Display\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cl.addEmployee(name);
            break;

        case 2:
            cout << "Enter name to delete: ";
            cin >> name;
            cl.deleteEmployee(name);
            break;

        case 3:
            cout << "Enter name to search: ";
            cin >> name;
            cl.searchEmployee(name);
            break;

        case 4:
            cout << "Enter old name: ";
            cin >> name;
            cout << "Enter new name: ";
            cin >> newName;
            cl.updateEmployee(name, newName);
            break;

        case 5:
            cl.display();
            break;
        }

    } while (choice != 6);

    return 0;
}