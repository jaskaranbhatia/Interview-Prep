#include<iostream>
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

void subMatrixSum(int **arr,int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int top_left = (i+1)*(j+1);
			int bottom_right = (n-i)*(n-j);
			sum += (top_left * bottom_right * arr[i][j]);
		}
	}
	cout<<sum;
}


int main(){
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<m;i++){
		arr[i] = new int[m];
	}	
	input_2dArray(arr,n,m);
	subMatrixSum(arr,n);
	return 0;
}
