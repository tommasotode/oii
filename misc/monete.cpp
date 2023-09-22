#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXM 100000

class Graph
{
public:

	unordered_map<int, vector<int>> adj;
	map<int, bool> visited;

	int s;		

	void addVertex(int n)
	{
		adj[n] = vector<int>();
		visited[n] = false;
	}
	
	void addEdge(int e1, int e2)
	{
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}

	void DFS(int start, int monete[MAXN])
	{
		visited[start] = true;
		s += monete[start];
		for (auto& neighbour: adj[start])
		{
			if (visited[neighbour] == false)
			{
				DFS(neighbour, monete);
			}
		}
	}
};

int monete[MAXN];
int A[MAXM], B[MAXM];


int raccogli(int N, int M, int monete[], int A[], int B[])
{
	Graph g;

	for (int i = 0; i < N; i++)
		g.addVertex(i);

	for (int i = 0; i < M; i++)
		g.addEdge(A[i], B[i]);

	g.DFS(0, monete);
	return g.s;
}


int main() 
{
	FILE *fr, *fw;
	int N, M, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d%d", &N, &M));
	for(i=0; i<N; i++)
		assert(1 == fscanf(fr, "%d", &monete[i]));
	for(i=0; i<M; i++)
		assert(2 == fscanf(fr, "%d%d", &A[i], &B[i]));

	fprintf(fw, "%d\n", raccogli(N, M, monete, A, B));
	fclose(fr);
	fclose(fw);
	return 0;
}
