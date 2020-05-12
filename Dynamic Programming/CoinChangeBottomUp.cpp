#include<bits/stdc++.h>
using namespace std;

int minCoins(int N,int coins[],int T){
	int dp[N+1] = {0};
	for(int n=1;n<=N;n++){
		dp[n] = INT_MAX;
		for(int i=0;i<T;i++){
			if(n-coins[i] >= 0){
				int subprob = dp[n-coins[i]];
				dp[n] = min(dp[n],subprob+1);
			}
		}
	}
	return dp[N];
}

int main(){
	int N;
	cin>>N;
	int coins[] = {1,7,10};
	int T = sizeof(coins)/sizeof(coins[0]);
	cout<<minCoins(N,coins,T);
	return 0;
}
