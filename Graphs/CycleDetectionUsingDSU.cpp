#include<bits/stdc++.h>
using namespace std;

class dsu{
	vector<int> parent;
public:
	dsu(int n){
		parent.resize(n);
		for(int i=0;i<n;i++){
			parent[i] = i;
		}
	}
	int get_superparent(int n){
		if(n == parent[n]){
			return n;
		}
		else{
			return parent[n] = get_superparent(parent[n]);
		}
	}
	void unite(int x,int y){
		int superparent_x = get_superparent(x);
		int superparent_y = get_superparent(y);
		if(superparent_x != superparent_y){
			parent[superparent_x] = superparent_y;
		}
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	dsu g(n);
	bool cycle = 0;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		if(g.get_superparent(x) != g.get_superparent(y)){
			// different component
			g.unite(x,y);
		}
		else{
			//means there was a path from x to y
			cycle = 1;
		}
	}
	if(cycle == 1){
		cout<<"Cycle in the graph";
	}
	else{
		cout<<"No cycle in the graph";
	}
}
