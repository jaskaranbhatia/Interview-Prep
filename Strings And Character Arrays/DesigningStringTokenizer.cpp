#include<bits/stdc++.h>
using namespace std;

char* mystrtok(char *str,char delim){
	static char *input = NULL;
	if(str != NULL){
		input = str;
	}
	//after final token is obtained
	if(input == NULL){
		return NULL;
	}
	//start extracting tokens
	char *output = new char[strlen(input)+1];
	int i;
	for(i=0;input[i]!='\0';i++){
		if(input[i]!=delim){
			output[i] = input[i];
		}
		else{
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}
	//corner case
	output[i] = '\0';
	input = NULL;
	return output;
}

int main(){
	char s[100] = "Today, is a rainy day";
	char *ptr = mystrtok(s,' ');
	cout<<ptr<<endl;
	while(ptr != NULL){
		ptr = mystrtok(NULL,' ');
		cout<<ptr<<endl;
	}
	return 0;
}
