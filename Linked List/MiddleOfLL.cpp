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

Node* middleOfLL(Node *head){
	Node *slow = head;
	Node *fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	Node *middle = middleOfLL(head);
	cout<<middle->data;
	return 0;
}
