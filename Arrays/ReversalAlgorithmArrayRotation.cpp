#include<bits/stdc++.h>
using namespace std;

void ReverseArray(int arr[],int start,int end) {
	while(start < end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void ReversalAlgo(int arr[],int d,int n){
	if(d==0) return;
	ReverseArray(arr,0,d-1);
	ReverseArray(arr,d,n-1);
	ReverseArray(arr,0,n-1);
}

int main(){
	int arr[] = {1,2,3,4,5};
	ReversalAlgo(arr,2,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}	
}
