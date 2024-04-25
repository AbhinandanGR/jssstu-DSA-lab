#include<iostream>
using namespace std;
#include<cstring>

void insertionSort(char s[]){
	int size = strlen(s);
	for(int i = 1; i < size; i++){
		char temp = s[i];
		int j = i - 1;
		while(j >=0){
			if(s[j] > temp)
				s[j+1] = s[j];
			else
				break;
			j--;
		}
		s[j+1] = temp;
	}
	cout << "The sorted array using insertion sort : " << s << endl;
}

void selectionSort(char s[]){
	int size = strlen(s);
	for(int i = 0; i < size-1; i++){
		int min = i;
		for(int j = i+1; j < size; j++){
			if(s[j] < s[min])
				min = j;
		}
		char temp = s[min];
		s[min] = s[i];
		s[i] = temp;
	}
	cout << "The sorted array using selection sort : " << s << endl;
}

int main(){
	char s[200];
	cout << "Enter the character array : ";
	cin >> s;
	insertionSort(s);
	selectionSort(s);
	
	return 0;
}



