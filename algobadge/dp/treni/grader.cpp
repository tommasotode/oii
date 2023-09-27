#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>

int tempo_massimo(int, int[], int[]);

#define MAXN 2000 + 1
int dp[MAXN][MAXN];




#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000 + 1


int solve(int N, int a[], int b[], int canHyper, int i, int s)
{
	if (i == N)
		return 0;
	
	if (dp[i][canHyper] != -1)
		return dp[i][canHyper];

	// stare fermo
	int fermo =	solve(N, a, b, 1, i+1, s);

	// prendere super
	int super = solve(N, a, b, 0, i+1, s+a[i]);

	//prendere hyper
	int hyper = 0;
	if (canHyper)
		hyper = solve(N, a, b, 1, i+1, s+b[i]);

	int tmp = max(fermo, max(super, hyper));

	dp[i][canHyper] = tmp;
	return tmp;
}


int tempo_massimo(int N, int a[], int b[])
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			dp[i][j] = -1;
		}
	}

	int sol = solve(N, a, b, true, 0, 0);
	return sol;
}














int main()
{
		int n;
		FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
		assert(fscanf(in, "%d", &n) == 1);

		int *a = (int*)calloc(n, sizeof(int));
		int *b = (int*)calloc(n, sizeof(int));

		for(int i=0; i<n; i++){
			assert(fscanf(in, "%d", a + i) == 1);
			assert(fscanf(in, "%d", b + i) == 1);
		}

		int answ = tempo_massimo(n, a, b);
		fprintf(out, "%d\n", answ);

		free(a);
		free(b);

		fclose(in);
		fclose(out);

		return EXIT_SUCCESS;
}
