#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
const ll INF = numeric_limits<ll>::max();

vector<ll> dijkstra(ll N, ll src, const vector<vector<p>> &adj)
{
	priority_queue<p, vector<p>, greater<p>> pq;
	vector<ll> dist(N + 1, INF);

	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty())
	{
		ll s = pq.top().second;
		ll d = pq.top().first;
		pq.pop();

		if (d > dist[s])
			continue;

		for (auto &edge : adj[s])
		{
			ll v = edge.first;
			ll weight = edge.second;

			if (dist[s] + weight < dist[v])
			{
				dist[v] = dist[s] + weight;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

ll main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ll N, M;
	cin >> N >> M;
	ll s, d;
	cin >> s >> d;

	vector<vector<p>> adj(N + 1);

	for (ll i = 0; i < M; i++)
	{
		ll u, v, weight;
		cin >> u >> v >> weight;
		adj[u].push_back({v, weight});
	}

	vector<ll> dist = dijkstra(N, s, adj);
	cout << dist[d] << endl;

	return 0;
}