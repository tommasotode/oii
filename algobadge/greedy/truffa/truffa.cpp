#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int sfangate(int N, int V[])
{
	sort(V, V+N);
	long long somma = 0;
	somma = accumulate(V, V+N, 0);
	for (int i = 0; i < N; i++)
	{
		if (somma > 0)
			return i;
		V[i] = -V[i];
		somma = somma + V[i] * 2;
	}
	return N;
}

int V[MAXN];

int main() {
	FILE *fr, *fw;
	int N, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(1 == fscanf(fr, "%d", &N));
	for(i=0; i<N; i++)
		assert(1 == fscanf(fr, "%d", &V[i]));

	fprintf(fw, "%d\n", sfangate(N, V));
	fclose(fr);
	fclose(fw);
	return 0;
}