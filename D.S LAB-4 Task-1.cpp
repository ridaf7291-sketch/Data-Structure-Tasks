#include <iostream>
#include <string>
using namespace std;

//  Mobile Class
class Mobile {
private:
    string brand;
    int unitsOnHand;
    double price;

public:
    // Constructor
    Mobile(string b = "", int u = 0, double p = 0.0) {
        brand = b;
        unitsOnHand = u;
        price = p;
    }
    // Setter functions
    void setBrand(string b) {
        brand = b;
    }
    void setUnits(int u) {
        unitsOnHand = u;
    }
    void setPrice(double p) {
        price = p;
    }
    // Getter functions
    string getBrand() const {
        return brand;
    }
    int getUnits() const {
        return unitsOnHand;
    }
    double getPrice() const {
        return price;
    }
};

// Node for Linked List 
class Node {
public:
    Mobile data;
    Node* next;

    Node(Mobile m) {
        data = m;
        next = NULL;
    }
};

// -----   Store Class (Linked List)
class Store {
private:
    Node* head;

public:
    Store() {
        head = NULL;
    }

    // Insert new mobile at end
    void insertMobile(Mobile m) {
        Node* newNode = new Node(m);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Mobile Inserted Successfully!\n";
    }

    // Delete mobile by brand name
    void deleteMobile(string brandName) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If head node needs deletion
        if (temp != NULL && temp->data.getBrand() == brandName) {
            head = temp->next;
            delete temp;
            cout << "Mobile Deleted Successfully!\n";
            return;
        }

        while (temp != NULL && temp->data.getBrand() != brandName) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Mobile not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Mobile Deleted Successfully!\n";
    }

    // Display all mobiles
    void displayMobiles() {
        if (head == NULL) {
            cout << "No mobiles in store.\n";
            return;
        }

        Node* temp = head;
        cout << "\n--- Mobile Store Inventory ---\n";
        while (temp != NULL) {
            cout << "Brand: " << temp->data.getBrand() << endl;
            cout << "Units: " << temp->data.getUnits() << endl;
            cout << "Price: " << temp->data.getPrice() << endl;
            cout << "---------------------------\n";
            temp = temp->next;
        }
    }
};

// Main Function
int main() {

    Store s;
    // Creating Mobile objects
    Mobile m1("Samsung", 10, 85000);
    Mobile m2("Apple", 5, 250000);
    Mobile m3("Vivo", 20, 65000);

    // Insert mobiles
    s.insertMobile(m1);
    s.insertMobile(m2);
    s.insertMobile(m3);

    // Display all mobiles
    s.displayMobiles();

    // Delete a mobile
    cout << "\nDeleting Apple.\n";
    s.deleteMobile("Apple");

    // Display after deletion
    s.displayMobiles();

    return 0;
}
