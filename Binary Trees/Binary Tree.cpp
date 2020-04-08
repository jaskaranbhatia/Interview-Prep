#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
	Node *left;
	Node *right;
	int data;
	Node(int d){
		data  = d;
		left = NULL; 
		right = NULL;
	}
};

Node* buildTree(){
	//it is a preOrder Build of tree
	int d;
	cin>>d;
	if(d==-1) return NULL;
	Node *root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void preOrderPrint(Node *root){
	if(root == NULL ){
		return;
	}
	cout<<root->data<<" ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

void inOrderPrint(Node *root){
	if(root == NULL){
		return;
	}
	inOrderPrint(root->left);
	cout<<root->data<<" ";
	inOrderPrint(root->right);
}

void postOrderPrint(Node *root){
	if(root == NULL){
		return;
	}
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout<<root->data<<" ";
}

int height(Node *root){
	if(root == NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int h = max(h1,h2) + 1;
	return h;
}

void printKthLevel(Node *root,int k){
	if(root == NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
}

//Level Order Print - O(n^2)
void levelOrderPrint(Node *root){
	for(int i=1;i<=height(root);i++){
		printKthLevel(root,i);
		cout<<endl;
	}
}

//Level Order Print - O(n)
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
	return;
}

//each level on new level bfs - O(n)
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

int count(Node *root){
	if(root == NULL){
		return 0;
	}
	return count(root->left) + count(root->right) + 1;
}

int sum(Node *root){
	if(root == NULL){
		return 0;
	}
	return sum(root->left) + sum(root->right) + root->data;
}

//Diameter of a tree - O(n^2)
int diameter(Node *root){
	if(root == NULL){
		return 0;
	}
	int h1 = height(root->left) + height(root->right);
	int h2 = diameter(root->left);
	int h3 = diameter(root->right);
	return max(h1,max(h2,h3));
}

//Diameter of a tree - Optimized - Post Order Traversal
class Pair{
public:
	int height;
	int diameter;
};

Pair fastDiameter(Node *root){
	Pair p;
	if(root == NULL){
		p.diameter = p.height = 0;
		return p;
	}
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);
	p.height = max(left.height,right.height) + 1;
	p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
	return p;
}

//Sum Replacement of each Node with Sum of it's child nodes
int replaceSum(Node *root){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	//Recursive Part
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);
	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

//Height Balanced Tree - A Tree in which difference in height for every node is <=1 
class HBPair{
	public:
		int height;
		bool balance;
};

HBPair isHeightBalance(Node *root){
	HBPair p;
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Recursive Case
	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);
	p.height = max(left.height,right.height) + 1;
	if(abs(left.height-right.height)<=1 && left.balance && right.balance){
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	return p;
}

int main(){
	Node *root = buildTree();
	if(isHeightBalance(root).balance){
		cout<<"Balanced";
	}
	else{
		cout<<"Not Balanced";
	}
}

