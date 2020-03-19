#include<bits/stdc++.h>
using namespace std;

void leftRotateBy1(int arr[],int n){
	int temp = arr[0];
	int i;
	for(i=0;i<n-1;i++){
		arr[i] = arr[i+1];
	}
	arr[i] = temp;
}

void leftRotate(int arr[],int k,int n){
	for(int i=0;i<k;i++){
		leftRotateBy1(arr,n);
	}
}

int main() {
	int arr[] = {1,2,3,4,5};
	leftRotate(arr,2,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
