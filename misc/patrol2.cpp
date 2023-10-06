#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
	int N = 0;
	vector<vector<int>> adj;

	Graph(int n)
	{
		adj.resize(n);
		N = n;
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}	

	int BFS(int end, vector<int> C)
	{
		queue<int> queue;
		bool visited[N];
		int distance[N];
		int min_path = INT_MAX;

		for (int i = 0; i < N; i++)
		{
			visited[i] = false;
			distance[i] = INT_MAX;
		}

		visited[0] = true;
		distance[0] = 0;
		queue.push(0);
		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
			for (auto v : adj[s])
			{
				if (visited[v]) continue;

				distance[v] = distance[s] + 1;
				int indiceguardia = (distance[v] % C.size());
				bool celaguardia = (v == C[indiceguardia]);

				if (celaguardia)
				{
					distance[v]++;
				}
				
				queue.push(v);

				if (v == end)
				{
					min_path = min(min_path, distance[v]);
				}
				else
				{
					visited[v] = true;
				}
			}
		}
		return min_path;
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

	Graph g = Graph(N);
	for(int i = 0; i < M; i++)
	{
		g.addEdge(A[i], B[i]);
	}
	int m = g.BFS(N-1, C);

	cout << m << endl;
	return 0;
}