#include <bits/stdc++.h>
using namespace std;

#define MAXK 100 + 1

#define MAX_LEN 2600

int K;
int V[MAXK];

int findCnt(int arr[], int n, int K)
{
    int dp[K] = { 0 };
    dp[0] = 1;
 
    for (int i = 0; i < n; i++)
	{
        int next_dp[K];
 
        for (int j = 0; j < K; j++)
		{
            next_dp[j] = (dp[j] % (1000000000 + 7)) + (dp[(j - arr[i] + K) % K] % (1000000000 + 7));
        }
 
        memcpy(dp, next_dp, sizeof(next_dp));
    }
 
    return dp[0];
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

	return findCnt(new_arr, ind, K);
}

int main()
{
  	//freopen("input.txt", "r", stdin);
  	//freopen("output.txt", "w", stdout);
	assert(1 == scanf("%d", &K));
	for(int i=0; i<K; i++) assert(1 == scanf("%d", &V[i]));

	int res = find(V, K, K) % (1000000000 + 7);
	
	printf("%d\n", res);
	return 0;
}