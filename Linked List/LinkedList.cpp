#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int d){
		this->data = d;
		this->next = NULL;
	}
};

void insertAtHead(Node *&head,int val){
	Node *temp = new Node(val);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node *&head,int val){
	if(head == NULL){
		head = new Node(val);
		return;
	}
	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}	
	temp->next = new Node(val);
}

int length(Node *head){
	int count = 0;
	while(head != NULL){
		head = head->next;
		count++;
	}
	return count;
}

void insertInMiddle(Node *&head,int val,int p){
	if(p==0){
		insertAtHead(head,val);
	}
	else if(p>=length(head)){
		insertAtTail(head,val);
	}
	else{
		int count = 1;
		Node *temp = head;
		while(count < p){
			temp = temp->next;
			count++;
		}
		Node *n = temp->next;
		Node *ne = new Node(val);
		temp->next = ne;
		ne->next = n;
	}
}

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void deleteAtHead(Node *&head){
	if(head == NULL){
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(Node *&head){
	if(head == NULL){
		return;
	}
	Node *prev = head;
	Node *temp = head->next;
	while(temp->next != NULL){
		prev = prev->next;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
}

void deleteAtMiddle(Node *&head,int p){
	int count = 1;
	if(p = 0){
		return;
	}
	if(p>length(head)){
		deleteAtTail(head);
	}
	Node *temp = head;
	while(count < p){
		temp = temp->next;
		count++;
	}
	Node *n = temp->next->next;
	delete temp->next;	
	temp->next = n;
}

Node* middleOfLL(Node *head){
	Node *slow = head;
	Node *fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void reverseLL(Node *&head){
	Node *c = head;
	Node *p = NULL;
	Node *n;
	while(c!=NULL){
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}

Node* kthFromEnd(Node *head, int k){
	int count = 0;
	Node *runner = head;
	while(count < k){
		runner = runner->next;
		count++;
	}
	while(runner != NULL){
		head = head->next;
		runner = runner->next;
	}
	return head;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,12);
	insertAtHead(head,14);
	insertAtHead(head,32);
	insertAtHead(head,20);
	insertAtTail(head,25);
	insertInMiddle(head,23,2);
//	deleteAtHead(head);
//	deleteAtTail(head);
//	deleteAtMiddle(head,2);
//	Node *middle = middleOfLL(head);
//	Node *kth = kthFromEnd(head,2);
//	cout<<"Original LL is : ";
//	print(head);
	reverseLL(head);
//	int len = length(head);
	cout<<"Reverse of LL is : ";
	print(head);
//	cout<<"Middle Element of LL is : "<<middle->data<<endl;
//	cout<<"Kth from end : "<<kth->data<<endl;
//	cout<<"Length of LL : "<<len;
	return 0;
}

