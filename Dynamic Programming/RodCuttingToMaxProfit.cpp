#include<bits/stdc++.h>
using namespace std;

int memo[100];

int maxProfit(int arr[],int totalLen){
	if(totalLen == 0) return 0;
	int best  = 0;
	if(memo[totalLen] != -1){
		return memo[totalLen];
	}
	for(int len=1;len<=totalLen;len++){
		int netProfit = arr[len] + maxProfit(arr,totalLen-len);
		best = max(best,netProfit);
	}
	return memo[totalLen] = best;
}

int main(){
	int priceOfEachLen[100];
	int totalLen;
	cin>>totalLen;
	for(int eachPiece=1;eachPiece<=totalLen;eachPiece++){
		cin>>priceOfEachLen[eachPiece];
	}
	for(int i=0;i<=totalLen;i++){
		memo[i] = -1;
	}
	int ans = maxProfit(priceOfEachLen,totalLen);
	cout<<ans;
}

