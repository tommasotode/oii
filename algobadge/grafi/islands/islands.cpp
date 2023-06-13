#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>
using namespace std; 

#define MAXN 1000

int R, C, i, j;
int M[MAXN][MAXN];

bool isIsland(int x, int y)
{
	// visitato
	M[x][y] = -1;
	
	
	// do per scontato che sia vero, se trovo un uno in un bordo (unico caso falso)
	// da qualsiasi parte, vuol dire che non è un'isola, ritorno false
	// se trovo un uno non in un bordo, vado avanti finché non trovo più uno
	// oppure finché non trovo un uno in un bordo
	bool u = true, d = true, l = true, r = true;

	if(M[x][y-1] == 1)
	{
		if(y-1 <= 0)
			u = false;
		else
			u = isIsland(x, y-1);
	}

	if(M[x][y+1] == 1)
	{
		if(y+1 >= C-1)
			d = false;
		else
			d = isIsland(x, y+1);
	}

	if(M[x-1][y] == 1)
	{
		if(x-1 <= 0)
			l = false;
		else
			l = isIsland(x-1, y);
	}

	if(M[x+1][y] == 1)
	{
		if(x+1 >= R-1)
			r = false;
		else
			r = isIsland(x+1, y);
	}

	// solo se da nessuna parte c'è un bordo è un'isola, se no no
	return u && d && l && r;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	assert(2 == scanf("%d %d", &R, &C));
	for(i=0; i<R; i++)
		for (j=0; j<C; j++)
			assert(1 == scanf("%d", &M[i][j]));


	long long result = 0;
	
	
	// salto direttamente i bordi, perché verificarli non serve
	// a niente
	for(int i=1; i<R-1; i++)
	{
		for(int j=1; j<C-1; j++)
		{
			if(M[i][j] == 1)
			{	
				if(isIsland(i, j))
					result++;
			}
		}
	}

	printf("%lld\n", result);
	return 0;
}