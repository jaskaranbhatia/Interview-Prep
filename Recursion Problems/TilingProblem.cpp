#include<bits/stdc++.h>
using namespace std;

int totalWays(int n){
    if(n<1) return 0;
    if(n<4) return 1;
    if(n==4) return 2;
    return totalWays(n-1) + totalWays(n-4);
}

int main(){
    int n = 5;
    cout<<totalWays(5);
    return 0;
}
