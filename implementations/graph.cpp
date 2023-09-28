#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	vector<vector<int>> adj;

public:

	Graph(int v)
	{
		adj.resize(v);
	}

	void addVertex(int n)
	{
		adj[n] = vector<int>();
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
};