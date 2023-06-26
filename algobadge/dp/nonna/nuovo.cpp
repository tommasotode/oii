#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define MAXN 5000 + 1
#define MAXK 5000 + 1
#define MAXP 1000000

// passare ogni volta la matrice è troppo lento
int lookup[MAXN][MAXK];
int P[MAXN];
int inf = MAXP + 1;

int knapsack(int n, int k, int N)
{
	if (k <= 0)
		return 0;

	if (n >= N)
		return inf;

	if (lookup[n][k] != -1)
		return lookup[n][k];

	int included = P[n] + knapsack(n+1, k-P[n], N);
	int notIncluded = knapsack(n+1, k, N);

	int tmp = min(included, notIncluded);
	lookup[n][k] = tmp;

	return tmp;
}

int mangia(int N, int K, int P[])
{
	return knapsack(0, K, N);
}

int main()
{
	FILE *fr, *fw;
	int N, K, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d %d", &N, &K));
	for(i=0; i<N; i++)
		assert(1 == fscanf(fr, "%d", &P[i]));
	
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXK; j++)
			lookup[i][j] = -1;
	}
	
	fprintf(fw, "%d\n", mangia(N, K, P));
	fclose(fr);
	fclose(fw);
	return 0;
}