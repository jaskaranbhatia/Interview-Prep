#include<iostream>
#define MAX 1000
using namespace std;

int hash[MAX+1][2];

void insert(int a[],int n){
	for(int i=0;i<n;i++){
		if(a[i] >=0 ){
			::hash[a[i]][0] = 1;
		}
		else{
			::hash[abs(a[i])][1] = 1;
		}
	}
}

bool search(int X){
	if(X >= 0){
		if(::hash[X][0] == 1){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		X = abs(X);
		if(::hash[X][1] == 1){
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	int arr[] = {-4,-3,-2,-1,0,1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	insert(arr,n);
	if(search(5)){
		cout<<"Present";
	}
	else{
		cout<<"Not Present";
	}
}


