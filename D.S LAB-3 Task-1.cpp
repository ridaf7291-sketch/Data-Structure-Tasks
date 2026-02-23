#include<iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic memory allocation
    Product* p = new Product[n];

    // Taking input
    for(int i = 0; i < n; i++) {
        cout<< "\nEnter details for Product " << i + 1 << endl;

        cout<< "Name: ";
        cin>> p[i].name;

        cout<< "Code: ";
        cin>> p[i].code;

        cout<< "Price: ";
        cin>> p[i].price;
    }

    // Printing products
    cout << "\n--- Product List ---\n";
    for(int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Name: " << p[i].name << endl;
        cout << "Code: " << p[i].code << endl;
        cout << "Price: " << p[i].price << endl;
    }
    // Free memory
    delete[] p;

    return 0;
}
