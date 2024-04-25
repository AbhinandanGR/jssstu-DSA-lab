#include<iostream>
#include<cmath>
using namespace std;

struct poly{
    float coeff;
    int x, y, z;
    poly* next;
};

poly* p1 = NULL;
poly* p2 = NULL;
poly* p3 = NULL;

poly* readypoly(){
    poly* temp = new poly();
    cout << "Enter coeff : ";
    cin >> temp->coeff;
    cout << "Enter x expon : ";
    cin >> temp->x;
    cout << "Enter y expon : ";
    cin >> temp->y;
    cout << "Enter z expon : ";
    cin >> temp->z;
    return temp; 
}

poly* create(){
    int n;
    cout << "Enter the number of terms : ";
    cin >> n;
    poly* temp = new poly();
    poly* t1 = temp;
    for(int i = 0; i < n; i++, t1 = t1->next)
        t1->next = readypoly();
    t1->next = temp;
    return temp;
}

void evaluate(){
    float sum = 0;
    int x, y, z;
    poly* t = p1->next;
    cout << "\nEnter x, y and z : ";
    cin >> x >> y >> z;
    while(t != p1){
        sum+=t->coeff * pow(x,t->x) * pow(y, t->y) * pow(z, t->z);
        t = t->next;  
    }
    cout << "Sum = " << sum << endl;
}

void display(poly* p){
    poly* t = p->next;
    while(t != p){
        if(t != p->next && t->coeff > 0)
            cout << " + ";
        //else if(t->coeff < 0)
          //  cout << " - ";
        cout << t->coeff << " X^" << t->x << " Y^" << t->y << " Z^" << t->z;
        t= t->next;
    }
}

poly* attach(float coeff, int x, int y, int z, poly* p){
    poly* t = new poly();
    t->coeff = coeff;
    t->x = x;
    t->y = y;
    t->z = z;
    p->next = t;
    return t;
}

poly* add(){
    cout << "Polynomial 1 : " << endl;
    p1 = create();
    cout << "Polynomial 2 : " << endl;
    p2 = create();
    int flag;
    poly* t1 = p1->next;
    poly* t2 = p2->next;
    poly* t3;
    p3 = new poly();
    t3 = p3;
    
    while(t1 != p1 && t2 != p2){
        if(t1->x > t2->x)
            flag = 1;
        else if(t1->y < t2->y)
            flag = -1;
        else if(t1->z == t2->z)
            flag = 0;
        
        switch(flag){
            case 0 :
                t3 = attach(t1->coeff + t2->coeff, t1->x, t1->y,t1->z,t3);
                t1 = t1->next;
                t2 = t2->next;
                break;
            case 1 : 
                t3 = attach(t1->coeff, t1->x, t1->y,t1->z,t3);
                t1 = t1->next;
                break;
            case -1 :
                t3 = attach(t2->coeff, t2->x, t2->y,t2->z,t3);
                t2 = t2->next;
                break;
        }
    }
    for(; t1 != p1; t1 = t1->next)
        t3 = attach(t1->coeff, t1->x, t1->y,t1->z,t3);
    for(; t2 != p2; t2 = t2->next)
        t3 = attach(t2->coeff, t2->x, t2->y,t2->z,t3);
    
    t3->next = p3;
    return p3;        
}

int main()
{
    int ch;
    cout << "1. Represent and evaluate polynomial\n2. Add 2 polynomials\n3. Exit\nEnter choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        p1 = create();
        display(p1);
        evaluate();
        break;
    case 2:
        p3 = add();
        cout << "\nPolynomial1:\n";
        display(p1);
        cout << "\nPolynomial2:\n";
        display(p2);
        cout << "\nP1 + P2:\n";
        display(p3);
        break;
    case 3:
        exit(0);
    default:
        cout << "\nInvalid choice…!";
    }
    return 0;
}


