#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

class WeightedGraph
{
	int N;
	vector<vector<p>> adj;

public:
	WeightedGraph(int n)
	{
		adj.resize(n);
		N = n;
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

int main()
{
	int V = 9;
	WeightedGraph g(V);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.dijkstra(0);

	return 0;
}