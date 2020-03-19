#include<iostream>
using namespace std;

int upperBound(int arr[],int n,int key) {
	int s = 0;
	int e = n-1;
	int ans = -1;
	while(s <= e) {
		int mid = (s+e)/2;
		if(arr[mid] == key){
			ans = mid;
			s = mid + 1;
		}
		else if(arr[mid] < key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
}

int main(){
	int arr[] = {1,1,2,2,2,2,2,3,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int ans = upperBound(arr,n,2);
	cout<<ans<<endl;
}
