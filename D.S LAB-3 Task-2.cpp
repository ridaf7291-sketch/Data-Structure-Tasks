#include<iostream>
using namespace std;

int main() {
    // Allocate memory for one character
    char* ptr = new char;

    // Store a character
    *ptr = 'R';

    // Print the stored character
    cout << "Stored Character: " << *ptr << endl;

    // Deallocate memory
    delete ptr;

    // Set pointer to nullptr
    ptr = nullptr;

    return 0;
}
