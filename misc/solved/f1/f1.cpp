#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> H, V;

int main()
{
	  ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	cin >> N;
	H.resize(N);
	for (int i = 0; i < N; i++) cin >> H[i];
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	int min_h = *min_element(H.begin(), H.end());
	int min_v = *min_element(V.begin(), V.end());
	int sum_h = accumulate(H.begin(), H.end(), 0);
	int sum_v = accumulate(V.begin(), V.end(), 0);

	if (sum_h < sum_v) cout << "Hamilton" << endl;
	else cout << "Verstappen" << endl;

	if (min_h < min_v) cout << "Hamilton" << endl;
	else cout << "Verstappen" << endl;

	return 0;
}
