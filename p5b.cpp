#include<iostream>
using namespace std;

void TOH(int n, char source, char aux, char dest){
	if(n == 1){
		cout << "Move disk 1 from " << source << " to " << dest << endl;
		return;
	}
	TOH(n-1, source, dest, aux);
	cout << "Move disk " << n << " from " << source << " to " << dest << endl; 
	TOH(n-1, aux, source, dest);
}

int main(){
	int n; 
	cout << "Enter the number of disks : " << endl;
	cin >> n;
	
	if(n <= 0)
		cout << "Number of disks should be positive integer" << endl;
	else
		TOH(n, 'A', 'B', 'C');
	
	return 0;
}



