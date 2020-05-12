#include<iostream>
using namespace std;

void permute(string s,int l,int r){
	if(l == r){
		cout<<s<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			//New string by swapping
			swap(s[l],s[i]);
			//Permute over string
			permute(s,l+1,r);
			//Backtrack to original
			swap(s[l],s[i]);
		}
	}
}

int main(){
	string s;
	cin>>s;
	int n = s.length();
	permute(s,0,n-1);
}
