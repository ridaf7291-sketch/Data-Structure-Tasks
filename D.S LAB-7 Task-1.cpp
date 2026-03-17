#include <iostream>
using namespace std;
class Node {
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next;

    Node(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
        next = NULL;
    }
};
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }
    void push(string t, float p, int e, int pg) {
        Node* newNode = new Node(t, p, e, pg);
        newNode->next = top;
        top = newNode;
        cout << "Book pushed: " << t << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        cout << "Book popped: " << temp->title << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
        } else {
            cout << "\nTop Book:\n";
            cout << "Title: " << top->title << endl;
            cout << "Price: " << top->price << endl;
            cout << "Edition: " << top->edition << endl;
            cout << "Pages: " << top->pages << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Books in Stack:\n";
        while (temp != NULL) {
            cout << "----------------------\n";
            cout << "Title: " << temp->title << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Edition: " << temp->edition << endl;
            cout << "Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Stack s;
    // Famous books
    s.push("The Great Gatsby", 500, 1, 180);
    s.push("To Kill a Mockingbird", 650, 2, 281);
    s.push("1984", 600, 3, 328);
    s.push("Harry Potter and the Sorcerer's Stone", 800, 1, 309);
    s.push("The Alchemist", 550, 2, 197);

    s.peek();

    s.pop();
    s.pop();

    s.display();

    return 0;
}