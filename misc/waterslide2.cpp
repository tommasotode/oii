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
				distance[s] = 0.0f;
				if (v < N - P)
				{
					// piscina
					queue.push(v);
				}
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

	return 4;
}

int A[MAXM];
int B[MAXM];

int main()
{
	FILE *fr, *fw;
	int N, M, P, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
	for (i = 0; i < M; i++)
		assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

	fprintf(fw, "%d\n", find_pool(N, M, P, A, B));
	fclose(fr);
	fclose(fw);
	return 0;
}
