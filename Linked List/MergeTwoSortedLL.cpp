#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

void insertAtHead(Node *&head,int key){
	Node *temp = new Node(key);
	temp->next = head;
	head = temp;
}

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

Node* mergeLL(Node *a,Node *b){
	Node *result = NULL;
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	if(a->data < b->data){
		result = a;
		result->next = mergeLL(a->next,b);
	}
	else{
		result = b;
		result->next = mergeLL(a,b->next);
	}
	return result;
}

int main(){
	Node *head1 = NULL, *head2 = NULL;
	insertAtHead(head1,5);
	insertAtHead(head1,3);
	insertAtHead(head1,1);
	insertAtHead(head2,4);
	insertAtHead(head2,2);
	Node *newLL = mergeLL(head1,head2);
	print(newLL);
	return 0;
}
