#include<iostream>
using namespace std;

void maxSubArraySum(int arr[],int n){
	int csum;
	int max_sum = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			csum = 0;
			for(int k=i;k<=j;k++){
				csum += arr[k];
				if(csum > max_sum){
					max_sum = csum;
				}
			}
		}
	}
	cout<<max_sum<<endl;	
}

int main(){
	int arr[] = {-4,1,3,-2,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	maxSubArraySum(arr,n);
}

