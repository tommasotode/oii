#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;

	Graph(int n)
	{
		N = n;
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


typedef pair<int, int> p;
class WeightedGraph
{
	int N;
	vector<vector<p>> adj;

public:
	WeightedGraph(int n)
	{
		N = n;
		adj.resize(n);
	}

	void addEdge(int u, int v, int weight)
	{
		adj[u].push_back(make_pair(v, weight));
		adj[v].push_back(make_pair(u, weight));
	}

	vector<int> dijkstra(int src)
	{
		priority_queue<p, vector<p>, greater<p>> q;
		vector<int> dist(N, INT_MAX);

		q.push(make_pair(0, src));
		dist[src] = 0;
		while (!q.empty())
		{
			int s = q.top().second; q.pop();
			for (auto node : adj[s])
			{
				int v = (node).first;
				int weight = (node).second;

				if (dist[v] > dist[s] + weight)
				{
					dist[v] = dist[s] + weight;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		return dist;
	}
};