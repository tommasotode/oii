#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long V[15];

int main() {
	for (int i = 0; i < 15; i++)
		cin >> V[i];

	vector<long long> prices = {1, 2, 5, 10, 20, 50, 100, 2*100, 5*100, 10*100, 20*100, 50*100, 100*100, 200*100, 500*100};

	long long s = 0;
	for (long long i = 0; i < 15; i++)
		s += V[i] * prices[i];
	
	reverse(prices.begin(), prices.end());
	vector<long long> sol = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	long long tmp_s = 0;
	for (int mi = 0; mi < prices.size(); mi++)
	{
		while( (tmp_s + (prices[mi] * 32)) <= s )
		{
			tmp_s += (prices[mi] * 32);
			sol[14-mi] += 32;
		}

		while( (tmp_s + (prices[mi] * 16)) <= s )
		{
			tmp_s += (prices[mi] * 16);
			sol[14-mi] += 16;
		}
		
	   while( (tmp_s + (prices[mi] * 8)) <= s )
		{
			tmp_s += (prices[mi] * 8);
			sol[14-mi] += 8;
		}

		while( (tmp_s + (prices[mi] * 4)) <= s )
		{
			tmp_s += (prices[mi] * 4);
			sol[14-mi] += 4;
		}	
		
		while( (tmp_s + (prices[mi] * 2)) <= s )
		{
			tmp_s += (prices[mi] * 2);
			sol[14-mi] += 2;
		}
		
		while ( (tmp_s + prices[mi]) <= s )
		{
			tmp_s += prices[mi];
			sol[14-mi] += 1;
		}
	}

	for (int i = 0; i < 15; i++)
		cout << sol[i] << " ";
	cout << endl;
	return 0;
}
