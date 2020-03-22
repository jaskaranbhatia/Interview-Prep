#include<iostream>
using namespace std;

//Time Complexity - O(n)
void kadaneAlgo(int arr[],int n){
	int cs=0, ms=0;
	for(int i=0;i<n;i++){
		cs += arr[i];
		if(cs < 0){
			cs = 0;
		}
		ms = max(cs,ms);
	}	
	cout<<"Maximum is : "<<ms;
}

int main(){
	int arr[] = {-4,1,3,-2,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	kadaneAlgo(arr,n);
}
