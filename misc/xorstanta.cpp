#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

int N, T;
int arr[MAXN];

int solve(int i, int currA, int currB)
{
	if(i > N)
	{
		return 0;
	}

	int includedA = arr[i] ^ solve(i+1, arr[i] ^ currA, currB);
	int includedB = arr[i] ^ solve(i+1, currA, arr[i] ^ currB);

	int m = max(includedA, includedB);

	return m;
}

int s()
{
	for(int i = 0; i < MAXN; i++)
	{
		arr[i] = i+1;
	}

	return solve(0, 0, 0);
}


int main()
{
  	
	freopen("C:\\repos\\oii\\misc\\input.txt", "r", stdin);
	freopen("C:\\repos\\oii\\misc\\output.txt", "w", stdout);

	assert(1 == scanf("%d", &T));
	for (int i = 0; i < T; i++)
	{
		assert(1 == scanf("%d", &N));
		int r = s();

		printf("%d\n", r);
	}

	return 0;
}
