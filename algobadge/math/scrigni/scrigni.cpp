#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

double scosse(int N)
{
	long long int n = (long long)N;
	double result;
	result = ( n*(n-1) ) / 4.0;
	return result;
}

int main()
{
	FILE *fr, *fw;
	int N;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(1 == fscanf(fr, "%d", &N));
	fprintf(fw, "%.6f\n", scosse(N));
	fclose(fr);
	fclose(fw);
	return 0;
}