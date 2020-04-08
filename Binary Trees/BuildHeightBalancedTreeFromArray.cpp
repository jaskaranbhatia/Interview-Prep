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

Node* buildTreeFromArray(int *arr,int s,int e){
	//Base Case
	if(s>e){
		return NULL;
	}
	//Recursive Case
	int mid = (s+e)/2;
	Node *root = new Node(arr[mid]);
	root->left = buildTreeFromArray(arr,s,mid-1);
	root->right = buildTreeFromArray(arr,mid+1,e);
	return root;
}

void bfs(Node *root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *f = q.front();
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

int main(){
	Node *root = NULL;
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	root = buildTreeFromArray(arr,0,n-1);
	bfs(root);
	return 0;
}
