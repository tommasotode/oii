#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>
using namespace std; 

#define MAXN 1000

int R, C, i, j;
int M[MAXN][MAXN];

bool isIsland(int y, int x)
{

	// do per scontato che sia vero, se trovo un uno in un bordo (unico caso falso)
	// da qualsiasi parte, vuol dire che non è un'isola, ritorno false
	// se trovo un uno non in un bordo, vado avanti finché non trovo più uno
	// oppure finché non trovo un uno in un bordo

	bool u = true, d = true, l = true, r = true;
	
	// visitato
	M[x][y] = -1;

	if(M[x][y-1] == 1)
	{
		if(y-1 <= 0)
			return false;
		else
			u = isIsland(y-1, x);
	}

	return u && d && l && r;
}

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

	assert(2 == scanf("%d %d", &R, &C));
	for(i=0; i<R; i++)
		for (j=0; j<C; j++)
			assert(1 == scanf("%d", &M[i][j]));


	int res = 0;
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			if(M[i][j] == 1)
			{
				if(isIsland(i, j))
					res++;
			}
		}
	}

	printf("%d\n", res);
	return 0;
}
