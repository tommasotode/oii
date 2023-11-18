#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define MAXK 50

int N, K, a, b;
int dp[MAXN][MAXK];

int mod_power(int base, int exp, int mod)
{
	int res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp & 1) // 1 if odd, 0 if even
			res = res * base % mod;
		base = base * base % mod;
		exp >>= 1; // divide by 2
	}
	return res;
}

int cct(int i, int k)
{
	if (i == N)
		return 0;

	if (dp[i][k] != -1)
		return dp[i][k];

	int notSkipped = mod_power(a, i, 1000) + cct(i + 1, min(K, k + mod_power(b, i, K)));

	int skipped = INT_MAX;
	if (k == K)
		skipped = cct(i + 1, 0);

	return dp[i][k] = min(notSkipped, skipped);
}

int speedrunna(int N_, int K_, int a_, int b_)
{
	N = N_; K = K_; a = a_; b = b_;

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -1;

	return cct(0, 0);
}