#include<bits/stdc++.h>
using namespace std;

int nthFibo(int n){
	int x=0, y=1;
	int z;
	for(int i=2;i<=n;i++){
		z = x + y;
		x = y;
		y = z;
	}
	return z;
}

int main(){
	int n;
	cin>>n;
	cout<<nthFibo(n)<<endl;
	return 0;
}

