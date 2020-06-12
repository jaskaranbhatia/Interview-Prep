#include<bits/stdc++.h>
using namespace std;

int coinMax(int arr[],int l,int r){
	if(l+1 == r){
		return max(arr[l],arr[r]);
	}
	int choice1 = arr[l] + min(coinMax(arr,l+2,r),coinMax(arr,l+1,r-1));
	int choice2 = arr[r] + min(coinMax(arr,l,r-2),coinMax(arr,l+1,r-1));
	return max(choice1,choice2);
}

int main(){
	int arr[] = {1,5,700,2};
	cout<<coinMax(arr,0,3);
}
