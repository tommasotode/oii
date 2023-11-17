#include <bits/stdc++.h>
using namespace std;
int solve(int N, int K, int *V, int *C)
{
	
	return 42;
}

int main()
{
	FILE *fr = stdin;
	FILE *fw = stdout;
	int N, K;
	assert(fscanf(fr, "%d %d", &N, &K));
	int *V = new int[N];
	int *C = new int[N];
	for (int i = 0; i < N; i++)
		assert(fscanf(fr, "%d", V + i) == 1);
	for (int i = 0; i < N; i++)
		assert(fscanf(fr, "%d", C + i) == 1);
	fprintf(fw, "%d", solve(N, K, V, C));
	delete[] V;
	delete[] C;
	return 0;
}