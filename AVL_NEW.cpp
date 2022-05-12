#include<bits/stdc++.h>
using namespace std;

class Node{

	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int height(Node *N){
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

Node* newNode(int key){

	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

Node *rightRotate(Node *node){

	Node *L = node->left;
	Node *LR = L->right;

	L->right = node;
	node->left = LR;	

	node->height = max(height(node->left),
					height(node->right)) + 1;
	L->height = max(height(L->left),
					height(L->right)) + 1;

	return L;
}

Node *leftRotate(Node *node) {

	Node *R = node->right;
	Node *RL = R->left;

	R->left = node;
	node->right = RL;

	node->height = max(height(node->left),
					height(node->right)) + 1;
	R->height = max(height(R->left),
					height(R->right)) + 1;

	return R;
}

int getBalance(Node *N){

	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key){
	
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key){

		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key){

		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void preOrder(Node *root){

	if(root != NULL){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node *root){

	if(root != NULL){
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

int main(){

	Node *root = NULL;

	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 10);
	root = insert(root, 14);
	
	preOrder(root);
	cout<<"\n";
	inOrder(root);
	return 0;
}

