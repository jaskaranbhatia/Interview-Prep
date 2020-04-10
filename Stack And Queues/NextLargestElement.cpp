#include<bits/stdc++.h>
using namespace std;

void findNextLargest(int arr[],int n){
	stack<int> s;
	s.push(arr[0]);
	for(int i=1;i<n;i++){
		while(!s.empty() && s.top() < arr[i]){
			cout<<arr[i]<<" ";
			s.pop();
		}
		s.push(arr[i]);
	}
	while(!s.empty()){
		cout<<"-1"<<" ";
		s.pop();
	}
}
//Performs very bad when arrat is in descending order
int main(){
	int arr[] = {11,13,21,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	findNextLargest(arr,n);
}
