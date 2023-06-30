#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int trovaSomme(int subset[], int start, int end, int somma, vector<int> somme)
{
    if (start > end)
	{
		somme.push_back(somma);
        return *min_element(somme.begin(), somme.end());
    }
 
    return trovaSomme(subset, start + 1, end, somma + subset[start], somme);
    return trovaSomme(subset, start + 1, end, somma, somme);
}

int solve(int start, int end, int P[], int K, vector<int> soluzioni, int N)
{
	vector<int> somme;
	int somma = trovaSomme(P, start, end, 0, somme);
	if(start > end || end >= N)
	{
		return (int)*min_element(soluzioni.begin(), soluzioni.end());
	}
	if(somma >= K)
	{
		soluzioni.push_back(somma);
		return solve(start+1, end, P, K, soluzioni, N);
	}
	else
	{		
		return solve(start, end+1, P, K, soluzioni, N);
	}

	int a = (int)*min_element(soluzioni.begin(), soluzioni.end());
	return a;
}

int mangia(int N, int K, int P[])
{
	sort(P, P+N);
	vector<int> soluz;
	int sol = solve(0, 0, P, K, soluz, N);
	return sol;
}

int P[MAXN];

int main()
{
	FILE *fr, *fw;
	int N, K, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d %d", &N, &K));
	for(i=0; i<N; i++)
		assert(1 == fscanf(fr, "%d", &P[i]));

	fprintf(fw, "%d\n", mangia(N, K, P));
	fclose(fr);
	fclose(fw);
	return 0;
}
