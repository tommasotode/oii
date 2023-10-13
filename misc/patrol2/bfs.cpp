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

	int BFS(int exit, vector<int> policepath)
	{
		queue<int> queue;
		vector<bool> visited(N, false);
		vector<int> distance(N, INT_MAX);		
		int min_path = INT_MAX;

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
				int ipolice = (distance[v] % policepath.size());
				bool occupied = (v == policepath[ipolice]);

				if (occupied)
					distance[v]++;
				
				if (v == exit)
					min_path = min(min_path, distance[v]);
				else
					visited[v] = true;

				queue.push(v);
			}
		}

		reversedBFS(distance);
		reversedBFS(distance);

		return distance[N-1];
	}

	void reversedBFS(vector<int> &distance)
	{
		queue<int> queue;
		vector<bool> visited(N, false);


		visited[N-1] = true;
		queue.push(N-1);
		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
		
			int min_d = INT_MAX;
		
			for (auto v : adj[s])
			{
				if (visited[v]) continue;
				visited[v] = true;

				min_d = min(min_d, distance[v]);

				queue.push(v);
			}

			distance[s] = min_d + 1;
		}
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