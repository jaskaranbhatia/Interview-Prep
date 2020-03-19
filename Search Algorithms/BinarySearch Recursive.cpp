#include<iostream>
using namespace std;

int binarySearch(int arr[],int l,int r,int key){
	int mid = (l+r)/2;
	while(l<=r){
		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] < key){
			return binarySearch(arr,mid+1,r,key);
		}
		else{
			return binarySearch(arr,l,mid-1,key);
		}
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 2;
	int ans = binarySearch(arr,0,n-1,key);
	if(ans == -1){
		cout<<"Element not found";
	}
	else{
		cout<<key<<" found at index : "<<ans;
	}
	return 0;
}
