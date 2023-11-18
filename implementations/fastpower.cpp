#include <bits/stdc++.h>
using namespace std;

int power(int base, unsigned int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;
	if (exp == 2)
		return base * base;

	int tmp = power(base, exp / 2);
	if (exp % 2 == 0)
		return tmp * tmp;
	else
		return base * tmp * tmp;
}

int module_power(int base, int exp, int mod)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	int temp = module_power(base, exp / 2, mod);
	if (exp % 2 == 0)
		return (temp % mod * temp % mod) % mod;
	else
		return (base % mod * temp % mod * temp % mod) % mod;
}


// this is way better, still have to understand this
int mod_power(int base, int exp, int mod)
{
	int res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp & 1) // 1 if odd, 0 if even
			res = res * base % mod;
		base = base * base % mod;
		exp >>= 1; // divide by 2
	}
	return res;
}