#include<bits/stdc++.h>
using namespace std;

int totalPaths(int m,int n){
    if(m == 1 || n == 1){
        return 1;
    }
    int ans = totalPaths(--m,n) + totalPaths(m,--n);
    return ans;
}

int main(){
    int m = 4, n = 4;
    cout<<totalPaths(m,n);
}
