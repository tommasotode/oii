#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

char s[MAXN];

int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;
	
	if (N % 2 == 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (i%2 == 0)
				s[i] = '1';
			else
				s[i] = '5';
		}
	}

	cout << s << endl;
	return 0;
}
