#include<iostream>
using namespace std;

// * is used for multiplication, creating pointer and dereferencing
// In dereferencing, we derefer a pointer
// & of a variable -> address
// * of a addrress -> variable
int main(){
	int x = 10;
	int *ptr;
	ptr = &x;
	cout<<*ptr<<endl; //variable
	cout<<*&x<<endl; //variable
	cout<<*ptr + 1<<endl; //variable + 1
	cout<<ptr<<endl;
	cout<<ptr+1<<endl; //next address
	//Double pointer - Pointer to a Pointer
	int **xptr = &ptr;
	cout<<xptr;
}
