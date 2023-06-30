#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

bool isValid(long long num)
{
	long long prev = -1;
	while(num > 0)
	{
		if (num % 10 == prev)
			return false;
		
		if (num%10 != 3 && num%10 != 6 && num%10 != 9)
			return false;

		prev = num % 10;
		num /= 10;
	}
	return true;	
}

void combine(int N, long long num, int M, vector<long long>& solutions)
{
	bool valid = isValid(num);
	
	if (valid)
		solutions.push_back(num % M);

	if (N <= 0)
		return;

	if (valid)
	{
		combine(N - 1, num * 10 + 3, M, solutions);
		combine(N - 1, num * 10 + 6, M, solutions);
		combine(N - 1, num * 10 + 9, M, solutions);
	}
	else return;

}

long long occulta(int N, int M)
{
	// per aggiungere a destra faccio n*10+x

	vector<long long> solutions;
	combine(N, 0, M, solutions);

	return *max_element(solutions.begin(), solutions.end());
}

int main()
{
	FILE *fr, *fw;
	int T, N, M, i;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(1 == fscanf(fr, "%d", &T));
	for (i=0; i<T; i++)
	{
		assert(2 == fscanf(fr, "%d %d", &N, &M));
		fprintf(fw, "%d ", occulta(N, M));
	}

	fprintf(fw, "\n");
	fclose(fr);
	fclose(fw);
	return 0;
}