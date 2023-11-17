#include <bits/stdc++.h>
using namespace std;

int match_count;
vector<pair<int, int>> solve(int A, int B)
{
	vector<pair<int, int>> matches(5);
	match_count = 1;
	if (B > 52)
		return {{-1, -1}};

	matches[0].first = 11;
	matches[1].first = 11;
	A -= 33;
	if (A == 0 )
	{
		if (B > 30)
		{
			// almeno 1 vinto da B forzato
			match_count = 4;
			matches[3].first = 11;
			matches[2].first = 0;
			matches[0].second = matches[1].second = matches[3].second = 10;
			matches[2].second = 11;
		}
		else if (B > 41)
		{
			// almeno 2 vinti da B forzati
			match_count = 5;
			matches[4].first = 11;
			matches[2].first = matches[3].first = 0;
			matches[0].second = matches[1].second = matches[4].second = 10;
			matches[2].second = matches[3].second = 11;
		}
		else
		{
			// 3 match vinti da A
			match_count = 3;
			matches[2].first = 11;

			for (int i = 0; i < 3; i++)
			{
				int remaining = min(B, 10);
				B = max(B - remaining, 0);
				matches[i].second = remaining;
			}
		}
	}
	else if (A < 10)
	{
		if (B > 41)
		{
			// almeno 2 vinti da B forzati
			match_count = 5;
			matches[4].first = 11;
			matches[2].first = A;
			matches[3].first = 0;
			matches[0].second = matches[1].second = matches[4].second = 10;
			matches[2].second = matches[3].second = 11;
		}
		else
		{
			// 1 match vinto da B
			match_count = 4;
			if (B < 11)
				return {{-1, -1}};

			matches[3].first = 11;
			matches[2].first = A;
			matches[2].second = 11;

			B -= 11;
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
	}
	else
	{
		// 2 match vinti da B
		match_count = 5;
		if (B < 22)
			return {{-1, -1}};

		matches[4].first = 11;
		matches[2].first = 10;
		A -= 10;
		matches[3].first = A;
		matches[2].second = 11;
		matches[3].second = 11;

		B -= 22;
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