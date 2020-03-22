#include<iostream>
using namespace std;

int main(){
	int x = 10;
	cout<< &x <<endl;
	int y = 10.5;
	cout<< &y <<endl;
	
	//It doesn't work for character variable which is due to operator overloading
	char ch = 'A';
	cout<< &ch;
	//To make it work, we type cast it to void pointer
	//Earlier it was char*
	cout<<(void*)&ch<<endl;
	return 0;
}
