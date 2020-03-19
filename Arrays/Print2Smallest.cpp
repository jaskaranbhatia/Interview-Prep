#include<bits/stdc++.h>
using namespace std;

void print2Smallest(int arr[],int n){
	int i,first,second;
	if(n < 2){
		cout<<" Invalid Input";
		return;
	}
	first = second = INT_MAX;
	for(i=0; i<n;i++){
		if(arr[i] < first){
			second = first;
			first = arr[i];
		}
		else if(arr[i]<second && arr[i] != first){
			second = arr[i];
		}
	}
	if(second == INT_MAX){
		cout<<"There is no second element";
	}
	else{
		cout<<"The smallest element is "<<first<<" and Second smallest is "<<second<<endl;
	}
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 1,9,4};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    print2Smallest(arr, n);  
    return 0;  
}

  
