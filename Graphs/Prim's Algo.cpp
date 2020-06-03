#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> gr[n+1];
	int vis[n+1] = {0};
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		gr[x].push_back({y,w});
		gr[y].push_back({x,w});
	}		
	// Min Heap
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.push({0,1});
	// We are pushing {weight,node}
	int mst = 0;
	while(!Q.empty()){
		pair<int,int> best = Q.top();
		Q.pop();
		int weight = best.first;
		int to = best.second;
		// Not an active edge, if edge is not active we have to do nothing with it.
		if(vis[to]) continue;
		mst += weight;
		vis[to] = 1;
		for(auto x:gr[to]){
			if(!vis[x.first]){
				Q.push({x.second,x.first});
			}
		}
	}
	cout<<mst<<endl;
}
