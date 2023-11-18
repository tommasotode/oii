#include <bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << -1 << endl;
		return 0;
	}

	int ones = (3 - N % 3) % 3;
	for (int i = 0; i < N - ones; i++)
		cout << 5;
	for (int i = 0; i < ones; i++)
		cout << 1;

	cout << endl;
	return 0;
}
