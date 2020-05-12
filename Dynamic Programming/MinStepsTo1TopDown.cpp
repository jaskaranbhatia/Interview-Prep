#include<bits/stdc++.h>
using namespace std;

int minSteps(int n,int dp[]){
	if(n==1){
		return 0;
	}
	if(dp[n] != 0){
		return dp[n];
	}
	int opt1, opt2, opt3;
	opt1 = opt2 = opt3 = INT_MAX;
	if(n%3 == 0){
		opt1 = minSteps(n/3,dp) + 1;
	}
	if(n%2 == 0){
		opt2 = minSteps(n/2,dp) + 1;
	}
	opt3 = minSteps(n-1,dp) + 1;
	return dp[n] = min(min(opt1,opt2),opt3);
}

int main(){
	int n;
	int dp[100] = {0};
	cin>>n;
	cout<<minSteps(n,dp);
}

