#include<bits/stdc++.h>
using namespace std;

void printPairs(int arr[],int n,int sum){
	unordered_set<int> s;
	for(int i=0;i<n;i++){
		int temp = sum - arr[i];
		if(s.find(temp) != s.end()){
			cout<<"Pair with given sum is : "<<temp<<" & "<<arr[i]<<endl;
		}
		s.insert(arr[i]);
	}
}

int main(){
	int A[] = {1,4,45,6,10,8};
	int sum = 16;
	int n = sizeof(A)/sizeof(A[0]);
	printPairs(A,n,sum);
	return 0;
}


