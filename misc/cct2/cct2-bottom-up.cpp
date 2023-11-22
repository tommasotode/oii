#include <bits/stdc++.h>
using namespace std;
int N, K, a, b;

int mod_power(int base, int exp, int mod)
{
	int res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp & 1)
			res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

int cct_bottom_up()
{	
	int base_dp[K+1]; int curr_dp[K+1];
	for (int i = 0; i <= K; i++) base_dp[i] = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int k = 0; k <= K; k++)
		{
			int notSkipped = mod_power(a, i, 1000) + base_dp[min(K, k + mod_power(b, i, K))];
			int skipped = INT_MAX;
			if (k == K)
				skipped = base_dp[0];

			curr_dp[k] = min(skipped, notSkipped);
		}
		memcpy(base_dp, curr_dp, sizeof(curr_dp));
	}
	return curr_dp[0];
}

int speedrunna(int N_, int K_, int a_, int b_)
{
	N = N_; K = K_; a = a_; b = b_;

	return cct_bottom_up();
}
