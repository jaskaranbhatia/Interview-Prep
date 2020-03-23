#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	cin>>n;
	cin.get();
	char a[1000];
	char largest[1000];
	int len = 0;
	int largest_len = 0;
	for(int i=0;i<n;i++){
		cin.getline(a,1000);
		len = strlen(a);
		if(len>largest_len){
			largest_len = len;
			strcpy(largest,a);
		}
	}
	cout<<largest<<" and Length : "<<largest_len;
	return 0;
}
