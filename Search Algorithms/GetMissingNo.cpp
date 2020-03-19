#include<bits/stdc++.h>
using namespace std;

int getMissingNo(int arr[],int n){
	int total = ((n+1)*(n+2))/2;
	for(int i=0;i<n;i++){
		total -= arr[i];
	}
	return total;
}

int getMissingNo2(int a[], int n) 
{  
    int x1 = a[0]; 
    int x2 = 1; 
    for (int i = 1; i < n; i++) 
        x1 = x1 ^ a[i]; 
    for (int i = 2; i <= n + 1; i++) 
        x2 = x2 ^ i; 
    return (x1 ^ x2); 
} 

int main() {
	int arr[] = { 1, 2, 4, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int miss = getMissingNo2(arr, n); 
    cout << miss;
	return 0;	
}
