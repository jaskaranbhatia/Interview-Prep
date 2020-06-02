#include<bits/stdc++.h>
using namespace std;

/*
There are N cities from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city.
You are given information in the form of M pairs(X,Y) i.e there is an undirected road between city X and city Y
Find out no. of ways in which city can be choosen
*/


class dsu{
public:
	vector<int> par,sz;
	int totalComp;
	void init(int n){
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++){
			par[i] = i;
			sz[i] = 1;
		}
		totalComp = n;
	}
	int get_superparent(int x){
		if(x == par[x]){
			return x;
		}
		else{
			return par[x] = get_superparent(par[x]);
		}
	}
	void unite(int x,int y){
		int superparent_x = get_superparent(x);
		int superparent_y = get_superparent(y);
		if(superparent_x != superparent_y){
			par[superparent_x] = superparent_y;
			sz[superparent_y] += sz[superparent_x];
			sz[superparent_x] = 0;
			totalComp--;
		}
	}
};

int main(){
	dsu g;
	int n,m,ans = 0;
	cin>>n>>m;
	g.init(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g.unite(x,y);
	}
	for(int i=0;i<n;i++){
		int super_parent_i = g.get_superparent(i);
		ans += (n - g.sz[super_parent_i]);
	}
	cout<<ans/2<<endl;
}
