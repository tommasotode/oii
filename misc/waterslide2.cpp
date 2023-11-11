#include <bits/stdc++.h>
#define MAXM 200000
using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;

	Graph(int n)
	{
		N = n;
		adj.resize(n);
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}

	int BFS(int x, int P)
	{
		queue<int> queue;
		vector<float> distance = vector<float>(N, 0.0f);
		vector<bool> visited = vector<bool>(N);
		queue.push(x);
		distance[x] = 1.0f;
		visited[x] = true;

		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
			int cont = 0;

			for (auto v : adj[s])
			{
				if (!visited[v])
				{
					visited[v] = true;
					queue.push(v);
				}

				distance[v] += distance[v] / adj[s].size();
			}
		}

		int best = N - P;
		for (int i = best + 1; i < N; i++)
			if (distance[i] > distance[best])
				best = i;
		return best;
	}
};

int find_pool(int N, int M, int P, int A[], int B[])
{
	Graph g = Graph(N);
	for (int i = 0; i < M; i++)
	{
		g.addEdge(A[i], B[i]);
	}

	int a = g.BFS(0, P);
	return a;
}

int A[MAXM];
int B[MAXM];

int main()
{
	int N, M, P;

	//  ifstream cin("input.txt");
	//  ofstream cout("output.txt");
	ios::sync_with_stdio(false);
	cin >> N >> M >> P;

	for (int i = 0; i < M; i++)
	{
		cin >> A[i] >> B[i];
	}
	int r = find_pool(N, M, P, A, B);

	cout << r << endl;

	return 0;
}
