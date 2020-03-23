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

void spiralPrint(int **a,int n,int m){
	int startRow = 0;
	int startCol = 0;
	int endRow = n-1;
	int endCol = m-1;
	while(startRow <= endRow && startCol <= endCol){
		for(int i=startCol;i<=endCol;i++){
			cout<<a[startRow][i]<<" ";
		}
		startRow++;
		for(int i=startRow;i<=endRow;i++){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;
		if(endRow > startRow) {
			for(int i=endCol;i>=startCol;i--){
				cout<<a[endRow][i]<<" ";
			}
			endRow--;	
		}
		if(endCol>startCol){
			for(int i=endRow;i>=startRow;i--){
				cout<<a[i][startCol]<<" ";
			}
			startCol++;	
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
	spiralPrint(arr,n,m);
	return 0;
}
