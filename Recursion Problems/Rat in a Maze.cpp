#include<iostream>
using namespace std;

/*
Custom Input
--------------->
3
1 0 1
1 1 1
1 1 1
*/


void printSolution(int **sol,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void mazeHelp(int maze[][20],int n,int **sol,int x,int y){
    if(x == n-1 && y == n-1){
        sol[x][y] = 1;
        printSolution(sol,n);
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y] == 0 || sol[x][y] == 1){
        return;
    }
    sol[x][y] = 1;
    mazeHelp(maze,n,sol,x-1,y);
    mazeHelp(maze,n,sol,x+1,y);
    mazeHelp(maze,n,sol,x,y-1);
    mazeHelp(maze,n,sol,x,y+1);
    sol[x][y] = 0;
}



void ratInAMaze(int maze[][20], int n){
    int **sol = new int*[n];
    for(int i=0;i<n;i++){
        sol[i] = new int[n];
    }
    mazeHelp(maze,n,sol,0,0);
}


int main(){
  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


