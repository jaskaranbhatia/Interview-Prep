#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void push(Node *&head,int data){
	Node *new_Node = new Node();
	new_Node->data = data;
	new_Node->next = head;
	head = new_Node;
}

int detectLoop(Node *head){
	Node *slow = head, *fast = head;
	while(slow != NULL && fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"Found Loop";
			return 1;
		}
	}
	return 0;
}

int main(){
	Node* head = NULL; 
    push(head, 20); 
    push(head, 4); 
    push(head, 15); 
    push(head, 10); 
    head->next->next->next->next = head; 
    detectLoop(head); 
    return 0; 
}

