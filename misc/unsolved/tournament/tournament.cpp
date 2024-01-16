#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> S;

int interest(int x, int y)
{
	return (abs(S[x] - S[y]) + abs(x - y));
}

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios::sync_with_stdio(false);

	cin >> N;
	S = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> S[i];

	int res = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			res = max(interest(i, j), res);

	cout << res << endl;

	return 0;
}
