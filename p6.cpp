#include<iostream>
using namespace std;
#define max 5

char q[max], ele;
int front = -1, rear = -1;

int isfull(){
	if(((rear+1) % max) == front)
		return 1;
	return 0;
}

int isempty(){
	if(front == -1 && rear == -1)
		return 1;
	return 0;
}

void enqueue(){
	if(isfull() == 1){
		cout << "Queue overflow " << endl;
		return;
	}
		
	else{
		cout << "Enter the element to insert : ";
		cin >> ele;
		
		if(front == -1 && rear == -1){
			front = rear = 0;
			q[rear] = ele;
		}
		else{
			rear = (rear + 1) % max;
			q[rear] = ele;
		}
	}
}

void dequeue(){
	if(isempty() == 1){
		cout << "Queue underflow " << endl;
		return;
	}
	else{
		cout << "Deleted element is : " << q[front] << endl;
		if(front == rear)
			front = rear = -1;
		else
			front = (front + 1) % max; 
	}
}

void display(){
	if(isempty() == 1){
		cout << "Queue underflow " << endl;
		return;
	}
	else{
		cout << "Queue elements are : " << endl;
		if(front <= rear){
			for(int i = front; i <= rear; i++)
				cout << q[i] << " ";
		}
		else{
			for(int i = front; i < max; i++)
				cout << q[i] << " ";
			for(int i = 0; i <= rear; i++)
				cout << q[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	int ch;
	
	do{
		cout << "Circular Queue operation : \n\t1.Enqueue\n\t2.Dequeue\n\t3.display\n\t4.Exit" << endl;
		cout << "Enter the choice : ";
		cin >> ch;
		
		switch(ch){
			case 1 : enqueue();break;
			case 2 : dequeue();break;
			case 3 : display();break;
			case 4 : cout << "Exiting the program " << endl;break;
			default : cout << "Invalid choice!!" << endl;
		}
	}while(ch != 4);

	return 0;
}



