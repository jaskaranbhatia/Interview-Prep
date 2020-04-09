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

void push(Node *&head,int key){
	Node *temp = new Node(key);
	temp->next = head;
	head = temp;
}

Node* kthFromEnd(Node *head,int k){
	Node *slow = head;
	Node *fast = head;
	int count = 0;
	while(count < k){
		fast = fast->next;
		count++;
	}
	while(fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	Node *head = NULL;
	push(head,4);
	push(head,3);
	push(head,2);
	push(head,1);
	Node *kTh = kthFromEnd(head,2);
	cout<<kTh->data;
	return 0;
}
