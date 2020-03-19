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

class Stack{
	Node *head;
public:
	Stack(){
		head = NULL;
	}
	bool isEmpty(){
		return head == NULL;
	}
	void push(int x){
		if(head == NULL){
			head = new Node(x);
			return;
		}
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
	}	
	void pop(){
		if(head==NULL){
			return;
		}
		Node *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	int top(){
		return head->data;
	}
};

int main(){
	Stack s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	while(!s.isEmpty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}







