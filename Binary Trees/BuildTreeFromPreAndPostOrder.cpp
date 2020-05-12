#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	Node *left;
	Node *right;
	char data;
	Node(char d){
		data  = d;
		left = NULL; 
		right = NULL;
	}
};

Node* createTreeFromInPre(char *in,char *pre,int s,int e){
	static int i = 0;
	//Base Case
	if(s>e){
		return NULL;
	}
	//Rec case
	Node *root = new Node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = createTreeFromInPre(in,pre,s,index-1);
	root->right = createTreeFromInPre(in,pre,index+1,e);
	return root;
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


int main(){
	char in[] = {'D','B','H','E','A','F','C','K','I','G','L','J'};
	char pre[] = {'A','B','D','E','H','C','F','G','I','K','J','L'};
	int n = sizeof(in)/sizeof(in[0]);
	Node *root = createTreeFromInPre(in,pre,0,n-1);
	bfs2(root);
	return 0;
}
