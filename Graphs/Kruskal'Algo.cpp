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
	int get(int n){
		if(n == parent[n]){
			return n;
		}
		else{
			return parent[n] = get(parent[n]);
		}
	}
	void merge(int x,int y){
		int sp_x = get(x);
		int sp_y = get(y);
		if(sp_x != sp_y){
			parent[sp_x] = sp_y;
		}
	}
};

int main(){
	int n,m, ans = 0;
	cin>>n>>m;
	dsu g(n);
	vector<vector<int>> edges(m);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;
		edges[i] = {w,x,y};
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<m;i++){
		int x = edges[i][1];
		int y = edges[i][2];
		int w = edges[i][0];
		if(g.get(x) != g.get(y)){
			// can take this edge
			g.merge(x,y);
			ans += w;
		}
	}
	cout<<ans<<endl;
}
