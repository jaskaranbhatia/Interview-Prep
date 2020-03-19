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

class Queue{
	public:
	Node *front,*rear;
	Queue(){
		front = rear = NULL;
	}
	void enQueue(int x){
		Node *temp = new Node(x);
		if(rear == NULL){
			front = rear = temp;
		}
		rear->next = temp;
		rear = temp;
	}
	void deQueue(){
		if(front == NULL){
			return;
		}
		Node *temp = front;
		front = front->next;
		if(front == NULL){
			rear = NULL;
		}
		delete temp;
	}
};


int main() 
{ 
    Queue q; 
    q.enQueue(10); 
    q.enQueue(20); 
    q.deQueue(); 
    q.deQueue(); 
    q.enQueue(30); 
    q.enQueue(40); 
    q.enQueue(50); 
    cout << "Queue Front : " << (q.front)->data << endl; 
    cout << "Queue Rear : " << (q.rear)->data; 
} 
