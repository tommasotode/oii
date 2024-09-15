#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef long long ll;
const ll INF = numeric_limits<ll>::max();

vector<ll> dijkstra(int N, int source, const vector<vector<pair<int, int>>> &adj)
{
	vector<ll> dist(N + 1, INF);
	dist[source] = 0;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, source});

	while (!pq.empty())
	{
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();

		if (d > dist[u])
			continue;

		for (auto &edge : adj[u])
		{
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int N, M;
	cin >> N >> M;
	int s, d;
	cin >> s >> d;

	vector<vector<pair<int, int>>> adj(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		adj[u].push_back({v, weight});
	}

	vector<ll> dist = dijkstra(N, s, adj);
	cout << dist[d] << endl;

	return 0;
}