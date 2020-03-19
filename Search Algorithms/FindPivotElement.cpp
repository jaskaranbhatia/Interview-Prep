#include<iostream>
using namespace std;

int findPivot(int arr[],int s,int e) {
	if(s>e){
		return -1;
	}
	while(s<=e){
		int mid = (s+e)/2;
		if(mid<e && arr[mid]>arr[mid+1]){
			return mid;
		}
		if(mid>s && arr[mid]<arr[mid-1]){
			return mid-1;
		}
		if(arr[s]>=mid){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return -1;
}

int main() {
	int a[] = {4,5,1,2,3};
    int b[] = {5,6,0,1,2,3};
    cout<<findPivot(a,0,4)<<endl;
	return 0;
}
