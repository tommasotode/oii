#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int salta(int N, vector<int> S, vector<int> A, vector<int> B);



#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

class WeightedDirectedGraph
{
public:

	int N;
	vector<vector<p>> adj;

	WeightedDirectedGraph(int n)
	{
		adj = vector<vector<p>>(n);
		N = n;
	}

	void addEdge(int u, int v, int weight)
	{
		adj[u].push_back(make_pair(v, weight));
	}

	vector<int> dijkstra(int src)
	{
		priority_queue<p, vector<p>, greater<p>> q;
		vector<int> dist(N, INT_MAX);
		int max_height = 0;


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
	WeightedDirectedGraph g = WeightedDirectedGraph(N);
	
	for (int i = 0; i < N; i++)
	{
		int h = S[i];
		int mi = A[i];
		int ma = B[i];

		for (int j = mi; j <= ma; j++)
		{
			g.addEdge(i, i+j, S[i]);
		}
	}
	return 42;
}



int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// Uncomment the following lines if you want to read or write from files
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;

	vector<int> S(N), A(N), B(N);
	for (int i = 0; i < N; i++)
	{
		cin >> S[i] >> A[i] >> B[i];
	}

	cout << salta(N, S, A, B) << endl;

	return 0;
}
