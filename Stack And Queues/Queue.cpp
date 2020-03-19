#include<iostream>
#define MAX 10
using namespace std;

class Queue{
	int r,f,arr[MAX];
public:
	Queue(){
		f = -1;
		r = -1;
	}
	bool isFull(){
		if( (r+1)%MAX == f){
			return true;
		} 
		else{
			return false;
		}
	}
	bool isEmpty(){
		return f == -1;
	}
	void enque(int data){
		if(isFull()){
			cout<<"Queue is Full";
		}
		else{
			r = (r+1)%MAX;
			if(f == -1){
				f = r;
			}
			arr[r] = data;
		}
	}
	void deque(){
		if(isEmpty()){
			cout<<"Queue is Empty";
			return;
		}
		if(f == r){
			f = -1;
			r = -1;
		}
		else{
			f = (f+1)%MAX;
		}
	}
	void display(){
		for(int i=f;i<=r;i++){
			cout<<arr[i]<<" ";
		}
	}
};

int main(){
	Queue q;
	q.enque(1);
	q.enque(2);
	q.enque(3);
	q.enque(4);
	q.deque();
	q.display();
}
