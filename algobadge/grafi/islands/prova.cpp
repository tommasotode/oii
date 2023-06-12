#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>
using namespace std; 

#define MAXN 1000

int R, C, i, j;
int M[MAXN][MAXN];
bool visitati[MAXN][MAXN]; 

vector<int> posizioniX = {1, 0, -1, 0}; 
vector<int> posizioniY = {0, 1, 0, -1}; 

bool isValid(int x, int y)
{
	//condizione: non è ai bordi
	if(x <= 0 || x >= R - 1)
		return false; 
	if(y <= 0 || y >= C - 1)
		return false; 
	return true; 
}

bool isIsland(int x, int y)
{
	if(not isValid(x, y))
		return false; 

	//controllo delle celle nelle 4 direzioni 
	for(int i = 0; i < 4; i++)
		//se non l'ho visitato ed è un pezzo di terra 
		if(M[x + posizioniX[i]][y + posizioniY[i]] == 1 and not visitati[x + posizioniX[i]][y + posizioniY[i]])
		{
			visitati[x+posizioniX[i]][y+posizioniY[i]] = true; 
			//se non è un pezzo di un'isola ritorno false 
			if(not isIsland(x + posizioniX[i], y + posizioniY[i])) 
				return false; 
		}   

	return true; 
}


int main() {
	int ans = 0; 
	assert(2 == scanf("%d %d", &R, &C));
	for(i=0; i<R; i++)
		for (j=0; j<C; j++)
			assert(1 == scanf("%d", &M[i][j]));


	deque<pair<int, int>> q;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(M[i][j] == 1 and isValid(i, j))
				q.push_back({i, j}); 
		}
	}



	while(q.size())
	{
		auto x = q.front().first; 
		auto y = q.front().second; 
		q.pop_front(); 
		if(not visitati[x][y])
		{
			if(isIsland(x, y))
				ans++; 
		}


	}

	printf("%d\n", ans); // print the result
	return 0;
}
