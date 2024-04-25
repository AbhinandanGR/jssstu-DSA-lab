#include<iostream>
#include<cstring>
using namespace std;

char infix[29], postfix[20], stack[20];
int top = -1;

int isempty(){
	if(top < 0)
		return 1;
	return 0;
}

void push(char symbol){
	stack[++top] = symbol;
}

int pop(){
	int temp = stack[top--];
	return temp;
}

int precedence(char symbol){
	switch(symbol){
		case '+' :
		case '-' :
			return 1;
		case '*' : 
		case '/' : 
		case '%' :
			return 2;
		case '^' : 
			return 3;
		default : 
			return 0;
	}
}

void infix_postfix(char *infix, char *postfix){
	int i, j = 0;
	char symbol, next;
	for(i = 0; i < strlen(infix); i++){
		symbol = infix[i];
		switch(symbol){
			case '(' : 
				push(symbol);
				break;
			case ')' :
				while((next = pop()) != '(')
					postfix[j++] = next;
				break;
			case '+' :
			case '-' :
			case '*' : 
			case '/' : 
			case '%' :
			case '^' :
				while(!isempty() && precedence(stack[top]) >= precedence(symbol))
					postfix[j++] = pop();
				push(symbol);
				break;
			default : postfix[j++] = symbol;
		}
	}
	while(!isempty())
		postfix[j++] = pop();
	postfix[j] = '\0';
}

int main(){
	cout << "Enter the valid infix expression : " << endl;
	cin >> infix;
	
	infix_postfix(infix, postfix);
	
	cout << "Infix expression : " << infix << endl;SQQQQ
	cout << "Postfix expression : " << postfix << endl;
	
	return 0;
}




