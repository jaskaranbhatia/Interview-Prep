#include<iostream>
using namespace std;

int partition(int arr[],int l, int r){
	int pivot = arr[r];
	int i = l-1;
	for(int j=l;j<r;j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return (i+1);	
}

void quickSort(int arr[],int l,int r){
	if(l<r){
		int p = partition(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
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
	quickSort(arr,0,n-1);
	print(arr,n);
	return 0;
}
