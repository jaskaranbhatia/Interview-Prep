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

Node* insertInBST(Node *root,int data){
	if(root == NULL){
		return new Node(data);
	}
	if(data <= root->data){
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

bool search(Node *root,int data){
	if(root == NULL){
		return false;
	}
	if(root->data == data){
		return true;
	}
	//Recursive Search
	if(data < root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

void inorder(Node *root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* deleteInBST(Node *root,int data){
	if(root == NULL){
		return NULL;
	}
	else if(data < root->data){
		root->left = deleteInBST(root->left,data);
		return root;
	}
	else if(data == root->data){
		//Found the Node for 3 cases
		//Node with 0 children
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		//Node with 1 childre
		if(root->left != NULL && root->right == NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		if(root->left == NULL && root->right != NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}
		//Node with 2 children
		Node *replace = root->right;
		while(replace->left != NULL){
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deleteInBST(root->right,replace->data);
		return root;
	}
	else{
		root->right = deleteInBST(root->right,data);
		return root;
	}
}

bool isBST(Node *root,int minV=INT_MIN,int maxV=INT_MAX){
	if(root == NULL){
		return true;
	}
	if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

int main(){
	Node *root = buildBST();
	inorder(root);
}


