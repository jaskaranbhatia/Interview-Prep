#include<iostream>
using namespace std;

class Stack{
	int n;
	int *arr;
	int top;
	public:
	Stack(int n){
		arr = new int[n];
		top = -1;
	}
	bool isFull(){
		return top == n-1;
	}
	bool isEmpty(){
		return top == -1;
	}
	void push(int data){
		if(isFull()){
			cout<<"Stack is Full"<<endl;
		}
		else{
			top++;
			arr[top] = data;
		}
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack Empty";
		}
		else{
			top--;
		}
	}
	int top_v(){
		return arr[top];
	}
};

int main(){
	Stack s(1000);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	while(!s.isEmpty()){
		cout<<s.top_v()<<" ";
		s.pop();
	}
}
