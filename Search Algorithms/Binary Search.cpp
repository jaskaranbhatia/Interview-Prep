#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key) {
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] < key){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 4;
	int ans = binarySearch(arr,n,key);
	if(ans == -1){
		cout<<"Element not found";
	}
	else{
		cout<<key<<" found at index : "<<ans;
	}
	return 0;
}
