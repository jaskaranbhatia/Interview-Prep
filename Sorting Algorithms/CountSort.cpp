#include<iostream>
using namespace std;

void countSort(int arr[],int n){
	int output[n];
	int count[100] = {0};
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	for(int i=1;i<=100;i++){
		count[i] += count[i-1];
	}
	for(int i=0;i<n;i++){
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	for(int i=0;i<n;i++){
		arr[i] = output[i];
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	countSort(arr,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
