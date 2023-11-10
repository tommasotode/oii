#include <bits/stdc++.h>
#define MAXM 200000

using namespace std;

class Graph
{
public:
	int N;
	vector<vector<int>> adj;
    vector<bool> visited;

	Graph(int n)
	{
		adj.resize(n);
        visited = vector<bool>(N);
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

    int DFS(int s, int start)
    {
        if(visited[s]) return;
        visited[s] = true;

        if (s == 0)
        {
            return start;
        }

        for (int neighbour : adj[s])
        {
            DFS(neighbour, start);
        }
    }
};


int find_pool(int N, int M, int P, int A[], int B[])
{
    Graph g = Graph(N);
    for(int i = 0; i < M; i++)
    {
        g.addEdge(A[i], B[i]);
    }

    return 4;
}


int A[MAXM];
int B[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, P, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", find_pool(N, M, P, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
