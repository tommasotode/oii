#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000 + 1
int dp[MAXN][2];

int solve(int N, int a[], int b[], bool canHyper, int i)
{
	if (i >= N)
		return 0;
	
	if (dp[i][canHyper] != -1)
		return dp[i][canHyper];

	// stare fermo
	int fermo =	solve(N, a, b, true, i+1);

	// prendere super
	int super = a[i] + solve(N, a, b, false, i+1);

	int hyper = 0;
	//prendere hyper
	if (canHyper)
		hyper = b[i] + solve(N, a, b, false, i+1);

	int tmp = max(fermo, max(super, hyper));

	dp[i][canHyper] = tmp;
	return tmp;

}

int tempo_massimo(int N, int a[], int b[])
{
	for (int i = 0; i < MAXN; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	
	int sol = solve(N, a, b, true, 0);

	return sol;
}