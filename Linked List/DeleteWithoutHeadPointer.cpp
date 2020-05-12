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

void insertAtHead(Node *&head,int key){
	Node *temp = new Node(key);
	temp->next = head;
	head = temp;
}

void display(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void deleteNode(Node *node)
{
   swap(node->data,node->next->data);
   Node *temp = node->next;
   node->next = node->next->next;
   delete temp;
}

int main(){
	return 0;
}


