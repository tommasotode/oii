#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, P;
	cin >> N >> P;
	vector<array<int, 3>> S(N);
	vector<int> sums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> S[i][0] >> S[i][1] >> S[i][2];
		sums[i] = S[i][0] + S[i][1] + S[i][2] + P*100;
	}

	sort(sums.rbegin(), sums.rend());

	if ( (S[0][0] + S[0][1] + S[0][2]) > sums[1])
		cout << 0 << endl;
	else cout << (P*100) - (sums[0] - sums[1]) + 1<< endl;	

	return 0;
}
