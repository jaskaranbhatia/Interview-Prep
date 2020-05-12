#include<bits/stdc++.h>
using namespace std;

int fib(int n,int dp[]){
	if(n==0||n==1){
		return n;
	}
	if(dp[n] != 0){
		return dp[n];
	}
	int ans;
	ans = fib(n-1,dp) + fib(n-2,dp);
	return dp[n] = ans;
}

int main(){
	int n;
	int dp[100] = {0};
	cin>>n;
	cout<<fib(n,dp)<<endl;
	return 0;
}
