#include <bits/stdc++.h>
using namespace std;

int match_count;
vector<pair<int, int>> solve(int A, int B)
{
	vector<pair<int, int>> matches(5);
	match_count = 1;
	if (B > 52) return { {-1, -1} };

	matches[0].first = 11;
	matches[1].first = 11; // primi 2 vinti
	A -= 33;
	if (A == 0)
	{
		// 3 di seguito vinte
		match_count = 3;
		matches[2].first = 11;

		// ora bisogna riempire B con numeri minori di 10
		for (int i = 0; i < 3; i++)
		{
			int remaining = min(B, 10);
			B = max(B - remaining, 0);
			matches[i].second = remaining;
		}
	}
	else if (A < 10)
	{
		// bisogno che B vinca 1 partita in mezzo
		match_count = 4;
		if (B < 11) return { {-1, -1} };
		
		matches[3].first = 11; // ultimo match
		matches[2].first = A; // match in mezzo
		matches[2].second = 11; // partita vinta da B

		B -= 11;
		// ora bisogna riempire B in 0, 1, e 3 con quello che rimane
		for (int i = 0; i < 3; i++)
		{
			int remaining = min(B, 10);
			B = max(B - remaining, 0);
			if (i == 2)
				matches[3].second = remaining;
			else
				matches[i].second = remaining;
		}
	}
	else
	{
		// bisogno che B vinca 2 partite in mezzo
		match_count = 5;
		if (B < 22) return { {-1, -1} };
		
		matches[4].first = 11; // ultimo match
		matches[2].first = 10; // primo match intermedio
		A -= 10;
		matches[3].first = A; // secondo match intermedio
		
		matches[2].second = 11; // primo match vinto da B
		matches[3].second = 11; // secondo match vinto da B

		B -= 22;
		// ora bisogna riempire B in 0, 1, e 4 con quello che rimane
		for (int i = 0; i < 3; i++)
		{
			int remaining = min(B, 10);
			B = max(B - remaining, 0);
			if (i == 2)
				matches[4].second = remaining;
			else
				matches[i].second = remaining;
		}
	}

	return matches;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		int A, B;
		cin >> A >> B;

		vector<pair<int, int>> r = solve(A, B);
		if (r[0].first == -1)
			cout << -1 << " " << -1 << endl;
		else
			for (int i = 0; i < match_count; i++)
				cout << r[i].first << " " << r[i].second << endl;
	}

	return 0;
}
