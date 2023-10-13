#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

class WeightedGraph
{
public:

	int N;
	vector<vector<p>> adj;

	WeightedGraph(int n)
	{
		adj = vector<vector<p>>(n);
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
 

int salta(int N, vector<int> S, vector<int> A, vector<int> B)
{
	WeightedGraph g = WeightedGraph(N);
	
	for (int i = 0; i < N; i++)
	{
		int h = S[i];
		int mi = A[i];
		int ma = B[i];

		for (int j = mi; j <= ma; j++)
		{
			g.addEdge(i, i+j, S[i+j]);
		}
	}
	return 42;
}