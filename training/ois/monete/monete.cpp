#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXM 100000

int monete[MAXN];
int A[MAXM], B[MAXM], N, M;

vector<vector<int>> adj;
vector<bool> visited;

int s;
void dfs(int v, int m)
{
	if (visited[v]) return;
	visited[v] = true;
	s += m;
	for (int w : adj[v])
	{
		dfs(w, monete[w]);
	}
}

int main() 
{
	FILE *fr, *fw;
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d%d", &N, &M));
	
  adj = vector<vector<int>>(N);
  visited = vector<bool>(N);

	for(int i=0; i<N; i++)
	{
		assert(1 == fscanf(fr, "%d", &monete[i]));
	}
	for(int i=0; i<M; i++)
	{
		assert(2 == fscanf(fr, "%d%d", &A[i], &B[i]));
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	s = 0;
	dfs(0, monete[0]);

	fprintf(fw, "%d\n", s);

	fclose(fr);
	fclose(fw);
	return 0;
}