#include <bits/stdc++.h>
using namespace std;

// #include <cstdio>
// #include <cassert>
// #include <cstdlib>

// static FILE *fr, *fw;

// #define EVAL

// // Declaring variables
// static int N;
// static int* V;
// static long long int numero_ribaltamenti;

// long long int paletta_sort(int N, int* V);

// int main()
// {
// 	#ifdef EVAL
// 		fr = fopen("input.txt", "r");
// 		fw = fopen("output.txt", "w");
// 	#else
// 		fr = stdin;
// 		fw = stdout;
// 	#endif

// 	// Reading input
// 	fscanf(fr, "%d ", &N);
// 	V = (int*)malloc(N * sizeof(int));
// 	for (int i0 = 0; i0 < N; i0++)
// 	{
// 		fscanf(fr, "%d ", &V[i0]);
// 	}

// 	// Calling functions
// 	numero_ribaltamenti = paletta_sort(N, V);

// 	// Writing output
// 	fprintf(fw, "%lld\n", numero_ribaltamenti);
	
// 	fclose(fr);
// 	fclose(fw);
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
			i++;
		}
		else
		{
			tmpV[k] = V[j];
			j++;
			result = result + (j + mid - k);
		}
		k++;
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

	return result;
}

long long int inversions(int V[], int tmpV[], int l, int r)
{
	long long int result = 0;
	if (l < r)
	{
		long long int mid = l + (r - l) / 2;

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
	int tmpPari[pari];
	int tmpDispari[dispari];

	long long int p = 0, d = 0;

	for (long long int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			if (V[i] % 2 != 0)
				return -1;
			Vpari[p] = V[i];
			tmpPari[p] = V[i];
			p++; 
		}
		else
		{
			if (V[i] % 2 == 0)
				return -1;
			Vdispari[d] = V[i];
			tmpDispari[d] = V[i];
			d++;
		}
	}


	result = result + inversions(Vpari, tmpPari, 0, pari-1);
	result = result + inversions(Vdispari, tmpDispari, 0, dispari-1);

	return result;
}