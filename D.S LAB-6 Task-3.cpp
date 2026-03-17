#include <iostream>
using namespace std;

// ================= Book Class =================
class Book {
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    // Default Constructor
    Book() {
        bookId = "";
        bookName = "";
        bookPrice = 0;
        bookAuthor = "";
        bookISBN = "";
    }

    // Parameterized Constructor
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    // Getters
    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }

    // Setters
    void setData(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    // Display
    void display() {
        cout << "ID: " << bookId << endl;
        cout << "Name: " << bookName << endl;
        cout << "Price: " << bookPrice << endl;
        cout << "Author: " << bookAuthor << endl;
        cout << "ISBN: " << bookISBN << endl;
    }
};

// ================= Node Class =================
class Node {
private:
    Book data;
    Node* next;
    Node* prev;

public:
    Node() {
        next = prev = NULL;
    }

    Node(Book b) {
        data = b;
        next = prev = NULL;
    }

    // Getters
    Book getData() { return data; }
    Node* getNext() { return next; }
    Node* getPrev() { return prev; }

    // Setters
    void setData(Book b) { data = b; }
    void setNext(Node* n) { next = n; }
    void setPrev(Node* p) { prev = p; }
};

// ================= Doubly Circular List =================
class BookList {
    Node* head;

public:
    BookList() {
        head = NULL;
    }

    // Add Book
    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);

        if (head == NULL) {
            head = newNode;
            head->setNext(head);
            head->setPrev(head);
        } else {
            Node* last = head->getPrev();

            newNode->setNext(head);
            newNode->setPrev(last);
            last->setNext(newNode);
            head->setPrev(newNode);
        }

        cout << "Book added successfully.\n";
    }

    // Remove Book
    void removeBook(string id) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->getData().getId() == id) {

                // Single node
                if (temp->getNext() == head && temp == head) {
                    head = NULL;
                }
                // Deleting head
                else if (temp == head) {
                    Node* last = head->getPrev();
                    head = head->getNext();
                    last->setNext(head);
                    head->setPrev(last);
                }
                // Other nodes
                else {
                    temp->getPrev()->setNext(temp->getNext());
                    temp->getNext()->setPrev(temp->getPrev());
                }

                delete temp;
                cout << "Book deleted successfully.\n";
                return;
            }

            temp = temp->getNext();

        } while (temp != head);

        cout << "Book ID not found!\n";
    }

    // Update Book
    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->getData().getId() == id) {
                Book b;
                b.setData(id, name, price, author, isbn);
                temp->setData(b);
                cout << "Book updated successfully.\n";
                return;
            }

            temp = temp->getNext();

        } while (temp != head);

        cout << "Book ID not found!\n";
    }

    // Print All Books
    void printBooks() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "\nAll Books:\n";

        do {
            cout << "------------------\n";
            temp->getData().display();
            temp = temp->getNext();
        } while (temp != head);
    }

    // Print Single Book
    void printBook(string id) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->getData().getId() == id) {
                cout << "\nBook Found:\n";
                temp->getData().display();
                return;
            }
            temp = temp->getNext();
        } while (temp != head);

        cout << "Book ID not found!\n";
    }
};

// ================= Main =================
int main() {
    BookList bl;

    // Add 10 books
    bl.addBook("B1","C++",500,"Ali","111");
    bl.addBook("B2","DSA",600,"Sara","112");
    bl.addBook("B3","OOP",550,"Ahmed","113");
    bl.addBook("B4","DBMS",700,"Fatima","114");
    bl.addBook("B5","OS",650,"Usman","115");
    bl.addBook("B6","AI",800,"Ayesha","116");
    bl.addBook("B7","ML",900,"Zain","117");
    bl.addBook("B8","CN",750,"Hina","118");
    bl.addBook("B9","SE",620,"Bilal","119");
    bl.addBook("B10","Cyber",880,"Noor","120");

    // Print one book
    bl.printBook("B3");

    // Remove books (one valid, one invalid)
    bl.removeBook("B5");
    bl.removeBook("B20");

    // Print again
    bl.printBook("B5");

    // Update book
    bl.updateBook("B3","Advanced OOP",750,"Ahmed","999");

    // Print updated book
    bl.printBook("B3");

    // Print all
    bl.printBooks();

    return 0;
}