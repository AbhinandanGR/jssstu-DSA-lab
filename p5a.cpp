#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

float stack[20];
int top = -1;

int isempty(){
	if(top < 0)
		return 1;
	else
		return 0;
}

void push(char symbol){
	stack[++top] = symbol;
}

int pop(){
	int temp = stack[top--];
	return temp;
}

float compute(char symbol, int op1, int op2){
	switch(symbol){
		case '+' : return op1 + op2;
		case '-' : return op1 - op2;
		case '*' : return op1 * op2;
		case '/' : return op1 / op2;
		case '%' : return op1 % op2;
		case '^' : return pow(op1, op2);
		default : return 0;
	}
}

int main(){
	float res, op1, op2;
	char postfix[20], symbol;
	
	cout << "Enter the postfix expression : ";
	cin >> postfix;
	
	for(int i = 0; i < strlen(postfix); i++){
		symbol = postfix[i];
		if(isdigit(symbol)){
			push(symbol - '0');
		}
		else{
			op2 = pop();
			op1 = pop();
			res = compute(symbol, op1, op2);
			push(res);
		}
	}
	res = stack[top];
	cout << "Result is : " << res << endl;
	
	return 0;
}



