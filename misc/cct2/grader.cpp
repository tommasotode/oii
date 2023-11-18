#include <bits/stdc++.h>
using namespace std;

int N, K, a, b;

int mod_power(int base, int exp, int mod)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	int temp = mod_power(base, exp / 2, mod);
	if (exp % 2 == 0)
		return (temp % mod * temp % mod) % mod;
	else
		return (base % mod * temp % mod * temp % mod) % mod;
}

int cct(int i, int k)
{
	if (i > N)
		return 0;

	int notSkipped = mod_power(a, i, 1000) + cct(i + 1, min(K, k + mod_power(b, i, K)));

	int skipped = INT_MAX;
	if (k == K)
		skipped = cct(i + 1, 0);

	return min(notSkipped, skipped);
}

int speedrunna()
{
	int r = cct(0, 0);
	return r;
}

int main()
{
	cin >> N >> K >> a >> b;
	cout << speedrunna();
}
