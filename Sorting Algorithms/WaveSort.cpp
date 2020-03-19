#include<bits/stdc++.h>
using namespace std;

void WaveSort(int arr[],int n){
	for(int i=0;i<n;i+=2){
		//check for left element
		if(i>0 && arr[i-1]>arr[i]){
			swap(arr[i],arr[i-1]);
		}
		//check for right element
		if(i<=n-2 && arr[i+1]>arr[i]){
			swap(arr[i],arr[i+1]);
		}
	}
}

int main() {
	int arr[] = {0,1,2,3,4,5};
	WaveSort(arr,6);
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
}
