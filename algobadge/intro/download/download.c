#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, t;
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		int N, F, C;
		int nf, nc;
		scanf("%d %d %d", &N, &F, &C);

		nf = N / F;
		nc = (N % F) / C; 
		printf("Case #%d: %d %d\n", t, nf, nc);
	}
}