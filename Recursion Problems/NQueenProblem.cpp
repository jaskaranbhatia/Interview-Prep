#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int column){
    // Checking Column
    for(int i=row-1;i>=0;i--){
        if(board[i][column] == 1){
            return false;
        }
    }
    // Checking Upper Left Diagonal
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // Upper Right Diagonal
    for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

void nQueenHelper(int n,int row){
    if(row == n){
        // We have reached a solution
        // Print Board Matrix
        // Return
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    // Place at all possible positions and move to smaller problems
    for(int j=0;j<n;j++){ // j is the column
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            nQueenHelper(n,row+1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n){
	for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            board[i][j] = 0;
        }
    }
    nQueenHelper(n,0);
}

int main(){
	placeNQueens(4);
}
