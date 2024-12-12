#include <bits/stdc++.h>
using namespace std;

int mod_pow(int base, int exp, int mod)
{
  int res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp & 1)
      res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }

  return res;
}