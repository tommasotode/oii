#include <bits/stdc++.h>
using namespace std;

set<long long> autogrill;

void inizia()
{
	return;
}

void apri(long long p)
{
	autogrill.insert(p);
	return;	
}

void chiudi(long long p)
{
	autogrill.erase(p);
	return;
}

long long chiedi(long long p)
{
	if (autogrill.empty())
		return -1;
	
	if (p < *autogrill.begin())
		return *autogrill.begin();

	if (p > *--autogrill.end())
		return *--autogrill.end();

	set<long long>::iterator up = autogrill.upper_bound(p);
	set<long long>::iterator down = autogrill.lower_bound(p);

	if (*down != p)
		down--;

	if (abs(p - *down) >= abs(p - *up))
		return *up;

	return *down;
}