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

	vector<int> dijkstra(int exit, vector<int> policepath)
	{
		priority_queue<p, vector<p>, greater<p>> q;
		vector<int> distance(N, INT_MAX);

		q.push(make_pair(0, 0));
		distance[0] = 0;
		while (!q.empty())
		{
			int s = q.top().second; q.pop();
			for (auto node : adj[s])
			{
				int v = (node).first;
				int weight = (node).second;

				int ipolice = (distance[v] % policepath.size());
				bool occupied = (v == policepath[ipolice]);

				if (occupied)
					weight++;

				if (distance[v] > distance[s] + weight)
				{
					distance[v] = distance[s] + weight;
					q.push(make_pair(distance[v], v));
				}
			}
		}
		return distance;
	}
};

int main()
{
	int N, M, L;
	cin >> N >> M >> L;

	vector<int> A(M), B(M);
	for (int i = 0; i < M; ++i) cin >> A[i] >> B[i];

	vector<int> C(L);
	for (auto &x : C) cin >> x;

	WeightedGraph g = WeightedGraph(N);
	for(int i = 0; i < M; i++)
	{
		g.addEdge(A[i], B[i], 1);
	}
	auto m = g.dijkstra(N-1, C);
	
	cout << m[N-1] << endl;
	return 0;
}