#include<bits/stdc++.h>
using namespace std;

int minSteps(int n){
	int dp[n+1] = {0};
	dp[1] = 0;
	for(int i=2;i<=n;i++){
		int opt1,opt2,opt3;
		opt1 = opt2 = opt3 = INT_MAX;
		if(n%3 == 0){
			opt1 = dp[i/3] + 1;
		}
		if(n%2 == 0){
			opt2 = dp[i/2] + 1;
		}
		opt3 = dp[i-1] + 1;
		dp[i] = min(min(opt1,opt2),opt3);
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	cout<<minSteps(n);
	return 0;
}
