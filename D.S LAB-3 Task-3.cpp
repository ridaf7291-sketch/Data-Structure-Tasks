#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Allocate memory for rows (array of pointers)
    int** matrix = new int*[rows];

    // Allocate memory for each row
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Input elements
    cout << "\nEnter matrix elements:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display matrix
    cout << "\nMatrix is:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    return 0;
}