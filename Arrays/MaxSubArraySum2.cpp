#include<iostream>
using namespace std;

void maxSubArraySum(int arr[],int n){
	//We use the concept of precomputing - O(n^2)
	int cumSum[n];
	int csum,max_sum = INT_MIN;
	cumSum[0] = arr[0];
	for(int i=1;i<n;i++){
		cumSum[i] = cumSum[i-1] + arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			csum = cumSum[j] - cumSum[i-1];
			if(csum > max_sum){
				max_sum = csum;
			}
		}
	}
	cout<<max_sum;
}

int main(){
	int arr[] = {-4,1,3,-2,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	maxSubArraySum(arr,n);
}
