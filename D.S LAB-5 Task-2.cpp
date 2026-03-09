#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;

// Insert at end
void insert(float value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
// Display statistics
void rainfallStats() {
    Node* temp = head;

    float total = 0;
    float maxRain = head->data;
    float minRain = head->data;
    int day = 1;
    int maxDay = 1;
    int minDay = 1;

    while (temp != NULL) {
        total += temp->data;

        if (temp->data > maxRain) {
            maxRain = temp->data;
            maxDay = day;
        }

        if (temp->data < minRain) {
            minRain = temp->data;
            minDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout << "\nTotal Rainfall = " << total << endl;
    cout << "Average Rainfall = " << total / 7 << endl;

    cout << "Highest Rainfall on Day " << maxDay << " = " << maxRain << endl;
    cout << "Lowest Rainfall on Day " << minDay << " = " << minRain << endl;
}

// Rainfall after 5th node
void rainfallAfter5th() {
    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < 5) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL && temp->next != NULL) {
        cout << "Rainfall after 5th day = " << temp->next->data << endl;
    } else {
        cout << "No rainfall data after 5th day.\n";
    }
}
int main() {
    float rain;

    cout << "Enter rainfall for 7 days:\n";

    for (int i = 1; i <= 7; i++) {
        do {
            cout << "Day " << i << ": ";
            cin >> rain;

            if (rain < 0)
                cout << "Invalid input! Rainfall cannot be negative.\n";

        } while (rain < 0);

        insert(rain);
    }
    rainfallStats();
    rainfallAfter5th();

    return 0;
}