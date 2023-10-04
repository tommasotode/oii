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
	
	// quando passo tutti i vicini li aggiungo alla coda
	// in questo caso devo aggiungerli, però tanto so già che se li aggiungo e c'è la guardia non va bene
	// quindi quando sto per aggiungerlo mi fermo nel caso in cui ci sia la guardia
	// ma la vera domanda è: cosa faccio?
	// trovo la guardia.
	// poi -> aumento di uno la lunghezza del percorso
	// sta volta il modulo aumenta
	// vuol dire che la prossima volta che trovo la guardia skippo


	void BFS(int x)
	{
		queue<int> queue;
		bool visited[N];
		int distance[N];
		int statoguardia;

		visited[x] = true;
		distance[x] = 0;
		queue.push(x);
		while (!queue.empty())
		{
			int s = queue.front(); queue.pop();
			for (auto v : adj[s])
			{
				if (visited[v]) continue;


				bool guardiaprossimo = true;
				visited[v] = true;
				if (guardiaprossimo)
				{
					distance[v] = distance[s] + 2;
					statoguardia++;
				}
				distance[v] = distance[s] + 1;
				queue.push(v);
			}
		}
	}
	

	//int recursiveBFS(queue<int> &q, vector<int> &distance, vector<bool> &discovered, int dest, int d, int i)
	//{
	
	//	if (q.empty()) return dest;

	//	if (i == q.size()) return distance[dest];

	//	int v = q.front();

	//	int notIncluded = recursiveBFS(q, distance, discovered, dest, distance[v] + 1, i +1 );

 	//	q.pop();
	
	//	for (int u: adj[v])
	//	{
	//		if (discovered[u]) continue;
			
	//		discovered[u] = true;
	//		distance[u] = distance[v] + 1;
	//		q.push(u);
	//	}
	
	//	int included = recursiveBFS(q, distance, discovered, dest, distance[v] + 1, i + 1);
	//	return min(included, notIncluded);
	//}
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


	// ogni funzione
	// provo a rifare la funzione uguale senza cambiarae niente
	// provo a farla dopo aver fatto la bfs
	//	

	cout << 42 << endl;
	return 0;
}
