#include <stdio.h>
#include <stdbool.h>
#include <vector>
#define MAXN 100000
using namespace std;

struct nodo
{
	bool calc;
	float p;									
	int t;
	vector<struct nodo *> prev;
} nodes[MAXN];

int n, m, p, i, a, b, mam, inde;

void calculate(nodo &a)
{
	if (a.calc)
		return;
	for (int i = 0; i < a.prev.size(); i++)
	{
		calculate(*(a.prev[i]));
		a.p += (float)(a.prev[i]->p) / (float)(a.prev[i]->t);
	}
	a.calc = true;
	return;
}

int main()
{
	FILE *fr, *fw;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	fscanf(fr, "%d %d %d", &n, &m, &p);

	for (i = 0; i < m; i++)
	{
		fscanf(fr, "%d %d", &a, &b);
		nodes[b].prev.push_back(&nodes[a]);
		nodes[a].t++;
	}

	nodes[0].p = 1;
	nodes[0].calc = true;

	for (i = n - p; i < n; i++)
	{
		calculate(nodes[i]);
	}

	for (i = n - p; i < n; i++)
	{
		if (mam < nodes[i].p)
		{
			mam = nodes[i].p;
			inde = i;
		}
	}

	fprintf(fw, "%d", inde);

	fclose(fr);
	fclose(fw);

	return 0;
}