#include<bits/stdc++.h>
using namespace std;

int fastPower(int a,int b){
    if(b==0){
        return 1;
    }
    int smallAns = fastPower(a,b/2);
    smallAns *= smallAns;
    //b&1 means checking for odd number
    if(b&1){
        return a*smallAns;
    }
    return smallAns;
}

int main(){
    cout<<fastPower(5,3);
}
