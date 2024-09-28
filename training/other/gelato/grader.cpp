#include <bits/stdc++.h>
using namespace std;

int presta(int N, int C, vector<int> P)
{
  sort(P.rbegin(), P.rend());
  int i = 0;
  for(i; i < N; i++)
  {
    C -= P[i];
    if (C <= 0) break;
  }

  return i+1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, C;
  assert(cin >> N);
  assert(cin >> C);

  vector<int> P(N);
  for (int &p : P)
  {
    assert(cin >> p);
  }
  cout << presta(N, C, move(P)) << "\n";
}
