#include <iostream>
using namespace std;

void swapNumbers(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a = 50, b = 90;
    cout<< "Before swapping:" <<endl;
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;

 // swap function
    swapNumbers(&a, &b);

    cout<< "\nAfter swapping:" <<endl;
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;

    return 0;
}
