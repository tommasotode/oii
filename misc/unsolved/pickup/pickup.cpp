#include <bits/stdc++.h>
using namespace std;

int A, B;
long long K;

int getSum(int n)
{
	int sum = 0;
	while (n != 0)
	{
		if (n % 10 == 0)
			return -1;
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}

int solve()
{

	int n = A;
	long long mul = 1;

	int cont = 0;
	while (cont < K)
	{
		n = A * mul;
		if (getSum(n) == B)
		{
			cont++;
			if (cont == K)
				return n;
		}

		if (mul % 10 == 9)
			mul++;
		mul++;
	}

	return 0;
}

int main()
{
	//  ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	cin >> A >> B >> K;

	int a = solve();
	cout << a << endl;
	return 0;
}