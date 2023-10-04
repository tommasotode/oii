#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;

	Graph(int n)
	{
		adj.resize(n);
	}

	void addVertex(int v)
	{
		adj[v] = vector<int>();
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	void BFS(int x)
	{
		queue<int> queue;
		bool visited[N];
		int distance[N];

		visited[x] = true;
		distance[x] = 0;
		queue.push(x);
		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
			for (auto v : adj[s])
			{
				if (visited[v])
					continue;

				visited[v] = true;
				distance[v] = distance[s] + 1;
				queue.push(v);
			}
		}
	}

};

