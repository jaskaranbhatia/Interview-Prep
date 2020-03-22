#include<iostream>
using namespace std;

int main(){
	//Pointer is a variable which stores address of another variable
	//Declaration And initialization
	int y = 20;
	int *ptr = &y;
	//Declaration and assignment
	float a = 10.5;
	float *aptr; //Declaration
	aptr = &a; //Assignment
	//if we don't initialize a pointer it has a garbage value
	//A pointer takes space of 4/8 bytes
	cout<<ptr<<" "<<aptr;
}
