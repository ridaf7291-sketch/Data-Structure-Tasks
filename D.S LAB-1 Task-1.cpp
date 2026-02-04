#include<iostream>
using namespace std;
int main(){
	int arr[5] = {1,2,3,4,5};
	int key = 3;
	//for loop
	for(int i=0; i<5; i++){
		if(arr[i]==key){
			cout<<"Element found at index "<<i;
			return 0;
		}
	}
	cout<<"Element not found";
	return 0;
}