#include<bits/stdc++.h>
using namespace std;

//char *strtok(char *s,char *delimiters)
//returns a token on each subsequent call
//on the first call function should be passed with string argument 's'
//on subsequent call we should pass string argument as null

int main(){
	char s[100] = "Today is a rainy day";	
	char *ptr = strtok(s," ");
	cout<<ptr<<endl;
	while(ptr != NULL){
		ptr = strtok(NULL," ");
		cout<<ptr<<endl;
	}
	return 0;
}
