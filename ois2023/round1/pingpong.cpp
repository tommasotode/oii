#include <bits/stdc++.h>
using namespace std;

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
		int C = -1, D = -1;

		vector<pair<int, int>> arr(5);
		bool error = false;
		int match = 0;

		if (B > 52)
			error = true;

		arr[0].first = 11;
		arr[1].first = 11;
		
		if (A == 0)
		{
			// 3 di seguito vinte
			match = 3;
			arr[2].first = 11;
			if (B > 10)
			{
				arr[0].second = 10;
				B -= 10;
				if (B > 10)
				{
					arr[1].second = 10;
					B -= 10;
					if (B == 10)
						arr[2].second = 10;
					else
						arr[2].second = B;
				}
				else
					arr[1].second = B;
			}
			else
				arr[0].second = B;
		}

		else if (A > 10)
		{
			// bisogno che B vinca 2 partite in mezzo
			match = 5;
			if (B < 22)
			{
				error = true;
			}
			else
			{
				arr[4].first = 11;

				arr[2].first = 10; arr[2].second = 11;

				arr[3].first = A - 10; arr[3].second = 11;

				B -= 22;
				if (B > 10)
				{
					arr[0].second = 10;
					B -= 10;
					if (B > 10)
					{
						arr[1].second = 10;
						B -= 10;
						if (B == 10)
							arr[4].second = 10;
						else
							arr[4].second = B;
					}
					else
						arr[1].second = B;
				}
				else
					arr[0].second = B;
				}
		}
		else
		{
			// bisogno che B vinca 1 partita in mezzo
			match = 4;
			if (B < 11)
			{
				error = true;
			}
			else
			{
				arr[2].first = A;
				arr[2].second = 11;
				arr[3].first = 11;

				B -= 11;
				if (B > 10)
				{
					arr[0].second = 10;
					B -= 10;
					if (B > 10)
					{
						arr[1].second = 10;
						B -= 10;
						if (B == 10)
							arr[3].second = 10;
						else
							arr[3].second = B;
					}
					else
						arr[1].second = B;
				}
				else
					arr[0].second = B;
				}
			}

		if (error == true)
		{
			cout << -1 << " " << -1 << endl;
		}
		else
		{
			for (int i = 0; i < match; i++)
			{
				cout << arr[i].first << " " << arr[i].second << endl;
			}
		}
	}

	return 0;
}
