#include <bits/stdc++.h>
using namespace std;

int knapSack(int max_w, int W[], int P[], int n)
{
	int dp[n+1][max_w+1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= max_w; j++)
		{
			if (i == 0 || j == 0) 
			{
				dp[i][j] = 0;
				continue;
			}

			// dp is 1 based, since to make it work better in a more elegant way you need the first spaces as 0s
			// W and P are 0 based, so you could either make them 1 based or use i-1 as their index


			// ogni volta arrivo alla parte più sotto della tabella, e ho quello sopra che è il massimo attuale
			// ora posso mettere nella mia casella il massimo fra l'inclusione e la non inclusione di quello attuale.

			int notIncluded = dp[i - 1][j];
			int included = INT_MIN;
			if (W[i - 1] <= j)
				included = P[i - 1] + dp[i - 1][j - W[i - 1]];

			dp[i][j] = max(notIncluded, included);
		}
	}
	return dp[n][max_w];
} 
