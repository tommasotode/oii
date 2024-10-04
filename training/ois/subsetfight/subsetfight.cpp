#include <bits/stdc++.h>
using namespace std;

#define MAXK 100
#define MAX_LEN 20000000
#define MOD 1000000007

int K;
int V[MAXK];

int subsets(uint8_t V[], int n, uint8_t K)
{
	int dp[K];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		int next_dp[K];
		for (uint8_t j = 0; j < K; j++)
		{
			next_dp[j] = (dp[j] % MOD) + (dp[(j - V[i] + K) % K] % MOD);
		}
		memcpy(dp, next_dp, sizeof(next_dp));
	}

	return dp[0];
}

int find(int V[MAXK], uint8_t n, uint8_t K)
{
	uint8_t new_arr[MAX_LEN];
	int ind = 0;
	for (uint8_t i = 0; i < n; i++)
	{
		memset(new_arr+ind, i+1, (size_t)V[i]);
		ind += V[i];
	}

	return subsets(new_arr, ind, K);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	assert(1 == scanf("%d", &K));
	for (uint8_t i = 0; i < K; i++)
		assert(1 == scanf("%d", &V[i]));

	printf("%d\n", find(V, K, K) % MOD);
	return 0;
}