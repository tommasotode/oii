#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int N, X;
	cin >> N >> X;

	vector<int> L(N);
	for (int i = 0; i < N; i++) cin >> L[i];

	sort(L.rbegin(), L.rend());

	int minuti = 0;
	for (int i = 0; i < N; i++)
	{   
		if ( (L[i] + L[i+1]) <= X) i++;
		minuti++;
	}

	cout << minuti << endl;
	return 0;
}
