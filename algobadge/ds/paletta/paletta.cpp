// parto dalla fine e provo a ordinare tutti quanti piano piano, arrivo alla fine
// è ordinato?
//	si -> finito
//	no -> return -1

#include <bits/stdc++.h>
using namespace std;



long long paletta_sort(int N, int V[])
{
	int c = 0;
	for(int i=N-3; i>=0; i--)
	{
		if(V[i] > V[i+2])
		{
			swap(V[i], V[i+2]);
			c++;
		}
	}

    if(is_sorted(V, V+N))
		return c;
	
	
	// quando raggiungi l'inizio dell'array, is_sorted?
	// si -> returna n
	// no -> returna -1

	return -1;
}

