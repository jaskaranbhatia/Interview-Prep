#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	Node *left;
	Node *right;
	int data;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

class LinkedList{
	public:
	Node *head;
	Node *tail;
};

Node* insertInBST(Node *root,int data){
	if(root == NULL){
		return new Node(data);
	}
	if(data<=root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
}

Node* buildBST(){
	int d;
	cin>>d;
	Node *root = NULL;
	while(d != -1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}

void inorder(Node *root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

LinkedList flatten(Node *root){
	LinkedList l;
	if(root == NULL){
		l.head = l.tail = NULL;
	}
	//Leaf Node Case
	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	if(root->left != NULL && root->right == NULL){
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	if(root->left == NULL && root->right != NULL){
		LinkedList rightLL = flatten(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);
	leftLL.tail->right = root;
	root->right = rightLL.head;
	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}

int main(){
	Node *root = buildBST();
	LinkedList l = flatten(root);
	Node *temp = l.head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}


