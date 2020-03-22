#include<iostream>
using namespace std;


void generateSubArray(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
	}
}

int main(){
	int arr[] = {5,3,1,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	generateSubArray(arr,n);
}
