void initialize(int v[], int size)
{
	for (int i = 0; i < size; i++)
		v[i] = i;
}

bool dsu_find(int v[], int a, int b)
{
	return (v[a] == v[b]);
}

void dsu_union(int v[], int size, int a, int b)
{
	int root = v[a];
	for (int i = 0; i < size; i++)
	{
		if (v[i] == root)
			v[i] = v[b];
	}
}