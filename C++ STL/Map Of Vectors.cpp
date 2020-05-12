#include<bits/stdc++.h>
using namespace std;

map<vector<int>,int> vis;

void checkvisited(vector<int> data){
	if(vis.find(data) != vis.end()){
		cout<<"True"<<endl;
	}
	else{
		cout<<"False"<<endl;
	}
}

int main(){
	vector<int> data_1 = {10,20,30,40};
	vector<int> data_2 = {5,10,15};
	vis[data_1] = 1;
	vis[data_2] = 1;
	vector<int> check_2 = {5,10,15};
	checkvisited(check_2);
	return 0;
}
