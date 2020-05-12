#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void insert(Node *root,int data){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
		q.pop();
		if(f->left == NULL){
			f->left = new Node(data);
			break;
		}
		else{
			q.push(f->left);
		}
		if(f->right == NULL){
			f->right = new Node(data);
			break;
		}
		else{
			q.push(f->right);
		}
	}
}

void leftView(Node *root,int level,int* max_level){
	if(root == NULL){
		return;
	}
	if(*max_level < level){
		cout<<root->data<<" ";
		*max_level = level; 
	}
	leftView(root->left,level+1,max_level);
	leftView(root->right,level+1,max_level);
}

void inOrder(Node *root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	Node *root = new Node(5);
	insert(root,4);
	insert(root,3);
	insert(root,2);
	insert(root,1);
	int max_level = 0;
	leftView(root,1,&max_level);
	cout<<endl;
	inOrder(root);
}
