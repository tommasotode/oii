#include <bits/stdc++.h>
using namespace std;

int rimembra(int N, int K, vector<int> V)
{
	int res = 0;

	int l = 0;
	int zeros = 0;
	for (int r = 0; r < N; r++)
	{
		if (V[r] == 0)
			zeros++;

		while (zeros > K)
		{
			if (V[l] == 0)
				zeros--;

			l++;
		}

		res = max(res, (r - l + 1));
	}

	return res;
}

int main()
{
	ifstream cin("input.txt");

	int N, K;
	cin >> N >> K;

	vector<int> V(N);
	for (int &x : V)
		cin >> x;

	cout << rimembra(N, K, V) << "\n";
}