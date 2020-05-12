#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(string &s){
	s.erase(unique(s.begin(),s.end()),s.end());
}

int main(){
	string str ="hheelloo";
	removeDuplicates(str);
	cout<<str;
}
