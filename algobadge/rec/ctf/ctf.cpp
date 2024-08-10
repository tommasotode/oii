#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("input.txt");

	long long Q;
	cin >> Q;
	vector<long long> S(Q);
	for (long long i = 0; i < Q; i++) cin >> S[i];

	for (long long i = 0; i < Q; i++)
	{
		long long n = S[i];
		long long l = floor(log2(n)); 
		long long p = pow(2, l);

		long long R = 2 * (n - p) + 1;

		cout << R << endl;
	}

	return 0;
}