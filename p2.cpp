#include<iostream>
using namespace std;
#define max 100

void display(int arr[], int size){
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int temp = arr[i];
		int j = i - 1;
		while(j >= 0){
			if(arr[j] > temp)
				arr[j+1] = arr[j];
			else 
				break;
			j--;
		}
		arr[j+1] = temp;
	}
}

void selectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i+1; j < size; j++){
			if(arr[j] < arr[min])
				min = j;
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;	
	}
}

int main(){
	int arr[max], n, choice;
	cout << "Enter the size of the array : ";
	cin >> n;
	
	cout << "Enter the elements into the array " << endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << "Sorting Technique : " << endl;
	cout << "\t1. Insertion Sort " << endl;
	cout << "\t2. Selection Sort " << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	
	switch(choice){
		case 1: cout << "Elements before sorting :" << endl;
			display(arr, n);
			insertionSort(arr, n);
			cout << "Elements after sorting : " << endl;
			display(arr, n);
			break;
		
		case 2 : cout << "Elements before sorting :" << endl;
			display(arr, n);
			selectionSort(arr, n);
			cout << "Elements after sorting : " << endl;
			display(arr, n);
			break;
			
		default : cout << "Invalid choice!!" << endl;
	} 
	
	
	return 0;
}



