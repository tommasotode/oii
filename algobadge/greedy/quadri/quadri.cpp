#include <iostream>
#include <stdlib.h>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

int quadri(int N, long long M, int V[])
{
	int B = N;
	long long somma = 0;
	int inizio = 0;

	for (int fine = 0; fine < N; fine++)
	{
		if (V[fine] > M)
			return 0;
		
		somma = somma + V[fine];
		while (fine > inizio && somma > M)
		{
			somma = somma - V[inizio];
			inizio++;
			B = min(B, fine - inizio + 1);
		}
	}
	return B;
}