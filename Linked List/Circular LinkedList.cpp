#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int d){
			data = d;
			next = NULL;
		}
};

void insertAtHead(Node *&last,int val){
	if(last == NULL){
		last = new Node(val);
		last->next = last;
	}
	else{
		Node *temp = new Node(val);
		temp->next = last->next;
		last->next = temp;
	}
}

void insertAtTail(Node *&last,int val){
	if(last==NULL){
		last = new Node(val);
		last->next = last;
	}
	else{
		Node *temp = new Node(val);
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void deleteAtHead(Node *&last){
	if(last == NULL){
		return;
	}
	Node *temp = last->next;
	last->next = last->next->next;
	delete temp;
}

void deleteAtTail(Node *&last){
	if(last == NULL){
		return;
	}
	Node *temp = last->next;
	while(temp->next != last){
		temp = temp->next;
	}
	temp->next = last->next;
	delete last;
	last = temp;
}

void print(Node *last){
	Node *temp = last->next;
	while(temp != last){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<" ";
	temp = temp->next;
	cout<<temp->data<" ";
}

int main(){
	Node *last = NULL;
	insertAtHead(last,3);
	insertAtHead(last,2);
	insertAtHead(last,1);
	insertAtTail(last,4);
	insertAtTail(last,5);
	deleteAtHead(last);
	deleteAtTail(last);
	print(last);
}
