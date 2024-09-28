#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> p;
const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int N, int src, const vector<vector<p>> &adj)
{
	priority_queue<p, vector<p>, greater<p>> pq;
	vector<int> dist(N + 1, INF);

	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty())
	{
		int s = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (d > dist[s])
			continue;

		for (auto &edge : adj[s])
		{
			int v = edge.first;
			int weight = edge.second;

			if (dist[s] + weight < dist[v])
			{
				dist[v] = dist[s] + weight;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D){
	vector<vector<p>> adj(N + 1);

	for (int i = 0; i < M; i++)
	{
		adj[X[i]].push_back({Y[i], P[i]});
	}

	D = dijkstra(N, 0, adj);
	for (auto &d : D)
	{
		if (d == INF)
			d = -1;
	}
	D.pop_back();
}