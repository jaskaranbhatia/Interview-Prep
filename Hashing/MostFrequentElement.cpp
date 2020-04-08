#include<bits/stdc++.h>
using namespace std;

int mostFrequent(int arr[],int n){
	unordered_map<int,int> hash;
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	int max_count = 0,res = -1;
	for(auto i:hash){
		if(max_count < i.second){
			res = i.first;
			max_count = i.second;
		}
	}
	return res;
}

int main()
{
	int arr[] = {1,5,2,1,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<mostFrequent(arr,n);
	return 0;
}
