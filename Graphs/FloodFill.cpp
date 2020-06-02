#include<bits/stdc++.h>
using namespace std;

int R,C;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void floodFill(char mat[][50],int i,int j,char ch,char color){
	//Base Case
	if(i<0 || j<0 || i>=R || j>=C){
		return;
	}
	//Boundary Condition
	if(mat[i][j] != ch){
		return;
		
	}
	//Recursice Call
	mat[i][j] = color;
	for(int k=0;k<4;k++){
		floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}
}

void printMat(char mat[][50]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cin>>R>>C;
	char input[15][50];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}
	printMat(input);
	floodFill(input,2,4,'.','r');
	printMat(input);
}
