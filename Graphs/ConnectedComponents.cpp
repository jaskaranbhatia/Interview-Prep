#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<T>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs_helper(T src,map<T,bool> &visited){
		cout<<src<<" ";
		visited[src] = true;
		//go to any neighbour not visited
		for(auto nbr:l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited);
			}
		}
	}
	void dfs(){
		map<T,bool> visited;
		for(auto p:l){
			T node = p.first;
			visited[node] = false;
		}
		// call helper fnc
		//Iterate over all the vertices
		int cnt = 0;
		for(auto p:l){
			T node = p.first;
			if(!visited[node]){
				cout<<"Component "<<cnt<<"-->";
				dfs_helper(node,visited);	
				cnt++;
				cout<<endl;
			}
		}
	}
};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(8,8);
	g.dfs();
}
