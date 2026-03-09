#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Insert player in sorted order (ascending score)
void addPlayer(string name, int score) {
    Node* newNode = new Node{name, score, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->score < score)
        temp = temp->next;

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (temp == NULL) {
        Node* last = head;
        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
        newNode->prev = last;
    }
    else {
        Node* previous = temp->prev;
        previous->next = newNode;
        newNode->prev = previous;

        newNode->next = temp;
        temp->prev = newNode;
    }
}

// Delete player by name
void deletePlayer(string name) {
    Node* temp = head;

    while (temp != NULL && temp->name != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Player not found\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;

    cout << "Player deleted\n";
}

// Display whole list
void display() {
    Node* temp = head;

    cout << "\nPlayers List:\n";
    while (temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

// Display lowest score player
void lowestScore() {
    if (head == NULL)
        return;

    cout << "\nLowest Score Player:\n";
    cout << head->name << " - " << head->score << endl;
}

// Display players with same score
void sameScore(int score) {
    Node* temp = head;

    cout << "\nPlayers with score " << score << ":\n";

    while (temp != NULL) {
        if (temp->score == score)
            cout << temp->name << endl;

        temp = temp->next;
    }
}

// Display backward from player
void backwardFrom(string name) {
    Node* temp = head;

    while (temp != NULL && temp->name != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Player not found\n";
        return;
    }

    cout << "\nPlayers behind " << name << ":\n";

    temp = temp->prev;

    while (temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->prev;
    }
}

int main() {

    addPlayer("Ali", 65);
    addPlayer("Atif", 50);
    addPlayer("Ahmed", 70);
    addPlayer("Sara", 65);
    addPlayer("Usman", 80);

    display();

    lowestScore();

    sameScore(65);

    backwardFrom("Ahmed");

    deletePlayer("Sara");

    display();

    return 0;
}