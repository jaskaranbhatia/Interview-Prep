#include<bits/stdc++.h>
using namespace std;

void input_2dArray(int **arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
}

void output_2dArray(int **arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp; 
}

void rotate(int **arr,int n){
	for(int i=0;i<n;i++){
		int start_col = 0;
		int end_col = n-1;
		while(start_col<end_col){
			swap(arr[i][start_col],arr[i][end_col]);
			start_col++;
			end_col--;
		}
	}
	//To take transpose
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap(arr[i][j],arr[j][i]);	
			}
		}
	}
}  

void rotate_stl(int **arr,int n){
	for(int i=0;i<n;i++){
		reverse(arr[i],arr[i] + n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap(arr[i][j],arr[j][i]);	
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<m;i++){
		arr[i] = new int[m];
	}	
	input_2dArray(arr,n,m);
	rotate_stl(arr,n);
	output_2dArray(arr,n,m);
	return 0;
}
