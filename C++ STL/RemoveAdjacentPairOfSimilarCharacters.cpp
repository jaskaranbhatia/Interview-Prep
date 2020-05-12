#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
	string ans = "";
	for(auto it:s){
		if(ans.empty() || ans.back() != it){
			ans.push_back(it);
		}
		else if(ans.back() == it){
			ans.pop_back();
		}
	}
	return ans;
}

int main(){
	string str = "keexxllx";
	cout<<removeDuplicates(str);
}
