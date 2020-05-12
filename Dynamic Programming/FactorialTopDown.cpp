#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll fact(int n,int dp[]){
	if(n==0 || n==1){
		return 1;
	}
	if(dp[n] != 0){
		return dp[n];
	}
	ll ans;
	ans = n*fact(n-1,dp);
	return dp[n] = ans;
}

int main(){
	ll n;
	int dp[100] = {0};
	cin>>n;
	cout<<fact(n,dp)<<endl;
	return 0;
}
