#include <fstream>
#include <iostream>
#include <vector>
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
 
int main()
{
	int N, M;
	cin >> N >> M;
	int e, s;
	cin >> e >> s;

	vector<int> A(M), B(M), C(M);
	for (int i = 0; i < M; ++i) cin >> A[i] >> B[i] >> C[i];

	WeightedGraph g = WeightedGraph(N);
	for(int i = 0; i < M; i++)
	{
		g.adj[A[i]-1].push_back(make_pair(B[i]-1, C[i]));
		g.adj[B[i]-1].push_back(make_pair(A[i]-1, C[i]));
	}
	auto m = g.dijkstra(0);
	
	cout << m[e] << endl;

	return 0;
}