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
		adj = vector<vector<p>>(n+1);
		N = n;
	}

	void addEdge(int u, int v, int weight)
	{
		adj[u].push_back(make_pair(v, weight));
	}

	vector<int> dijkstra(int src)
	{
		priority_queue<p, vector<p>, greater<p>> q;
		vector<int> maxh(N+1, INT_MAX);
		vector<int> prev(N+1);


		q.push(make_pair(0, src));
		maxh[src] = 0;
		while (!q.empty())
		{
			int s = q.top().second; q.pop();
			for (auto node : adj[s])
			{
				int v = (node).first;
				int weight = (node).second;

				if (maxh[v] > weight)
				{
					maxh[v] = weight;
					q.push(make_pair(maxh[v], v));
					prev[v] = s;
				}
			}
		}
		return prev;
	}
};
 
int shortest(vector<int> prev, int target)
{
	vector<int> path;
	int tmp = target;
	path.push_back(tmp);
	while (tmp != 0)
	{
		tmp = prev[tmp];
		path.push_back(tmp);
	}

	return *max_element(path.begin(), path.end());
}


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

	auto x = g.dijkstra(0);
	return shortest(x, N);
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
