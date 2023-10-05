#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>



using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;

	Graph(int n)
	{
		adj.resize(n);
	}

	void addVertex(int v)
	{
		adj[v] = vector<int>();
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}	

	int BFS(int x, int end, vector<int> C)
	{
		queue<int> queue;
		bool visited[N];
		int distance[N];
		int min_path = INT_MAX;

		visited[x] = true;
		distance[x] = 0;
		queue.push(x);
		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
			for (auto v : adj[s])
			{
				if (visited[v]) continue;

				distance[v] = distance[s] + 1;
				int indiceguardia = (C.size() % distance[v]);
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
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, M, L;
	cin >> N >> M >> L;

	vector<int> A(M), B(M);
	for (int i = 0; i < M; ++i) cin >> A[i] >> B[i];

	vector<int> C(L);
	for (auto &x : C) cin >> x;

	

	cout << 42 << endl;
	return 0;
}
