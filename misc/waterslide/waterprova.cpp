#include <bits/stdc++.h>
using namespace std;

bool giaPushato[1000000];
queue<int> coda;
vector<vector<int>> grafo;
long double *value;
int N, M, P;

void walk(int n)
{
	int div = grafo[n].size();

	for (int i = 0; i < div; i++)
	{
		if (!giaPushato[grafo[n][i]])
		{
			giaPushato[grafo[n][i]] = true;
			coda.push(grafo[n][i]);
		}
		value[grafo[n][i]] += value[n] / div;
	}

	while (!coda.empty())
	{
		int prossimo = coda.front();
		coda.pop();
		walk(prossimo);
	}
}

int main()
{

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin >> N >> M >> P;

	grafo.assign(N, vector<int>());
	value = new long double[N];
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
	}

	value[0] = 1;
	for (int i = 1; i < N; i++)
	{
		value[i] = 0;
	}
	giaPushato[0] = true;

	walk(0);

	cout << distance(value, max_element(value + N - P, value + N));

	return 0;
}