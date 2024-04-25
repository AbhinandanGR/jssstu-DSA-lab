#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

bool search(node* root, int key){
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;
	return search(root->left, key) || search(root->right, key);
}

node* create(int val){
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

node* insert(node* &root, int val){
	if(root == NULL)
		return create(val);
	if(val < root->data)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return root;
}

int main(){
	int ch, n, k, key;
	node* root = NULL;
	do{
		cout << "Binary Search Tree Operation : \n\t1.Create\n\t2.Traversal\n\t3.Search\n\t4.Exit\n";
		cout << "Enter the choice : ";
		cin >> ch;
		
		switch(ch){
			case 1 : cout << "Enter the number of nodes : ";
				 cin >> n;
				 for(int i = 0; i < n; i++){
				 	cout << "Enter the node : ";
				 	cin >> k;
				 	root = insert(root, k);
				 }
				 break;
			case 2 : inorder(root); cout << endl;
				 preorder(root); cout << endl;
				 postorder(root); cout << endl;
				 break;
			case 3 : cout << "Enter the number to be searched : ";
				 cin >> key;
				 if(search(root, key))
				 	cout << "Element is present " << endl;
				 else 
				 	cout << "Element is not present " << endl;
				 break;
			case 4 : cout << "Exiting the program" << endl;
				 break;
			default : cout << "Invalid choice!!" << endl;
		}
	}while(ch != 4);

	return 0;
}




