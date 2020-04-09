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

void insertAtHead(Node *&head,int val){
	Node *temp = new Node(val);
	temp->next = head;
	head = temp;
}

void display(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

Node* reverseLL(Node *head){
	Node *C = head;
	Node *P = NULL;
	Node *N;
	while(C != NULL){
		N = C->next;
		C->next = P;
		P = C;
		C = N;
	}
	return P;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	display(head);
	Node *revHead = reverseLL(head);
	display(revHead);
	return 0;
}
