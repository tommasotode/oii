#include <bits/stdc++.h>
using namespace std;

#define MAXK 100 + 1

#define MAX_LEN 2600

int K;
int V[MAXK];

//int count(int arr[MAX_LEN] , int n , int K)
//{
//	int dp[n + 1][K + 1];
 
//	for (int j = 0; j < K; j++)
//	{
//		dp[n][j] = (j == 0) ? 1 : 0;
//	}
 
//	for (int i = n - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < K; j++)
//		{
//			dp[i][j] = dp[i + 1][j] + dp[i + 1][(j - arr[i] + K) % K];
//		}
//	}
 
//	return dp[0][0];
//}


uint64_t findCnt(int V[MAX_LEN], int n, int K)
{
	uint64_t dp[K];
	dp[0] = 1;
 
	for (int i = 0; i < n; i++)
	{
		uint64_t next_dp[K];
 
		for (int j = 0; j < K; j++)
		{
			next_dp[j] = (dp[j] + dp[(j - V[i] + K) % K]) % 1000000000 + 7;
			cout << next_dp[j] << endl;
		}
 
		memcpy(dp, next_dp, sizeof(next_dp));
	}
 
	return dp[0];
}


uint64_t find(int V[MAXK], int n, int K)
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

	return findCnt(new_arr, ind, K);
}

int main()
{
  	//freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	assert(1 == scanf("%d", &K));
	for(int i=0; i<K; i++) assert(1 == scanf("%d", &V[i]));

	uint64_t res = find(V, K, K);
	
	printf("%d\n", res);
	return 0;
}