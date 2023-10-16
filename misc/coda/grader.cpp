#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H);


vector<int> cucina2(int N, int K, int X, vector<int> H)
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


vector<int> cucina(int N, int K, int X, vector<int> H)
{
	vector<int> R(X);

	vector<int> timings = vector<int>(X, 0);
	for(auto student : H)
	{
		timings[student]++;
	}

	for (int i = 0; i < X; i++)
	{
		int coda = 0, res = 0;
		for (int sec = i; sec < X; sec++)
		{
			if (timings[sec] > (K - coda))
				coda += (K - coda);
			else
				coda += timings[sec];

			if (coda != 0)
			{
				coda--;	res++;
			}

		}
		R[i] = res;
	}

	return R;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, K, X;
	cin >> N >> K >> X;

	vector<int> H(N);
	for (int& h : H)
	{
		cin >> h;
	}

	vector<int> res = cucina(N, K, X, move(H));
	for (int r : res)
	{
		cout << r << ' ';
	}
	cout << endl;

	return 0;
}