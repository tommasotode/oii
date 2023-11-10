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

	void addVertex(int v)
	{
		adj[v] = vector<int>();
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	int BFS(int x, int P)
	{
		queue<int> queue;
		vector<float> distance = vector<float>(N, 0.0f);

		distance[x] = 1.0f;
		queue.push(x);
		while (!queue.empty())
		{
			int s = queue.front();
			queue.pop();
			int cont = 0;
			for (auto v : adj[s])
			{
				if (v < s) continue;
				cont++;
			}

			for (auto v : adj[s])
			{
				if (v < s) continue;

				distance[v] += (float)(distance[s] / cont);
				if (v < N - P)
				{
					// piscina
					queue.push(v);
				}
			}
			distance[s] = 0.0f;

		}

		for (int i = 0; i < distance.size(); i++)
		{
			if (i < N - P)
			{
				distance[i] = 0.0f;
			}
		}
		int maxIndex = max_element(distance.begin(), distance.end()) - distance.begin();
		return maxIndex;
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
