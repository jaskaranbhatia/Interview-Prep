#include<bits/stdc++.h>
using namespace std;

void printPair(pair<int,int> p){
	cout<<"("<<p.first<<","<<p.second<<") ";
}

void showStack(stack<pair<int,int>> s){
	while(!s.empty()){
		printPair(s.top());
		s.pop();
	}
}

int main(){
	stack<pair<int,int>> s;
	s.push({5,6});
	s.push({3,4});
	s.push({1,2});
	showStack(s);
}
