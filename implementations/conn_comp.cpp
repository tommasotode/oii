#include <bits/stdc++.h>
using namespace std;

class dsu
{
private:
	int N;
	vector<int> parent;

public:
	dsu(int size)
	{
		N = size;
		parent = vector<int>(N);
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}

	void make_set(int v)
	{
		parent[v] = v;
	}

	int find_set(int v)
	{
		if (v == parent[v])
			return v;
		return find_set(parent[v]);
	}

	void union_sets(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a != b)
			parent[b] = a;
	}
};

