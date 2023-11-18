#include <bits/stdc++.h>
using namespace std;

int N, K, a, b;

#define MAXN 1000 + 1
#define MAXK 50 + 1
int dp[MAXN][MAXK];

int mod_power(int base, int exp, int mod)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	int temp = mod_power(base, exp / 2, mod);
	if (exp % 2 == 0)
		return (temp % mod * temp % mod) % mod;
	else
		return (base % mod * temp % mod * temp % mod) % mod;
}

int cct(int i, int k)
{
	if (i == N)
		return 0;

	if (dp[i][k] != -1) return dp[i][k];

	int notSkipped = mod_power(a, i, 1000) + cct(i + 1, min(K, k + mod_power(b, i, K)));

	int skipped = INT_MAX;
	if (k == K)
		skipped = cct(i + 1, 0);

	return dp[i][k] = min(notSkipped, skipped);
}

int speedrunna(int N_, int K_, int a_, int b_)
{
	N = N_; K = K_; a = a_; b = b_;

	for(int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXK; j++)
			dp[i][j] = -1;

	int r = cct(0, 0);
	return r;
}