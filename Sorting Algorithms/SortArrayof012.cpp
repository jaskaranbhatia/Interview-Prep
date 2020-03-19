#include<bits/stdc++.h>
using namespace std;

void sort012(int a[],int n){
	int l = 0;
	int r = n-1;
	int mid = 0;
	while(mid <= r){
		switch(a[mid]){
			case 0:
				swap(a[l++],a[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(a[mid],a[r--]);
				break;
		}
	}
}

int main() {
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sort012(arr, n); 
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}
	return 0;
}
