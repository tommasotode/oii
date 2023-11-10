#include <bits/stdc++.h>
using namespace std;
#define MAXM 200000

typedef struct
{
	float value;
	int left;
} node;

int waterslide(int N, int M, int P, int A[], int B[])
{
	node nodes[N] = {};
	nodes[0].value = 1;
	unordered_multimap<int, int> slides(M);
	for (int i = 0; i < M; i++)
	{
		slides.insert({A[i], B[i]});
		nodes[B[i]].left++;
	}

	queue<int> queue({0});
	while (queue.size() > 0)
	{
		int v = queue.front(); queue.pop();

		float split = nodes[v].value / slides.count(v);
		for (auto [it, end] = slides.equal_range(v); it != end; it++)
		{
			node &next = nodes[it->second];
			next.value += split;
			if (--next.left == 0)
				queue.push(it->second);
		}
	}

	int best = N - P;
	for (int i = best + 1; i < N; i++)
	{
		if (nodes[i].value > nodes[best].value)
			best = i;
	}
	return best;
}

int A[MAXM];
int B[MAXM];

int main()
{
	int N, M, P;

	//  ifstream cin("input.txt");
	//  ofstream cout("output.txt");
	ios::sync_with_stdio(false);
	cin >> N >> M >> P;

	for (int i = 0; i < M; i++)
	{
		cin >> A[i] >> B[i];
	}
	int r = waterslide(N, M, P, A, B);

	cout << r << endl;

	return 0;
}
