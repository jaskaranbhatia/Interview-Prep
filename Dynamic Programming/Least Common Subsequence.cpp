#include<bits/stdc++.h>
using namespace std;

//Recursive
int lcs(string a,string b,int i,int j){
	if(a[i]=='\0' || b[j] == '\0'){
		return 0;	
	} 
	else if(a[i] == b[j]){
		return 1 + lcs(a,b,i+1,j+1);
	}
	else{
		return max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
	}
}

//Using Memoization
int lcs2(string X,string Y,int m,int n){
	int L[m + 1][n + 1]; 
	int i, j;  
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];  
}
  

int main(){
	string a = "AGGTAB";
	string b = "GXTXAYB";
	int m = a.length();
	int n = b.length();
	cout<<lcs2(a,b,m,n);
	return 0;	
}
