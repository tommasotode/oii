#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 5000
using namespace std;

int N, X, i;
int P[MAXN], Q[MAXN];

int dp[MAXN][MAXN][MAXN];

int solve(int ix, int X, int N)
{
    if (ix >= N)
        return 0;

    if (dp[ix][N][X] != -1)
    {
        return dp[ix][N][X];
    }

    // con
    int included = 0;
    if (X - Q[ix] >= 0)
        included = P[ix] + solve(ix+1, X-Q[ix], N);

    // senza
    int notIncluded = solve(ix+1, X, N);

    int r = max(included, notIncluded);
    dp[ix][N][X]= r;

    return r;
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &X));
    for(i=0; i<N; i++)
        assert(2 == scanf("%d %d", &P[i], &Q[i]));

    for (int j = 0; j < MAXN; j++)
    {
        for (int k = 0; k < MAXN; k++)
        {
            for (int asd = 0; asd < MAXN; asd++)
            {
                dp[j][k][asd] = -1;
            }
        }
    }
    int i = solve(0, X, N);

    printf("%d\n", i);
    return 0;
}