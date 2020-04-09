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

void rotateBy1(Node *&head){
	Node *prev = head;
	Node *temp = head->next;
	while(temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = head;
	head = temp;
}

void rotateLL(Node *&head,int k){
	for(int i=0;i<k;i++){
		rotateBy1(head);
	}
}

void insertAtHead(Node *&head,int val){
	Node *temp = new Node(val);
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

int main(){
	Node *head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	rotateLL(head,2);
	print(head);
}
