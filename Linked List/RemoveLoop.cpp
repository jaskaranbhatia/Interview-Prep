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

void removeTheLoop(Node* head)
{
    if (detectLoop(head) == 0)    
        return;
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise)   
    {
        hare = hare->next;
        tortoise = tortoise->next;
        hare = hare->next;
        if (hare == tortoise)
            break;
    }
    Node* begin = head;
    tortoise = tortoise->next;  
    while (begin != tortoise)   
    {
        begin = begin->next;
        if (tortoise->next == begin)  
        {
            tortoise->next = NULL;
            return;
        }
        tortoise = tortoise->next;
    }
}

Node* newNode(int key) 
{ 
    Node* temp = new Node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 

int main(){
	Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
    head->next->next->next->next->next = head->next->next; 
    removeTheLoop(head); 
    cout << "Linked List after removing loop" << endl; 
    printList(head); 
    return 0; 
} 


