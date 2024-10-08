#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int mod_power(int base, int exp, int mod)
{
	base %= mod;
	int res = 1;
	while (exp > 0)
	{
		if (exp & 1)
			res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

class DSU
{
public:
	int N;
	vector<int> parent;
	vector<int> size;

	DSU(int n)
	{
		N = n;
		parent = vector<int>(N);
		size = vector<int>(N);
		for (int i = 0; i < N; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}

	int find_set(int v)
	{
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a != b)
		{
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};

int32_t main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int R, C, N;
	cin >> R >> C >> N;
	vector<int> rr(N), cc(N);
	for (int i = 0; i < N; ++i)
		cin >> rr[i] >> cc[i];

	DSU dsu = DSU(N);
	for (int curr = 0; curr < N; curr++)
	{
		for (int attacked = 0; attacked < N; attacked++)
		{
			if ((rr[curr] == rr[attacked] || cc[curr] == cc[attacked]) ||
					(abs(rr[curr] - rr[attacked]) == abs(cc[curr] - cc[attacked])))
			{
				dsu.union_sets(curr, attacked);
			}
		}
	}

	unordered_set<int> s;
	for (int i = 0; i < N; i++)
		s.insert(dsu.parent[i]);

	int res = mod_power(2, s.size(), MOD);
	cout << res << endl;
	return 0;
}