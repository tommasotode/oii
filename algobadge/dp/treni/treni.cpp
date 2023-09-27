#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000 + 1

int dp[MAXN][MAXN];

int solve(int N, int a[], int b[], bool canHyper, int i, int s)
{
	if (i >= N)
		return s;
	
	if (dp[i][canHyper] != -1)
		return dp[i][canHyper];

	// stare fermo
	int fermo =	solve(N, a, b, true, i+1, s);

	// prendere super
	int super = solve(N, a, b, false, i+1, s+a[i]);

	//prendere hyper
	int hyper = 0;
	if (canHyper)
		hyper = solve(N, a, b, false, i+1, s+b[i]);

	int tmp = max(fermo, max(super, hyper));

	dp[i][canHyper] = tmp;
	return tmp;
}


int tempo_massimo(int N, int a[], int b[])
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			dp[i][j] = -1;
		}
	}

	int sol = solve(N, a, b, true, 0, 0);
	return sol;
}