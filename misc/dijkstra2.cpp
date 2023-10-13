#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

class Graph
{
private:
	int V;
	vector<vector<pair<int, int>>> adj;

public:
	Graph(int vertices)
	{
		V = vertices;
		adj.resize(V);
	}

	void addEdge(int u, int v, int weight)
	{
		adj[u].push_back(make_pair(v, weight));
	}

	void dijkstra(int source)
	{
		vector<int> dist(V, INT_MAX);
		vector<bool> visited(V, false);
		dist[source] = 0;

		priority_queue<p, vector<p>, greater<p>> q;

		q.push(make_pair(0, source));

		while (!q.empty())
		{
			int u = q.top().second; q.pop();
			if (visited[u]) continue;
			visited[u] = true;

			for (const p& neighbor : adj[u])
			{
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
					q.push(make_pair(dist[v], v));
				}
			}
		}

		// Print the shortest distances from the source vertex
		cout << "Shortest distances from source vertex " << source << ":\n";
		for (int i = 0; i < V; ++i) {
			cout << "Vertex " << i << ": " << dist[i] << endl;
		}
	}
};