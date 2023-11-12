#include <bits/stdc++.h>
using namespace std;

#define MAXI 12
#define MAXSUM 10000
#define INF MAXSUM + 1
int dp[MAXI][MAXSUM];

int solve(const int i, const int sum, const vector<int> &coins, const int &N, const int &amount)
{	
	if (i >= N)
	{
		// finito l'array, soluzione non trovata
		return INF;
	}

	if (sum > amount)
	{
		// superata la somma, soluzione non valida
		return INF;
	}

	if (sum == amount)
	{
		// trovata la somma giusta, soluzione valida (caso base)
		return 0;
	}

	if (dp[i][sum] != -1)
	{
		// soluzione già calcolata
		return dp[i][sum];
	}

	// moneta più grande di amount, non ha senso includere
	int included = INF;
	if (coins[i] <= amount)
		included = 1 + solve(i, sum+coins[i], coins, N, amount);
	int notIncluded = solve(i+1, sum, coins, N, amount);

	return dp[i][sum] = min(included, notIncluded);
}

class Solution
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		int N = coins.size();
		for (int i = 0; i < N; i++)
			for(int j = 0; j < amount; j++)
				dp[i][j] = -1;

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

	vector<int> c = {4, 3, 1};
	int limit = 6;

	int r = s.coinChange(c, limit);
	cout << r;

	return 0;
}

// ( leetcode 322 )