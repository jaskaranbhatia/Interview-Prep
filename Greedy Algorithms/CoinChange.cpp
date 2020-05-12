#include<bits/stdc++.h>
using namespace std;

int make_change(int *coins,int n,int money){
	int ans;
	while(money>0){
		int idx = upper_bound(coins,coins+n,money) - coins - 1;
		cout<<coins[idx]<<" ";
		money = money - coins[idx];
		ans++;
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int t = sizeof(coins)/sizeof(int);
	int ans = make_change(coins,t,n);
	cout<<endl<<"No of coins needed = "<<ans;
}
