#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main()
{
  ifstream cin("input.txt");
  cin >> N;
  cin >> S;

  vector<vector<int>> dp(N, vector<int>(26, INT_MAX));
  for (int c = 0; c < 26; ++c)
  {
    if (S[0] == 'a' + c)
      dp[0][c] = 0;
    else
      dp[0][c] = 1;
  }

  for (int i = 1; i < N; ++i)
  {
    for (int c = 0; c < 26; ++c)
    {
      for (int p = 0; p <= c; ++p)
      {
        int cost = (S[i] == 'a' + c) ? 0 : 1;
        dp[i][c] = min(dp[i][c], dp[i - 1][p] + cost);
      }
    }
  }

  int minswaps = INT_MAX;
  int last = -1;
  for (int c = 0; c < 26; ++c)
  {
    if (dp[N - 1][c] < minswaps)
    {
      minswaps = dp[N - 1][c];
      last = c;
    }
  }

  vector<pair<int, char>> swaps;
  int curr = last;
  for (int i = N - 1; i >= 0; --i)
  {
    if (S[i] != 'a' + curr)
    {
      swaps.push_back({i, 'a' + curr});
    }

    if (i > 0)
    {
      for (int p = 0; p <= curr; ++p)
      {
        if (dp[i][curr] == dp[i - 1][p] + ((S[i] == 'a' + curr) ? 0 : 1))
        {
          curr = p;
          break;
        }
      }
    }
  }

  cout << minswaps << endl;
  reverse(swaps.begin(), swaps.end());
  for (const auto &s : swaps)
  {
    cout << s.first << " " << s.second << endl;
  }

  return 0;
}