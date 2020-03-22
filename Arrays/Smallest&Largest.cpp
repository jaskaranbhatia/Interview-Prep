#include<iostream>
using namespace std;

void findLargestSmallest(int arr[],int n){
	int smallest = INT_MAX;
	int largest = INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i] < smallest){
			smallest = arr[i];
		}
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	cout<<"Smallest : "<<smallest<<endl;
	cout<<"Largest : "<<largest<<endl;
}

int main(){
	int arr[] = {5,4,1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	findLargestSmallest(arr,n);
}
