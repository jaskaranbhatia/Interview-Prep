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

void wavePrint(int **arr,int n,int m){
	for(int col=0;col<m;col++){
		if(col % 2 == 0){
			//Top-Down Traversal
			for(int row=0;row<n;row++){
				cout<<arr[row][col]<<" ";
			}
		}
		else{
			//Bottom-Up Traversal
	
			for(int row=n-1;row>=0;row--){
				cout<<arr[row][col]<<" ";
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
	wavePrint(arr,n,m);
	return 0;
}
