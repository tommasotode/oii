#include <bits/stdc++.h>
using namespace std;

unsigned long long potenza(long long int x, long long int p, long long int mod)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return x;
	
	long long temp = potenza(x, p/2, mod);
	if (p%2 == 0)
		return (temp % mod * temp % mod) % mod;
	else
		return (x % mod * temp % mod * temp % mod) % mod;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext)
{
	for(int i=0; i<L; i++)
		plaintext[i] = potenza(messaggio[i], d, N);

	plaintext[L] = '\0';
}
