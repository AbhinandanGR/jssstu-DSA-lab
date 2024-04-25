#include<iostream>
using namespace std;
#define max 100

int arr[max], n;

void create(){
	cout << "Enter the size of the array : ";
	cin >> n;
	cout << "Enter the elements into the array : " << endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
}

void display(){
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insert(){
	int ele, pos;
	cout << "Enter the element to insert : ";
	cin >> ele;
	cout << "Enter the position to insert : ";
	cin >> pos;
	
	if(pos < 0 || pos > n+1)
		cout << "Invalid position!!" << endl;
	
	else{
		for(int i = n-1; i >= pos-1; i--)
			arr[i+1] = arr[i];
		arr[pos-1] = ele;
		n = n+1;
	}
	
	cout << "Updated array is : " << endl;
	display();
	cout << endl;
}

void deleteElement(){
	int pos;
	cout << "Enter the position to delete an element from array : ";
	cin >> pos;
	
	if(pos < 0 || pos > n)
		cout << "Invalid position!!" << endl;
	else{
		for(int i = pos-1; i < n; i++)
			arr[i] = arr[i+1];
		n = n-1;
	}
	cout << "Updated array is : " << endl;
	display();
	cout << endl;
}

int main(){
	int ch;
	
	do{
		cout << "\nArray Operation :\n\t1.Create an array\n\t2.Display the array\n\t3.Insert an element into array\n\t4.Delete an element from array\n\t5.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		
		switch(ch){
			case 1 : create(); break;
			case 2 : cout << "Array elements are : " << endl;
				 display(); break;
			case 3 : insert();break;
			case 4 : deleteElement();break;
			case 5 : cout << "Exiting the program!!" << endl;break;
			default : cout << "Invalid choice!!" << endl;
		}
	}while(ch != 5);
	
	return 0;
}


