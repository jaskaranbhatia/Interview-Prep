#include<iostream>
using namespace std;

int fib(int n){
	int f[n+2];
	f[0] = 0;
	f[1] = 1;
	for(int i=2;i<=n;i++){
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

//Space Optimized Method
int fib2(int n)
{
	int a=0, b=1,c;
	if(n == 0) return a;
	for(int i=2;i<=n;i++){
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main(){
	int n=9;
	cout<<fib2(5);
	return 0;
}
