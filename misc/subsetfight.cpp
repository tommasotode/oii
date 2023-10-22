#include <bits/stdc++.h>
using namespace std;

#define MAXK 100

int K;
int V[MAXK];
int dp[MAXK][MAXK];

/*
	per ogni n da 0 a V[i]:
		prova includendo
		prova senza includere
*/

int subsets(int V[MAXK], int i, int mod, int n, int K)
{
	if (i == n)
		return (mod == 0);

	if (dp[i][mod] != -1)
		return dp[i][mod];
 
	// ora come ora faccio included e notIncluded per tutti
	// potrebbe avere senso farlo solo per included, però partendo da 0?
	// ripasso comunque lo stesso modulo, quindi non cambia niente 
	// ( mod + (V[i]*x) ) % K	-> 	con x = 0	-> come fare mod % K

	for (int x = 1; x <= V[i]; x++)
	{
		int notIncluded = subsets(V, i + 1, mod, n, K);
		int included = subsets(V, i + 1, (mod + V[i]) % K, n, K);

		return dp[i][mod] = notIncluded + included;
	}

}

int find(int V[MAXK], int n, int K)
{
	for (int i = 0; i < MAXK; i++)
		for (int j = 0; j < MAXK; j++)
			dp[i][j] = -1;

	return subsets(V, 0, 0, n, K);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
	assert(1 == scanf("%d", &K));
	for(int i=0; i<K; i++) assert(1 == scanf("%d", &V[i]));





	int V[6] = {1, 2, 2, 3, 3, 3};
	int res = find(V, 6, 3);
	
	printf("%d\n", res);
	return 0;
}