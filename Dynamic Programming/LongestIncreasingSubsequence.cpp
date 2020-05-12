#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
	int dp[n];
	for(int i=0;i<n;i++){
		dp[i] = 1;
	}
	int best = -1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j] <= arr[i]){
				//jth element can be observed by ith element
				int curLen = 1 + dp[j];
				dp[i] = max(curLen,dp[i]);
			}
		}
		best = max(best,dp[i]);
	}
	return best;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = lis(arr,n);
	cout<<ans;
}
