#include <bits/stdc++.h>
using namespace std;

#define MAXI 12
#define MAXSUM 1001

int dp[MAXI][MAXSUM];

int solve(int i, int sum, vector<int> &coins, int &N, int &amount)
{
	if (sum == amount)
	{
		// trovata la somma giusta, soluzione valida (caso base)
		return 0;
	}

	if (i >= N)
	{
		// finito l'array, soluzione non trovata
		return MAXSUM + 10;
	}

	if (sum > amount)
	{
		// superata la somma, soluzione non valida
		return MAXSUM + 10;
	}

	if (dp[i][sum] != -1)
	{
		// soluzione già calcolata
		return dp[i][sum];
	}

	int included = 1 + solve(i, sum+coins[i], coins, N, amount);
	int notIncluded = solve(i+1, sum, coins, N, amount);

	return min(included, notIncluded);
}


class Solution
{
public:

	int coinChange(vector<int> &coins, int amount)
	{
		int N = coins.size();
		int r = solve(0, 0, coins, N, amount);
		
		if (r > MAXSUM)
			return -1;
		else
			return r;
	}
};


int main()
{
	Solution s = Solution();
	for (int i = 0; i < MAXI; i++)
		for(int j = 0; j < MAXSUM; j++)
			dp[i][j] = -1;

	vector<int> c = {4, 3, 1};
	int limit = 6;

	int r = s.coinChange(c, limit);
	cout << r;

	return 0;
}
