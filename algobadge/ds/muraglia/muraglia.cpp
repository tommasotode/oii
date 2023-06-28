#include <utility>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> muri;

void inizializza(int N, vector<int> H)
{
	muri = vector<int>(N);
	
	for (int i = 0; i < H.size(); i++)
	{
		muri[i] = H[i];
	}	
	return;
}

pair<int, int> chiedi(int x)
{
	int left = x;
	int right = x;
	
	for (int i = x; i < muri.size(); i++)
	{
		if (muri[i] > muri[x] || i == muri.size()-1)
		{
			right = i;
			break;
		}
	}

	for (int j = x; j >= 0; j--)
	{
		if (muri[j] > muri[x] || j == 0)
		{
			left = j;
			break;
		}	
	}
	
	return {left, right};
}

void cambia(int x, int h)
{
	muri[x] = h;
	return;
}







// static int R;
// static vector<int> risultato1;
// static vector<int> risultato2;

// void inizializza(int N, vector<int> H);

// pair<int, int> chiedi(int x);
// void cambia(int x, int h);

// void leggi_eventi(int M)
// {
// 	for (int i = 0; i < M; i++)
// 	{
// 		char tipo;
// 		cin >> tipo;

// 		if (tipo == 'Q')
// 		{
// 			int x;
// 			cin >> x;
// 			pair<int, int> risultato = chiedi(x);
// 			risultato1[R] = risultato.first;
// 			risultato2[R] = risultato.second;
// 			R++;
// 		}
// 		else
// 		{
// 			int x, h;
// 			cin >> x >> h;
// 			cambia(x, h);
// 		}
// 	}
// }


// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	int N, M;
// 	cin >> N >> M;

// 	vector<int> H(N);
// 	risultato1.resize(M);
// 	risultato2.resize(M);

// 	for (int i = 0; i < N; i++)
// 	{
// 		cin >> H[i];
// 	}
	
// 	inizializza(N, H);
// 	leggi_eventi(M);

// 	for (int i = 0; i < R; i++)
// 	{
// 		cout << risultato1[i] << ' ' << risultato2[i] << '\n';
// 	}

// 	return 0;
// }