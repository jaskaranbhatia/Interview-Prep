#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char a[]){
	int i = 0;
	int j = strlen(a) - 1;
	while(i<j){
		if(a[i]==a[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	char str[] = "tututu";
	if(isPalindrome(str)){
		cout<<"Yes, it is Palindrome";
	}
	else{
		cout<<"No, it is not a Palindrome";
	}
}


