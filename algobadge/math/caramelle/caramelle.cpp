#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//euclide
int mcd(int n1, int n2)
{
	if(n1 == 0)
		return n2;
		
	return mcd(n2 % n1, n1);
}

long long solve()
{
	int N;
	cin >> N;
	vector<int> V(N);
	for(int &x: V)
		cin >> x;
		
	long long risposta = V[0];
	for(int i=1; i<N; i++)
		risposta = (V[i] * risposta) / mcd(V[i], risposta);

	return risposta;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
	return 0;
}