#include <bits/stdc++.h>

using namespace std;

int find_max(vector<int> &arr, int n)
{
	int m = 0;

	if (n == 1)
		return arr[0];

	for (int i = 0; i < n - 1; i++)
		m = max(m, arr[i] + arr[i + 1]);

	return m + 1;
}

void solve(int t)
{
	int N;
	cin >> N;
	string S;
	cin >> S;

	vector<int> arr;
	int c = 0;

	for (int i = 0; i < N; i++)
	{
		if (S[i] == '1')
			c++;

		if (S[i] == '0' || i == N - 1)
		{
			arr.push_back(c);

			if (S[i + 1] == '0')
			{
				arr.push_back(0);
				while (i + 1 < N && S[i + 1] == '0')
					i++;
			}
			c = 0;
		}
	}

	int risposta = find_max(arr, arr.size());

	cout << "Case #" << t << ": " << risposta << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		solve(t);
	}

	return 0;
}