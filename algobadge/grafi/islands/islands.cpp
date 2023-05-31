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

		if(M[i][right] == -1)
			break;

		if(M[i][right] == 1)
			M[i][right] = -1;
		
		if(M[i][right] == 0)
		{
			r=true;
			break;
		}
	}

	for(int left=j-1; left>=0; left--)
	{

		if(M[i][left] == -1)
			break;

		if(M[i][left] == 1)
			M[left][j] = -1;
		
		if(M[i][left] == 0)
		{
			l=true;
			break;
		}
	}

	for(int down=i+1; down<C; down++)
	{

		if(M[down][j] == -1)
			break;

		if(M[down][j] == 1)
			M[i][down] = -1;
		
		if(M[down][j] == 0)
		{
			d=true;
			break;
		}
	}

	for(int up=i-1; up>=0; up--)
	{

		if(M[up][j] == -1)
			break;

		if(M[up][j] == 1)
			M[up][j] = -1;
		
		if(M[up][j] == 0)
		{
			u=true;
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
	for(i=1; i<C-1; i++)
	{
		for(j=1; j<R-1; j++)
		{
			if(M[i][j] == 1)
				if(isIsland(i, j))
					res++;
		}
	}


	printf("%d\n", res);
	return 0;
}
