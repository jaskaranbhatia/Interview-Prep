#include<bits/stdc++.h>
using namespace std;

int minCoins(int n,int coins[],int T,int dp[]){
	if(n==0){
		return 0;
	}
	if(dp[n] != 0){
		return dp[n];
	}
	int ans = INT_MAX;
	for(int i=0;i<T;i++){
		if(n-coins[i] >= 0){
			int subpro = minCoins(n-coins[i],coins,T,dp);
			ans = min(ans,subpro+1);
		}
	}
	dp[n] = ans;
}

int main(){
	int N = 15;
	int coins[] = {1,7,10};
	int dp[100] = {0};
	int T = sizeof(coins)/sizeof(coins[0]);
	cout<<minCoins(N,coins,T,dp)<<endl;
	return 0;
}
