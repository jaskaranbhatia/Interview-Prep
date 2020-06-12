#include<bits/stdc++.h>
using namespace std;

set<string> present;

void permute(string s,int l,int r){
	if(l == r){
		if(present.count(s) != 0){
			return;
		}
		present.insert(s);
		cout<<s<<endl;
		return;
	}
	for(int i=l;i<=r;i++){
		swap(s[l],s[i]);
		permute(s,l+1,r);
		swap(s[l],s[i]);
	}
}

int main(){
	string s;
	cin>>s;
	int l = 0;
	int r = s.length()-1;
	permute(s,l,r);
	return 0;
}
