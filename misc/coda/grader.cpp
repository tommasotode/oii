#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H);

vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X, 0);

	vector<int> timings = vector<int>(X, 0);
	for(auto student : H)
	{
		timings[student]++;
	}

	int liberi = 0;
	if (timings[X-1] == 0) liberi++;
	else R[X-1] = 1;

	for (int sec = X-2; sec >= 0; sec--)
	{
		liberi++;
		if (timings[sec] > 0)
		{
			int p = min(liberi, timings[sec]);

			R[sec] = R[sec+1] + min(p, K);
			
			if (liberi - R[sec] >= 0)
				liberi = liberi - R[sec];
			else
				liberi = 0;
		}
		else
		{
			R[sec] = R[sec+1];
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