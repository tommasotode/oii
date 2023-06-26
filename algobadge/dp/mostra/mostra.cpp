#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 1;
const int MAXM = 1000 + 1;

int lookup[MAXN][MAXM];

int accoppia(int turisti, int guide, vector<int> &V, vector<int> &G)
{
	if (lookup[turisti][guide] != -1)
		return lookup[turisti][guide];
	
	if (turisti == 0)
		return 0;

	if (guide == 0)
		return turisti * 1;

	int guida = accoppia(turisti, guide - 1, V, G);

	int turista = accoppia(turisti - 1, guide, V, G) + 1;

	int entrambi = 0;
	if (G[guide] > V[turisti])
		entrambi = accoppia(turisti - 1, guide - 1, V, G) + 2;

	int tmp = max(max(turista, entrambi), guida);
	
	lookup[turisti][guide] = tmp;
	return tmp;
}

int solve()
{
	int N, M;
	cin >> N >> M;

	vector<int> V(N), G(M);

	for (int i=0; i<N; i++)
		cin >> V[i];
	for (int i=0; i<M; i++)
		cin >> G[i];

	V.insert(V.begin(), 0);
	G.insert(G.begin(), 0);
	int risposta = accoppia(N, M, V, G);

	return risposta;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, t;
	cin >> T;

	for (t = 1; t <= T; t++)
	{
	
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXM; j++)
				lookup[i][j] = -1;

		cout << "Case #" << t << ": " << solve() << endl;
	}
}