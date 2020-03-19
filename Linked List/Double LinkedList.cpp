#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		Node(int d){
			data = d;
			next = NULL;
			prev = NULL;
		}
};

void insertAtHead(Node *&head,int val){
	Node *temp = new Node(val);
	temp->next = head;
	if(head != NULL){
		head->prev = temp;
	}
	head = temp;
}

void insertAtTail(Node *&head,int data){
	if(head == NULL){
		insertAtHead(head,data);
	}
	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node *ne = new Node(data);
	temp->next = ne;
	ne->prev = temp;
}

int length(Node *head){
	int count = 0;
	while(head != NULL){
		head = head->next;
		count++;
	}
	return count;
}

void insertAtMiddle(Node *&head,int data,int p){
	if(p==0){
		insertAtHead(head,data);
	}
	else if(p>length(head)){
		insertAtTail(head,data);
	}
	else{
		int count=1;
		Node *temp = head;
		while(count<p){
			temp = temp->next;
			count++;
		}
		Node *ne = new Node(data);
		ne->next = temp->next;
		temp->next->prev = ne;
		temp->next = ne;
		ne->prev = temp;
	}
}
void deleteATHead(Node *&head){
	Node*ptr=head;
	if(head==NULL){
		return;
	}
	head=head->next;
	delete ptr;
	head->prev=NULL;
}
void display(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
void deleteATTail(Node *&head){
	if(head == NULL){
		return;
	}
	Node *ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	ptr->prev=NULL;
	delete(ptr);
}

void deleteAtMiddle(Node *&head,int p){
	if(p==0){
		return;
	}
	else if(p>length(head)){
		deleteATTail(head);
		return;
	}
	int count = 1;
	Node *temp = head;
	while(count<p){
		temp = temp->next;
		count++;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = NULL;
	temp->prev = NULL;
	delete temp;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtTail(head,4);
	insertAtMiddle(head,7,2);
	deleteAtMiddle(head,2);
	display(head);
	cout<<endl<<length(head);
}
