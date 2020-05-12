#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int> &v){
	v.erase(unique(v.begin(),v.end()),v.end());
}

int main(){
	vector<int> v = {1,2,2,3,3,4,4,4,5,5,5,6,7,8,9,9,10};
	removeDuplicates(v);
	for(auto it=v.begin();it != v.end();it++){
		cout<<*it<<" ";
	}
}
