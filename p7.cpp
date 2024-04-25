#include<iostream>
using namespace std;

struct stud{
	char name[20], usn[15], branch[4], phone[11];
	int sem;
	stud* next;
};

stud* createNode(){
	stud* t = (struct stud*)malloc(sizeof(struct stud));
	cout << "Enter the USN : ";
	cin >> t->usn;
	cout << "Enter the name : ";
	cin >> t->name;
	cout << "Enter the branch : ";
	cin >> t->branch;
	cout << "Enter the sem : ";
	cin >> t->sem;
	cout << "Enter the phone number : ";
	cin >> t->phone;
	t->next = NULL;
	return t;
}

void insertBeg(stud* &head, stud* &tail){
	stud* t = createNode();
	if(head == NULL)
		head = tail = t;
	else{
		t->next = head;
		head = t;
	}
}

void insertEnd(stud* &head, stud* &tail){
	stud* t = createNode();
	if(head == NULL)
		head = tail = t;
	else{
		tail->next = t;
		tail = t;
	}
}

void deleteBeg(stud* &head, stud* &tail){
	if(head == NULL)
		cout << "List is empty"  << endl;
	else{
		stud* t = head;
		if(head == tail)
			head = tail = NULL;
		else 
			head = head->next;
		cout << "Element deleted!!" << endl;
		cout << "USN : " << t->usn << "\nName : " << t->name << "\nBranch : " << t->branch << "\nSem : " << t-> sem << "\nPhone Number : " << t->phone << endl;
		free(t);
	}
}

void deleteEnd(stud* &head, stud* &tail){
	if(head == NULL)
		cout << "List is empty"  << endl;
	else{
		stud* t = head;
		if(head == tail)
			head = tail = NULL;
		else{
			stud* prev = NULL;
			while(t->next != NULL){
				prev = t;
				t = t->next;
			}
			tail = prev;
			tail->next = NULL;
		}
		cout << "Element deleted!!" << endl;
		cout << "USN : " << t->usn << "\nName : " << t->name << "\nBranch : " << t->branch << "\nSem : " << t-> sem << "\nPhone Number : " << t->phone << endl;
		free(t);
	}
		
}

void display(stud* &head){
	if(head == NULL)
		cout << "List is empty"  << endl;
	else{
		stud* t = head;
		while(t != NULL){
			cout << "USN : " << t->usn << "\nName : " << t->name << "\nBranch : " << t->branch << "\nSem : " << t-> sem << "\nPhone Number : " << t->phone << endl;
			t = t->next;
		}
	}
}

int main(){
	int choice, n;
	stud *head = NULL, *tail = NULL;
	do{
		cout << "Student Data\n\t1.Create\n\t2.Display\n\t3.Insert at begining\n\t4.Insert at end\n\t5.Delete at Begining\n\t6.Delete at End\n\t7.Exit"<< endl;
		cout << "Enter your choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : cout << "Enter the number of students : ";
				 cin >> n;
				 for(int i = 0; i < n; i++){
				 	insertEnd(head, tail);
				 	cout << endl;
				 }
				 break;
			case 2 : display(head);
				 break;
			case 3 : insertBeg(head, tail);
				 break;
			case 4 : insertEnd(head, tail);
				 break;
			case 5 : deleteBeg(head, tail);
				 break;
			case 6 : deleteEnd(head, tail);
				 break;
			case 7 : cout << "Exiting the program " << endl;
				 break;
			default : cout << "Invalid choice " << endl;
		}
	}while(choice != 7);
	return 0;	
}



