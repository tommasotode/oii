#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 5000 + 1
#define MAXX 10000 + 1
using namespace std;
#define MAXUINT 65535

int N, X, i;
int P[MAXN], Q[MAXN];

uint16_t dp[MAXN][MAXX];

uint16_t solve(int ix, int X, int N)
{
	if (ix >= N)
		return 0;

	if (dp[ix][X] != MAXUINT)
		return dp[ix][X];

	uint16_t included = 0;
	if (X - Q[ix] >= 0)
		included = P[ix] + solve(ix+1, X-Q[ix], N);

	uint16_t r = max(included, solve(ix+1, X, N));
	dp[ix][X] = r;
	return r;
}

int main()
{
	assert(2 == scanf("%d %d", &N, &X));
	for(i=0; i<N; i++)
		assert(2 == scanf("%d %d", &P[i], &Q[i]));

	for (int a = 0; a < MAXN; a++)
		for (int b = 0; b < MAXX; b++)
			dp[a][b] = MAXUINT;

	printf("%d\n", solve(0, X, N));
	return 0;
}