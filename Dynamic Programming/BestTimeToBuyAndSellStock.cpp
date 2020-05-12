#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
	if(prices.size() == 0) return 0;
	int min = prices[0];
	int maxProfit = 0;
	for(int i=0;i<prices.size();i++){
		if(prices[i] < min){
			min = prices[i];
		}
		else{
			int profit = prices[i] - min;
			maxProfit = max(maxProfit,profit);
		}
	}
	return maxProfit;
}

int maxProfitFast(vector<int> prices){
	int maxPro = 0, minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(prices[i] - minPrice, maxPro);
        }
    return maxPro;
}

int main(){
	int n;
	cin>>n;
	vector<int> prices;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		prices.push_back(data);
	}
	cout<<maxProfitFast(prices);
	return 0;
}
