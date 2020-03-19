#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int lookup[MAX][MAX];

string LCS(string X,string Y,int m,int n){
	if( m==0 || n==0 ){
		return string("");
	}
	if(X[m-1] == Y[n-1]){
		return LCS(X,Y,m-1,n-1) + X[m-1];
	}
	
}
