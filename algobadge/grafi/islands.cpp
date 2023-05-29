/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int R, C, i, j;
int M[MAXN][MAXN];

// isEnd?

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

	assert(2 == scanf("%d %d", &R, &C));
	for(i=0; i<R; i++)
		for (j=0; j<C; j++)
			assert(1 == scanf("%d", &M[i][j]));

	// insert your code here

	int res = 0;
	for(int i=0; i<C-1; i++)
	{
		for(int j=0; j<R-1; j++)
		{
			if(M[i][j] == 1)
			{
				if((M[i][j+1] == 0 && M[i+1][j] == 0))
					res++;
			}
		}
	}


	printf("%d\n", res);
	return 0;
}
