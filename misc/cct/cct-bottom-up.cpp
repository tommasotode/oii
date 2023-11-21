#include <bits/stdc++.h>
using namespace std;

int N, K;
int *T, *C;

int cct_bottom_up()
{
	int dp[N + 1][K + 1];
	for (int i = 0; i <= K; i++)
		dp[N][i] = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int k = 0; k <= K; k++)
		{
			int notSkipped = T[i] + dp[i + 1][min(K, k + C[i])];
			int skipped = INT_MAX;
			if (k == K)
				skipped = dp[i + 1][0];

			dp[i][k] = min(notSkipped, skipped);
		}
	}
	return dp[0][0];
}

long long int solve()
{
	return cct_bottom_up();
}

int main()
{
	FILE *fr = stdin, *fw = stdout;
	assert(fscanf(fr, "%d %d", &N, &K));

	T = new int[N];
	C = new int[N];
	for (int i = 0; i < N; i++)
		assert(fscanf(fr, "%d", T + i) == 1);
	for (int i = 0; i < N; i++)
		assert(fscanf(fr, "%d", C + i) == 1);

	fprintf(fw, "%d", solve());
	delete[] T;
	delete[] C;
	return 0;
}