#include<iostream>
using namespace std;

struct node{
	int data;
	node* right;
	node* left;
};

node* create(node* &root, int x){
	if(x == -1)
		return NULL;
	root = (struct node*)malloc(sizeof(struct node));
	root->right = NULL;
	root->left = NULL;
	root->data = x;
	
	cout << "Enter the number to insert in left subtree of " << x << " or enter -1" << endl;
	int d;
	cin >> d;
	root->left = create(root->left, d);
	
	cout << "Enter the number to insert in right subtree of " << x << " or enter -1" << endl;
	int c;
	cin >> c;
	root->right = create(root->right, c);
	return root;
}

void inorder(node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root){
	if(root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}


bool search(node* root, int key){
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;
	return search(root->left, key) || search(root->right, key);
}


int main(){
	int ch, k, key;
	node* root = NULL;
	do{
		cout << "\nBinary tree operation : \n\t1.Create\n\t2.preorder\n\t3.inorder\n\t4.postorder\n\t5.search\n\t6.Exit" << endl;
		cout << "Enter the choice : ";
		cin >> ch;
		
		switch(ch){
			case 1 : cout << "Enter the root : ";
				 cin >> k;
				 create(root, k);
				 break;
			case 2 : preorder(root);break;
			case 3 : inorder(root);break;
			case 4 : postorder(root);break;
			case 5 : cout << "Enter to search : ";
				 cin >> key;
				 if(search(root, key))
				 	cout << "Element is present" << endl;
				 else
				 	cout << "Element is not present " << endl;
				 break;
			case 6 : cout << "Exiting the program " << endl;
				 break;
			default : cout << "Invalid choice " << endl;
		}
	}while(ch != 6);
	return 0;
}



