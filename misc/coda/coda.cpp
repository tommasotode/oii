#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X);

	sort(H.begin(), H.end());

	queue<int> q;

	for (int i = 0; i < X; i++)
	{
		int cont = 0;
		q = queue<int>();
		for (int second = i; second < X; second++)
		{
			for (int student : H)
			{
				if (second == student)
				{
					q.push(student);
				}
			}
			
			if (q.size() > 0)
			{
				q.pop(); cont++;
			}
		}
		R[i] = cont;
	}

	return R;
}