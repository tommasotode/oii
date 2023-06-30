#include <bits/stdc++.h>
using namespace std;

long long mergeInversions(int V[], int tmpV[], int l, int r, int mid)
{
	int i = l, k = l, j = mid;
	long long result = 0;

	while ((i <= mid - 1) && (j <= r))
	{
		if (V[i] <= V[j])
		{
			tmpV[k] = V[i];
			i++;
			k++;
		}
		else
		{
			tmpV[k] = V[j];
			j++;
			k++;
			result = result + (mid - i);
		}
	}

	while (i <= mid - 1)
	{
		tmpV[k] = V[i];
		k++;
		i++;
	}

	while (j <= r)
	{
		tmpV[k] = V[j];
		k++;
		j++;
	}

	for (i = l; i <= r; i++)
		V[i] = tmpV[i];

	return result;
}

long long inversioni(int V[], int tmpV[], int l, int r)
{
	long long result = 0;
	if (r > l)
	{
		int mid = (r + l) / 2;
		result = result + inversioni(V, tmpV, l, mid);
		result = result + inversioni(V, tmpV, mid + 1, r);
		
		result = result + mergeInversions(V, tmpV, l, r, mid + 1);
	}
	return result;
}

long long paletta_sort(int N, int V[])
{
	long long result = 0;
	int pari = (N + 1) / 2, dispari = N / 2;
	int Vpari[pari];
	int Vdispari[dispari];

	int p = 0, d = 0;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			if (V[i] % 2 != 0)
				return -1;
			Vpari[p] = V[i];
			p++; 
		}
		else
		{
			if (V[i] % 2 == 0)
				return -1;
			Vdispari[d] = V[i];
			d++;
		}
	}

	int tmpPari[pari];
	int tmpDispari[dispari];
	result = result + inversioni(Vpari, tmpPari, 0, pari-1);
	result = result + inversioni(Vdispari, tmpDispari, 0, dispari-1);

	return result;
}