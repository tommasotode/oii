#include <bits/stdc++.h>
using namespace std;

unordered_multiset<long long int> libreria;

void aggiungi(long long int id)
{
	libreria.insert(id);
}

void togli(long long int id)
{
	libreria.erase(libreria.find(id));
}

int conta(long long int id)
{
	return libreria.count(id);
}