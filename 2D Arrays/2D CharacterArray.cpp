#include<iostream>
using namespace std;

int main(){
	char a[][10] ={{'a','b','\0'},{'d','e','f','\0'}};
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	
	char b[][10] = {"abc","def","ghi","jkl"};
	cout<<b[0]<<endl;
	cout<<b[1]<<endl;
	cout<<b[2]<<endl;
	cout<<b[3]<<endl;
	
	//Read a list of strings
	char c[100][100];
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++){
		cin.getline(a[i],1000);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
