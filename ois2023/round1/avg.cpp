#include <bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, K;
	cin >> N >> K;
	vector<uint64_t> P(N);
	for (int i = 0; i < N; ++i)
		cin >> P[i];

	uint64_t sum = 0;
	uint64_t prod = N * K;
	for (int i = 0; i < N; i++)
		sum += P[i];

	int r = 1;
	if (sum < prod) cout << 1 << endl;
	else if (sum > prod)
	{
		sort(P.rbegin(), P.rend());
		for (int i = 0; i < N; i++)
		{
			sum -= (P[i]-1);
			if (sum <= prod)
			{
				cout << r << endl;
				break;
			}
			++r;
		}
	}
	else cout << 0 << endl;

	return 0;
}
