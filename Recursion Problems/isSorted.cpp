#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n){
    if(n == 1){
        return true;
    }
    else if(arr[0] < arr[1] && isSorted(arr+1,n-1)){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSorted(arr,n)){
        cout<<"Is Sorted";
    }
    else{
        cout<<"Not Sorted";
    }
}
