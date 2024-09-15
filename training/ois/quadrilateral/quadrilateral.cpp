#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<long long> S(N);
  for (int i = 0; i < N; ++i)
    cin >> S[i];

  sort(S.begin(), S.end());
  for (int i = 0; i <= N - 4; i++)
  {
    if (S[i] + S[i+1] + S[i+2] > S[i + 3])
    {
      cout <<S[i]<<" "<<S[i+1]<<" "<<S[i+2]<<" "<<S[i+3]<<endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}