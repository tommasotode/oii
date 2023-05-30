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

bool isIsland(int i, int j)
{
	// diventa visitato
	bool l = false, r = false, u = false, d = false;

	for(int right=j+1; right<R; right++)
	{
		if(right == R-1 || M[i][right] == -1)
		{
			l=false;
			break;
		}
		if(M[i][right] == 0)
		{
			l=true;
			break;
		}
	}


	for(int left=j; left>=0; left--)
	{
		if(left == 0 || M[i][left] == -1)
		{
			l=false;
			break;
		}
		if(M[i][left] == 0)
		{
			l=true;
			break;
		}
	}

	for(int down=i+1; down<C; down++)
	{
		if(down == C-1 || M[down][j] == -1)
		{
			l=false;
			break;
		}
		if(M[down][j] == 0)
		{
			l=true;
			break;
		}
	}


	for(int up=j; up>=0; up--)
	{
		if(up == 0 || M[up][j] == -1)
		{
			l=false;
			break;
		}
		if(M[up][j] == 0)
		{
			l=true;
			break;
		}
	}

	return l && r && u && d;
	// prova a destra, prova a sinistra, prova giu e prova su
}

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
	for(i=0; i<C; i++)
	{
		for(j=0; j<R; j++)
		{
			if(M[i][j] == 1)
				if(isIsland(i, j))
					res++;
		}
	}


	printf("%d\n", res);
	return 0;
}
