#include<bits/stdc++.h>
using namespace std;

vector<int> v[3];

void insertIntoArrayOfVector(){
	for(int i=0;i<3;i++){
		cout<<"Enter no of elements in "<<i<<"th Row : ";
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			int val;
			cin>>val;
			v[i].push_back(val);
		}
	}
}

void printElements(){
	for(int i=0;i<3;i++){
		cout<<"Elements at Index "<<i<<" : ";
		for(auto it = v[i].begin();it != v[i].end(); it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

int main(){
	insertIntoArrayOfVector();
	printElements();
}