/*

#include<iostream>
#include<cmath>
using namespace std;

struct poly{
	float coeff;
	int x, y, z;
	poly* next;
};

poly* p1 = NULL;
poly* p2 = NULL;
poly* p3 = NULL;

poly* readypoly(){
	poly* temp = new poly;
	cout << "Enter coeff : ";
	cin >> temp->coeff;
	cout << "Enter x expon : ";
	cin >> temp->x;
	cout << "Enter y expon : ";
	cin >> temp->y;
	cout << "Enter z expon : ";
	cin >> temp->z;
	return temp; 
}

poly* create(){
	int n;
	cout << "Enter the number of terms : ";
	cin >> n;
	poly* temp = new poly;
	poly* t1 = temp;
	for(int i = 0; i < n; i++) {
		t1->next = readypoly();
		t1 = t1->next;
	}
	t1->next = temp;
	return temp;
}

void evaluate(){
	float sum = 0;
	int x, y, z;
	poly* t = p1->next;
	cout << "\nEnter x, y and z : ";
	cin >> x >> y >> z;
	while(t != p1){
		sum+=t->coeff * pow(x,t->x) * pow(y, t->y) * pow(z, t->z);
		t = t->next;  
	}
	cout << "Sum = " << sum << endl;
}

void display(poly* p){
	poly* t = p->next;
	while(t != p){
		if(t->coeff > 0 && t != p->next)
			cout << " + ";
		else if(t->coeff < 0)
			cout << " - ";
		cout << abs(t->coeff) << " X^" << t->x << " Y^" << t->y << " Z^" << t->z;
		t= t->next;
	}
	cout << endl;
}

poly* attach(float coeff, int x, int y, int z, poly* p){
	poly* t = new poly;
	t->coeff = coeff;
	t->x = x;
	t->y = y;
	t->z = z;
	p->next = t;
	return t;
}

poly* add(){
	cout << "Polynomial 1 : " << endl;
	p1 = create();
	cout << "Polynomial 2 : " << endl;
	p2 = create();
	int flag;
	poly* t1 = p1->next;
	poly* t2 = p2->next;
	poly* t3;
	p3 = new poly;
	t3 = p3;
	
	while(t1 != p1 && t2 != p2){
		if(t1->x > t2->x)
			flag = 1;
		else if(t1->y > t2->y)
			flag = -1;
		else if(t1->z > t2->z)
			flag = -1;
		else
			flag = 0;
		
		switch(flag){
			case 0 :
				t3 = attach(t1->coeff + t2->coeff, t1->x, t1->y,t1->z,t3);
				t1 = t1->next;
				t2 = t2->next;
				break;
			case 1 : 
				t3 = attach(t1->coeff, t1->x, t1->y,t1->z,t3);
				t1 = t1->next;
				break;
			case -1 :
				t3 = attach(t2->coeff, t2->x, t2->y,t2->z,t3);
				t2 = t2->next;
				break;
		}
	}
	for(; t1 != p1; t1 = t1->next)
		t3 = attach(t1->coeff, t1->x, t1->y,t1->z,t3);
	for(; t2 != p2; t2 = t2->next)
		t3 = attach(t2->coeff, t2->x, t2->y,t2->z,t3);
	
	t3->next = p3;
	return p3;
		
}

int main(){
	int ch;
	cout << "\n1. Represent and evaluate polynomial\n2. Add two polynomials\n3. Exit" << endl;
	cout << "Enter your choice : ";
	cin >> ch;
	
	switch(ch){
		case 1 : p1 = create();
			 display(p1);
			 evaluate();
			 break;
		case 2 : p3 = add();
			 cout << "Polynomial 1 : " << endl;
			 display(p1);
			 cout << "Polynomial 2 : " << endl;
			 display(p2);
			 cout << "P1 + P2 : " << endl;
			 display(p3);
			 break;
		case 3 :
			return 0;
		default : cout << "Invalid choice!! " << endl;  
	}
	
	return 0;
}

*/



