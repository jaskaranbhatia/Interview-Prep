#include<bits/stdc++.h>
using namespace std;

class Stack{
	stack<int> s;
	int minEle;
public:
	void getMin(){
		if(s.empty()){
			cout<<"Stack is Empty\n";
		}
		else{
			cout<<"Minimum Element is "<<minEle<<"\n";
		}
	}
	void top(){
		if(s.empty()){
			cout<<"Stack is Empty";
			return;
		}
		int t = s.top();
		if(t<minEle){
			cout<<"Top Element is : "<<minEle;
		}
		else{
			cout<<"Top Element is : "<<minEle;
		}
	}
	void pop(){
		if(s.empty()){
			cout<<"Stack is empty\n";
			return;
		}	
		int t = s.top();
		s.pop();
		if(t<minEle){
			minEle = 2*minEle - t;
		}
	}
	void push(int x){
		if(s.empty()){
			minEle = x;
			s.push(x);
			return;
		}
		if(x<minEle){
			s.push(2*x - minEle);
			minEle = x;
		}
		else{
			s.push(x);
		}
	}
};

int main(){
	Stack s;
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(2);
	s.pop();
	s.pop();
	s.getMin();
}

