#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X, 0);

	vector<int> timings = vector<int>(X, 0);
	for(auto student : H)
	{
		timings[student]++;
	}

	int capacita = 0;
	if (timings[X-1] == 0) capacita++;
	else R[X-1] = 1;

	for (int sec = X-2; sec >= 0; sec--)
	{
		capacita++;
		if (timings[sec] > 0)
		{
			int p = min(capacita, timings[sec]);

			R[sec] = R[sec+1] + min(p, K);
			
			if (capacita - R[sec] >= 0)
				capacita = capacita - R[sec];
			else
				capacita = 0;
		}
		else
		{
			R[sec] = R[sec+1];
		}
	}

	return R;
}
