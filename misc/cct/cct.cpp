#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 1
#define MAXK 20 + 1

int N, K;
int *T, *C;

int dp[MAXN][MAXK];

int cct(int i, int k)
{
	if (i > N)
		return 0;

	if (dp[i][k] != -1)
		return dp[i][k];

	int notSkipped = T[i] + cct(i + 1, min(K, k + C[i]));

	int skipped = INT_MAX;
	if (k >= K)
		skipped = cct(i + 1, 0);

	return dp[i][k] = min(notSkipped, skipped);
}

long long int solve()
{
	for (int n = 0; n < MAXN; n++)
		for (int k = 0; k < MAXK; k++)
			dp[n][k] = -1;

	return cct(0, 0);
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