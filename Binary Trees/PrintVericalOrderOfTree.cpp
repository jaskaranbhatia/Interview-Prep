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

void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m) 
{ 
    if (root == NULL) 
        return; 
    m[hd].push_back(root->data); 
    getVerticalOrder(root->left, hd-1, m); 
    getVerticalOrder(root->right, hd+1, m); 
} 

void printVerticalOrder(Node* root) 
{ 
    map <int,vector<int>> m; 
    int hd = 0; 
    getVerticalOrder(root, hd,m); 
    map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    } 
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
	printVerticalOrder(root); 
}
