#include<bits/stdc++.h>
using namespace std;

class Graph{
	unordered_map<int,list<pair<int,int>>> l;
public:
	void addEdge(int x,int y,int dist,bool bdir=true){
		l[x].push_back(make_pair(y,dist));
		if(bdir){
			l[y].push_back(make_pair(x,dist));
		}
	}
	void dijsktraAlgo(int src){
		unordered_map<int,int> dist;
		for(auto node_pair:l){
			int node = node_pair.first;
			dist[node] = INT_MAX;
		}
		// Make a set to find node with miniumum distance
		set<pair<int,int>> s;
		// 1st parameter distance, 2nd parameter is vertex
		dist[src] = 0;
		s.insert(make_pair(0,src));
		while(!s.empty()){
			// Find pair at the front
			auto p = *(s.begin());
			int node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());
			//Iterate over neighbours
			for(auto nbr:l[node]){
				if(nodeDist + nbr.second < dist[nbr.first]){
					// In set updation is not possible so we need to erase old pair and insert new
					int dest = nbr.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
					}
					dist[dest] = nodeDist + nbr.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		for(auto d:dist){
			cout<<d.first<<" "<<d.second<<endl;
		}
	}
};

int main(){
	Graph g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,2,1);
	g.addEdge(1,4,7);
	g.dijsktraAlgo(1);
}
