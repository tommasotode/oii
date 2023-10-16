#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X);

	vector<int> timings = vector<int>(X, 0);
	for(auto student : H)
	{
		timings[student]++;
	}

	for (int i = 0; i < X; i++)
	{
		int coda = 0, res = 0;
		for (int sec = i; sec < X; sec++)
		{
			if (timings[sec] > (K - coda))
				coda += (K - coda);
			else
				coda += timings[sec];

			if (coda != 0)
			{
				coda--;	res++;
			}

		}
		R[i] = res;
	}

	return R;
}