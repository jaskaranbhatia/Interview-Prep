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

bool checkPalindrome(Node *head){
	if(head == NULL || head->next == NULL){
		return true;
	}
	stack<int> s;
	Node *temp = head;
	while(temp != NULL){
		s.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp != NULL){
		if(s.top() != temp->data){
			return false;
		}
		s.pop();
		temp = temp->next;
	}
	return true;
}

int main(){
	Node *head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,1);
	if(checkPalindrome(head)){
		cout<<"It's a Palindrome\n";
	}
	else{
		cout<<"It's not a Palindrome\n";
	}
	return 0;
}
