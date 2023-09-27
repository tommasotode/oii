#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 5000 + 1
using namespace std;

int N, X, i;
int P[MAXN], Q[MAXN];

unsigned int dp[MAXN][10000 + 1];

unsigned int solve(int ix, int X, int N)
{
    if (ix >= N)
        return 0;

    if (dp[ix][X] != -1)
        return dp[ix][X];

    unsigned int included = 0;
    if (X - Q[ix] >= 0)
        included = P[ix] + solve(ix+1, X-Q[ix], N);

    unsigned int r = max(included, solve(ix+1, X, N));
    dp[ix][X] = r;

    return r;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &X));
    for(i=0; i<N; i++)
        assert(2 == scanf("%d %d", &P[i], &Q[i]));


    for (int a = 0; a < MAXN; a++)
    {
        for (int b = 0; b < MAXN; b++)
        {
            dp[a][b] = -1;
        }
    }

    int i = solve(0, X, N);

    printf("%d\n", i);
    return 0;
}
