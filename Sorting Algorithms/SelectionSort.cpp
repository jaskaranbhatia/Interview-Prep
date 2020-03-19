#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int arr[],int n){
	int i,j,min_idx;
	for(int i=0;i<n-1;i++){
		min_idx = i;
		for(int j=i;j<n;j++){
			if(arr[j]<arr[min_idx]){
				min_idx = j;
			}
			swap(arr[min_idx],arr[i]);
		}
	}
}

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	print(arr,n);
	return 0;
}
