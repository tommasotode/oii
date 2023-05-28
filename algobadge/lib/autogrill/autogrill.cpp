#include <bits/stdc++.h>
using namespace std;
set<long long> lista;

void inizia()
{
	return;
}

void apri(long long p)
{
	lista.insert(p);
	return;	
}

void chiudi(long long p)
{
	lista.erase(p);
	return;
}

long long chiedi(long long p)
{
	if(lista.empty()) return -1;
	
	if(p < *lista.begin())
		return *lista.begin();

	if(p > *--lista.end())
		return *--lista.end();

	set<long long>::iterator big = lista.upper_bound(p);
	set<long long>::iterator small = lista.lower_bound(p);

	if(*small != p)
		small--;

	if(abs(p - *small) >= abs(p - *big))
	{
		return *big;
	}

	return *small;
}
