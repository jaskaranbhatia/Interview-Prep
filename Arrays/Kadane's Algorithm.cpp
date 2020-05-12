#include<iostream>
using namespace std;

//Time Complexity - O(n)
void kadaneAlgo(int arr[],int n){
	int cs=0, ms=INT_MIN;
	for(int i=0;i<n;i++){
		cs += arr[i];
		if(cs > ms){
			ms = cs;
		}
		if(cs < 0){
			cs = 0;
		}
	}
	cout<<"Maximum is : "<<ms;
}

int main(){
	int arr[] = {-4,3,2,-1,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	kadaneAlgo(arr,n);
}
