#include<bits/stdc++.h>
using namespace std;

bool cmp(char b,char c){
	if(b=='{' && c=='}') return true;
	else if(b=='[' && c==']') return true;
	else if(b=='(' && c==')') return true;
	return false;
}

bool isBalanced(string x){
	stack<char> s;
	for(int i=0;i<x.size();i++){
		if(x[i] == '[' || x[i] =='{' || x[i] == '('){
			s.push(x[i]);
		}
		else if(x[i] == ']' || x[i] == '}' || x[i] == ')'){
			if(s.empty() || !cmp(s.top(),x[i])) return false;
			else{
				s.pop();
			}
		}
	}
	if(s.empty()){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string query;
	cin>>query;
	cout<<isBalanced(query);
}
