#include<bits/stdc++.h>
using namespace std;

int rPower(int n,int p){
    if(p==1){
        return n;
    }
    return n*rPower(n,p-1);
}

int main(){
    cout<<rPower(4,2);
}
