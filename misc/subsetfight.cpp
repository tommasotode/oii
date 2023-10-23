#include <bits/stdc++.h>
using namespace std;

#define MAXK 100 + 1
//#define MAXV 200 + 1

#define MAX_LEN 3000

int K;
int V[MAXK];

int count(int arr[MAX_LEN] , int n , int K)
{
	int dp[n + 1][K + 1];
 
	for (int j = 0; j < K; j++)
	{
		dp[n][j] = (j == 0) ? 1 : 0;
	}
 
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < K; j++)
		{
			dp[i][j] = dp[i + 1][j] + dp[i + 1][(j - arr[i] + K) % K];
		}
	}
 
	return dp[0][0];
}

int find(int V[MAXK], int n, int K)
{
	int new_arr[MAX_LEN];
	int ind = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < V[i]; j++)
		{
			new_arr[ind] = i + 1;
			ind++;
		}
	}

	return count(new_arr, ind, K);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
	assert(1 == scanf("%d", &K));
	for(int i=0; i<K; i++) assert(1 == scanf("%d", &V[i]));

	int res = find(V, K, K);
	
	printf("%d\n", res);
	return 0;
}