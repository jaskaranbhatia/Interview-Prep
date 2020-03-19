#include<bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[],int n,int x){
	int l = 0, r = n-1;
	while( l<=r && x >= arr[l] && x <= arr[r]){
		if(l == r){
			if(arr[l] == x) return l;
			return -1;
		}
		int pos = l + (((double)(r - l) / (arr[r] - arr[l])) * (x - arr[l]));
		if(arr[pos] == x){
			return pos;
		} 
		else if(arr[pos] < x){
			l = pos + 1;
		}
		else{
			r = pos - 1;
		}
	}
	return -1;
}

int main(){
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 33; 
    int index = interpolationSearch(arr, n, x); 
    if (index != -1) 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
    return 0; 	
}
