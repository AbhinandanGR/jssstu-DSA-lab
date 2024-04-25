#include<iostream>
using namespace std;
#define max 100

int create(int num){
	return num % 100;
}

void display(int a[max]){
	int ch;
	cout << "\n1. Display all\n2. Filtered display\n";
	cout << "Enter the choice : ";
	cin >> ch;
	
	if(ch == 1){
		cout << "The hash table is : " << endl;
		for(int i = 0; i < max; i++)
			cout << "\n" << i << "\t" << a[i];
	}
	else{
		cout << "The hash table is : " << endl;
		for(int i = 0; i < max; i++){
			if(a[i] != -1)
				cout << "\n" << i << "\t" << a[i];
		}
	}
}

void linearProbe(int a[max], int key, int num){
	int i, flag = 0, count = 0;
	if(a[key] == -1)
		a[key] = num;
	else{
		cout << "Collision Detected!!" << endl;
		for(i = 0; i < max; i++){
			if(a[i] != -1)
				count++;
		}
		cout << "Collision handled successfully by linear probing!!" << endl;
		
		if(count == max){
			cout << "The hash table is full" << endl;
			display(a);
			exit(1);
		}
		for(i = key +1; i < max; i++){
			if(a[i] == -1){
				a[i] = num;
				flag = 1;
				break;
			}
		}
		i = 0;
		while((i < key) && (flag == 0)){
			if(a[i] == -1){
				a[i] = num;
				flag = 1;
				break;
			}
			i++;
		}
	}
}

int main(){
	int a[max], num, key;
	int ans = 1;
	
	cout << "Collision handling by linear probing!!" << endl;
	for(int i = 0; i < max; i++)
		a[i] = -1;
		
	do{
		cout << "Enter the data : ";
		cin >> num;
		key = create(num);
		linearProbe(a, key, num);
		cout << "Do want to continue(1/0) : " ;
		cin >> ans;
	}while(ans);
	
	display(a);
	return 0;
}





