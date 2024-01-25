#include <bits/stdc++.h>
using namespace std;

int K, N, R, T;
vector<int> S;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	cin >> K;
	for (int j = 0; j < K; j++)
	{
		cin >> N >> R >> T;
		S.resize(N);
		for (int i = 0; i < N; i++) cin >> S[i];

		long long sum = 0;
		for (auto &x : S)
			sum += x;

		if ((sum/N) >= (R+T))
			cout << "Cheater" << endl;
		else
			cout << "Innocent" << endl;

	}
	return 0;
}
