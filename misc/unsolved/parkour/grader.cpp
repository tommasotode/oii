#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int salta(int N, vector<int> S, vector<int> A, vector<int> B);

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
		vector<int> maxh(N, INT_MAX);
		vector<int> prev(N);

		maxh[0] = adj[0][0].second;
		q.push(make_pair(src, maxh[0]));
		while (!q.empty())
		{
			int s = q.top().first; q.pop();
			for (auto node : adj[s])
			{
				int v = (node).first;
				int weight = (node).second;

				if (maxh[v] > weight)
				{
					maxh[v] = weight;
					q.push(make_pair(v, maxh[v]));
					prev[v] = s;
				}
			}
		}
		return prev;
	}

	int shortest(vector<int> &prev, int target, vector<int> &S)
	{
	vector<int> path;
	int tmp = target;
	path.push_back(tmp);
	while (tmp != 0)
	{
		tmp = prev[tmp];
		path.push_back(tmp);
	}

	int m = 0;
	for (auto i : path)
	{
		if (S[i] > m)
		{
			m = S[i];
		}
	}
	return m;
	}
};
 

int salta(int N, vector<int> S, vector<int> A, vector<int> B)
{
	WeightedDirectedGraph g = WeightedDirectedGraph(N+1);
	
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

	auto x = g.dijkstra(0);
	return g.shortest(x, N, S);
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
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
