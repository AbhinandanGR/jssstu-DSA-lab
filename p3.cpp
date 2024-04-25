#include<iostream>
using namespace std;
#define max 10

int top = -1, s[max];

int isfull(){
	if(top == (max-1)){
		cout << "Overflow!!" << endl;
		return 1;
	}
	return 0;
}

int isempty(){
	if(top == -1){
		cout << "Underflow!!" << endl;
		return 1;
	}
	return 0;
}

void push(){
	if(isfull() == 1);
	else{
		cout << "Enter the element to insert : ";
		cin >> s[++top];
	}
}

void pop(){
	if(isempty() == 1);
	else{
		cout << s[top--] << " is deleted" << endl;
	}
}

void display(){
	if(isempty() == 1);
	else{
		cout << "Stack elements are : " << endl;
		for(int i = top; i >= 0; i--)
			cout << s[i] << " ";
		cout << endl;
	}
}

void palindrome(){
	int num[max], rev[max];
	if(isempty() == 1);
	else{
		for(int i = top, t = 0; i >= 0; i--, t++)
			rev[t] = num[i] = s[i];
		for(int i = 0; i <= top; i++){
			if(num[i] != rev[i]){
				cout << "It is not a palindrome" << endl;
				return;
			}
		}
		cout << "It is a palindrome " << endl;
	}
}

int main(){
	int choice;
	
	do{
		cout << "Stack operation:\n\t1.Push\n\t2.Pop\n\t3.Palindrome\n\t4.Display\n\t5.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : push();break;
			case 2 : pop();break;
			case 3 : palindrome();break;
			case 4 : display();break;
			case 5 : cout << "Exiting the program" << endl;
				 break;
			default : cout << "Invalid choice!!" << endl;
		} 
	}while(choice != 5);
	
	return 0;
}




