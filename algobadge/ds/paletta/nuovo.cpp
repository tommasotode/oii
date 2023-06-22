#include <bits/stdc++.h>
using namespace std;

// int main()
// {
// 	int V[] = {2, 3, 4, 1, 0, 7, 6, 5, 8, 9};
// 	paletta_sort(10, V);
// 	return 0;
// }

long long int mergeA(int V[], int tmpV[], int l, int r, int mid)
{
	long long int i = l, k = l, j = mid+1;
	long long int result = 0;

	while (i <= mid && j <= r)
	{
		if(V[i] <= V[j])
		{
			tmpV[k] = V[i];
			k++;
			i++;
		}
		else
		{
			tmpV[k] = V[j];
			result = result + (mid-i) + 1;
			k++;
			j++;
		}
	}

	while (i <= mid)
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

	for(int x = l; x < r; x++)
	{
		V[x] = tmpV[x];
	}

	return result;
}

long long int inversions(int V[], int tmpV[], int l, int r)
{
	long long int result = 0;
	if (l < r)
	{
		long long int mid = (l + r) / 2;

		result = result + inversions(V, tmpV, l, mid);
		result = result + inversions(V, tmpV, mid+1, r);

		result = result + mergeA(V, tmpV, l, r, mid);
	}
	
	return result;
}

long long paletta_sort(int N, int V[])
{
	long long int result = 0;

	long long int pari = (N + 1) / 2, dispari = N / 2;

	int Vpari[pari];
	int Vdispari[dispari];

	long long int p = 0, d = 0;

	for (long long int i = 0; i < N; i++)
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
	result = result + inversions(Vpari, tmpPari, 0, pari-1);
	result = result + inversions(Vdispari, tmpDispari, 0, dispari-1);

	return result;
}