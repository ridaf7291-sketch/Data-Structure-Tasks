#include<iostream>
using namespace std;
int main(){
	int arr[5] = {10,20,30,40,50};
	int index = 3;
	int newValue = 100;
	arr[index] = newValue;
	//for loop
	cout<<"After value updated, the array is: ";
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}