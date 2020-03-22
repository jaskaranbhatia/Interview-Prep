#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//Use use Two Pointer Approach To Solve this Problem
	int s = 16;
	int i = 0;
	int j = n-1;
	while(i<j){
		int csum = a[i] + a[j];
		if(csum > s){
			j--;
		}
		else if(csum < s){
			i++;
		}
		else{
			cout<<a[i] <<" & "<<a[j]<<endl;
			i++;
			j--;
		}
	}
	
	return 0;
}
