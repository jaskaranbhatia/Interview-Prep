#include<iostream>
#include<queue>
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

void insertNode(Node *root,int key){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
		q.pop();
		if(f->left == NULL){
			f->left = new Node(key);
			break;
		}
		else{
			q.push(f->left);
		}
		if(f->right == NULL){
			f->right = new Node(key);
			break;
		}
		else{
			q.push(f->right);
		}
	}
}

void bfs2(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left != NULL){
				q.push(f->left);
			}
			if(f->right != NULL){
				q.push(f->right);
			}	
		}
	}
	return;
}

bool search(Node *root,int key){
	if(root == NULL){
		return false;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
		if(f->data == key){
			return true;
		}
		q.pop();
		if(f->left != NULL){
			q.push(f->left);
		}
		if(f->right != NULL){
			q.push(f->right);
		}
	}
	return false;
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(10);
	root->left->left = new Node(20);
	root->right = new Node(34);
	insertNode(root,12);
	insertNode(root,24);
	insertNode(root,13);
	insertNode(root,99);
	if(search(root,99)){
		cout<<"It's Present";
	}
	else{
		cout<<"It's not Present";
	}
}

