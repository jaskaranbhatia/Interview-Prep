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

void insertAtHead(Node *&head,int data){
	Node *temp = new Node(data);
	temp->next = head;
	head = temp;
}

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

Node* sort123(Node *head){
	Node *temp = head;
	Node *zeroN = NULL, *oneN = NULL, *twoN = NULL;
	while(temp != NULL){
		if(temp->data == 0){
			insertAtHead(zeroN,temp->data);
		}
		else if(temp->data == 1){
			insertAtHead(oneN,temp->data);
		}
		else if(temp->data == 2){
			insertAtHead(twoN,temp->data);
		}
		temp = temp->next;
	}
	Node *temp2 = zeroN;
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = oneN;
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = twoN;
	return zeroN;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,0);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	insertAtHead(head,0);
	insertAtHead(head,1);
	insertAtHead(head,2);
	Node *sortedList = sort123(head);
	print(sortedList);
	return 0;
}
