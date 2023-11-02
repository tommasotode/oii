#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int N, K;
vector<string> S;
int lookup[MAXN][MAXN];

int find_diff(int i1, int i2)
{
	int c = 0;
	for (int i = 0; i < K; i++)
	{
		if (S[i1][i] != S[i2][i])
			c++;
	}
	return c;
}

int main()
{
	//  ifstream cin("input.txt");
	//  ofstream cout("output.txt");
	ios::sync_with_stdio(false);
	cin >> N >> K;
	S.resize(N);
	for (int i = 0; i < N; i++)
		cin >> S[i];

	cout << 42 << endl;
	return 0;
}
