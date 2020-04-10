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

void swapItems(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;	
}

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
void pairwiseSwap(Node *&head){
	Node *temp = head;
	while(temp != NULL && temp->next != NULL){
		swapItems(temp->data,temp->next->data);
		temp = temp->next->next;
	}
}

int main(){
	Node *head = NULL;
	insertAtHead(head,8);
	insertAtHead(head,7);
	insertAtHead(head,6);
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,2);
	insertAtHead(head,2);
	insertAtHead(head,1);
	pairwiseSwap(head);
	print(head);
}

