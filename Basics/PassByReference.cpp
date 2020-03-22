#include<iostream>
using namespace std;

//Pass by value
void increment(int a){
	a = a + 1;
	cout<<"Inside Function : "<<a<<endl;
}

//Pass by Reference using pointers
void increment_ref(int *a){
	*a = *a + 1;
	cout<<"Inside Function : "<<*a<<endl;
}



int main(){
	int a = 10;
	increment_ref(&a);
	cout<<"Inside Main : "<<a;
	return 0;
}
