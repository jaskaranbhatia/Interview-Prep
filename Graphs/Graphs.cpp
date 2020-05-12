#include<bits/stdc++.h>
using namespace std;

// Graph is a network like Data Structure with edges and vertices
// Edges are used to connect two vertices
// Graphs Applications
/*
1. Shorted Path in Google Maps is found using Graphs
2. Social Networking Apps also build graphs of users to generate news feed and find mutual friends
3. Graphs are used in circuit design in electronics
4. Routing Algorithms are also based on graphs. Used to optimize flow of packets
5. Delivery Route of Vans
6. Resolving Dependencies
7. Neural Networks use Graphs
8. Web Document is a DOM Tree which is a type of graph
9. Used in Image Processing
10. Paint Bucket Tools
*/

class Graph{
	int V;
 	list<int> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdjList(){
		//Iterate over all vertices
		for(int i=0;i<V;i++){
			cout<<i<<" -> ";
			for(auto nbr:l[i]){
				cout<<nbr<<" ";
			}
			cout<<endl;
		}
	}
};

// Adjacency List Implementation: Using array of Lists
int main(){
	Graph g1(4);
	g1.addEdge(0,1);
	g1.addEdge(0,2);
	g1.addEdge(2,3);
	g1.addEdge(1,2);
	g1.printAdjList();
	return 0;
}
