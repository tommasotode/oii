#include <bits/stdc++.h>

using namespace std;

#define MAXK 100

int K;
int V[MAXK];

int dp[MAXK][MAXK];

int cont = 0;


int subsets(int V[MAXK], int index, int K)
{
	if (index == K)
	{
		return 0;
	}

	int included = V[index] + subsets(V, index+1, K);
	int notIncluded = subsets(V, index+1, K);

	if (included % K == 0)
		cont++;
	if(notIncluded % K == 0)
		cont++;

	return 0;
}

int findCnt(int* arr, int i, int curr, int n, int m)
{
	// Base case
	if (i == n)
	{
		if (curr == 0)
			return 1;
		else
			return 0;
	}
 
	if (dp[i][curr] != -1)
		return dp[i][curr];
 
	// Recurrence relation
	return dp[i][curr] = findCnt(arr, i + 1, curr, n, m) +
	findCnt(arr, i + 1, (curr + arr[i]) % m, n, m);
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

	assert(1 == scanf("%d", &K));
	for(int i=0; i<K; i++) assert(1 == scanf("%d", &V[i]));

	// qui -> arriva array con numero di carte di quell'indice
	int V[6] = {1, 2, 2, 3, 3, 3};


	for (int i = 0; i < MAXK; i++)
	{
		for (int j = 0; j < MAXK; j++)
		{
			dp[i][j] = -1;
		}
	}
	int a = findCnt(V, 0, 0, 6, K);
	// posso o fare l'array vero
	// o fare calcoli considerando le moltiplicazioni

	
	printf("%d\n", 42);
	return 0;
}
