#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H);

vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X, 0);

	vector<int> timings = vector<int>(X, 0);
	for (auto student : H)
		timings[student]++;

	int coda = 0;
	if (timings[X - 1] > 0)
	{
		R[X - 1] = 1;
		coda = min(K, timings[X - 1]);
		coda--;
	}

	for (int sec = X - 2; sec >= 0; sec--)
	{
		if (timings[sec] > 0)
		{
			if (timings[sec] > (K - coda))
			{
				R[sec] = R[sec + 1] + (K - coda);
				coda += (K - coda);
			}
			else
			{
				R[sec] = R[sec + 1] + timings[sec];
				coda += timings[sec];
			}

			if (coda > 0)
				coda--;
		}
		else
		{
			R[sec] = R[sec + 1];
		}
	}
	return R;
}


int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, K, X;
	cin >> N >> K >> X;

	vector<int> H(N);
	for (int& h : H)
	{
		cin >> h;
	}

	vector<int> res = cucina(N, K, X, move(H));
	for (int r : res)
	{
		cout << r << ' ';
	}
	cout << endl;

	return 0;
}