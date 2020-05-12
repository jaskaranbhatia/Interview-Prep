#include<bits/stdc++.h>
using namespace std;

int maxProfit_bu(int arr[],int totalLen){
	int dp[100] = {};
	for(int len=1;len <= totalLen; len++){
		int best = 0;
		for(int cut=1;cut<=len;++cut){
			best = max(best,arr[cut] + dp[len-cut]);
		}
		dp[len] = best;
	}
	return dp[totalLen];
}

int main(){
	int priceOfEachLen[100];
	int totalLen;
	cin>>totalLen;
	for(int eachPiece=1;eachPiece<=totalLen;eachPiece++){
		cin>>priceOfEachLen[eachPiece];
	}
	int ans = maxProfit_bu(priceOfEachLen,totalLen);
	cout<<ans;
}

