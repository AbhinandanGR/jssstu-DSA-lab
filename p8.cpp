#include<iostream>
using namespace std;

struct node{
	int ssn, phone;
	float sal;
	char name[20], dept[20], desig[20];
	node* prev;
	node* next;
}*head = NULL, *tail = NULL;

node* createNode(){
	node* t = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the SSN : ";
	cin >> t->ssn;
	cout << "Enter the name : ";
	cin >> t->name;
	cout << "Enter the department : ";
	cin >> t->dept;
	cout << "Enter the designation : ";
	cin >> t->desig;
	cout << "Enter the salary : ";
	cin >> t->sal;
	cout << "Enter the phone number : ";
	cin >> t-> phone;
	t->prev = NULL;
	t->next = NULL;
	return t;
}

void insertBeg(){
	node* t = createNode();
	if(head == NULL)
		head = tail = t;
	else{
		t->next = head;
		head->prev = t;
		head = t;
	}
}

void insertEnd(){
	node* t = createNode();
	if(head == NULL)
		head = tail = t;
	else{
		tail -> next = t;
		t->prev = tail;
		tail = t;
	}
}

void deleteBeg(){
	if(head == NULL)
		cout << "List is Empty" << endl;
	else{
		node* t = head;
		if(head == tail)
			head = tail = NULL;
		else 
			head = head->next;
		cout << "Employee deleted!!" << endl;
		cout << "SSN : " << t->ssn <<"\nName : " << t->name << "\nDepartment : " << "\nDesignation : " << t->desig << "\nSalary : " << t->sal << "\nPhone number : " << t->phone << endl; 
		free(t);
	}
}

void deleteEnd(){
	if(head == NULL)
		cout << "List is Empty" << endl;
	else{
		node* t = tail;
		if(head == tail)
			head = tail = NULL;
		else{
			tail = tail->prev;
			tail->next = NULL;
		} 
		cout << "Employee deleted!!" << endl;
		cout << "SSN : " << t->ssn <<"\nName : " << t->name << "\nDepartment : " << "\nDesignation : " << t->desig << "\nSalary : " << t->sal << "\nPhone number : " << t->phone << endl;
		free(t);		
	}
}

void display(){
	int count = 0;
	if(head == NULL)
		cout << "List is Empty" << endl;
	else{
		cout << "Employee Details : ";
		node* t = head;
		while(t != NULL){
			cout << "SSN : " << t->ssn <<"\nName : " << t->name << "\nDepartment : " << "\nDesignation : " << t->desig << "\nSalary : " << t->sal << "\nPhone number : " << t->phone << endl;
			t=t->next;
			++count;
		}
		cout << "\n\nNumber of employees is : " << count << endl;
	}
}

int main(){
	int ch;
	
	cout << "Employee Data : \n\t1.Create\n\t2.Display\n\t3.Insert at begining\n\t4.Insert at end\n\t5.Delete at begin\n\t6.Delete at end\n\t7.exit" << endl;
	
	while(1){
		cout << "\nEnter the choice : ";
		cin >> ch;
		
		switch(ch){
			case 1 : cout << "Enter the number of employee : ";
				 int n;
				 cin >> n;
				 for(int i = 0; i< n; i++){
				 	insertEnd();
				 	cout << endl;
				 }
				 break;
			case 2 : display();break;
			case 3 : insertBeg();break;
			case 4 : insertEnd();break;
			case 5 : deleteBeg();break;
			case 6 : deleteEnd();break;
			case 7 : cout << "Exiting the program " << endl;
				 return 0;
			default : cout << "Invalid choice " << endl;
		}
	}
	return 0;
}





