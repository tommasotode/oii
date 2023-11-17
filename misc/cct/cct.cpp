#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 1
#define MAXK 20 + 1
#define MAXT 1000 + 1

int *T, *C;
int N, K;

int cct(int i, int k)
{
	if (i > N)
	{
		return T[i];
	}
	
	bool canSkip;
	canSkip = (k >= K);

	int notSkipped = T[i] + cct(i+1, k+C[i]);

	int skipped = INT_MAX;
	if (canSkip)
	{
		skipped = T[i] + cct(i+1, 0);
	}

	return min(notSkipped, skipped);
}

int solve(int N, int K, int *T, int *C)
{

	return 42;
}

int main()
{
	FILE *fr = stdin, *fw = stdout;
	assert(fscanf(fr, "%d %d", &N, &K));
	T = new int[N];
	C = new int[N];
	
	for (int i = 0; i < N; i++) assert(fscanf(fr, "%d", T + i) == 1);
	for (int i = 0; i < N; i++) assert(fscanf(fr, "%d", C + i) == 1);
	fprintf(fw, "%d", solve(N, K, T, C));
	delete[] T;
	delete[] C;
	return 0;
}