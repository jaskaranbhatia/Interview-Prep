#include<bits/stdc++.h>
using namespace std;

void printPair(pair<int,int> p){
	cout<<"("<<p.first<<","<<p.second<<") ";
}

void showQueue(queue<pair<int,int>> gq){
	while(!gq.empty()){
		printPair(gq.front());
		gq.pop();
	}
	cout<<endl;
}

int main(){
	queue<pair<int,int>> gq;
	gq.push({10,20});
	gq.push({15,5});
	gq.push({1,5});
	showQueue(gq);
}
