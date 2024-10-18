#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001

int N, dp[2][MAX_N];
vector<int> T;

int pass(int N, int i, bool previous)
{
    if (i >= N)
        return 0;

    if (dp[previous][i] != -1)
        return dp[previous][i];

    int wait = T[i] + pass(N, i + 1, false);

    int skip = INT_MAX;
    if (!previous)
        skip = pass(N, i + 1, true);

    return dp[previous][i] = min(skip, wait);
}

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    T = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
        dp[0][i] = -1;
        dp[1][i] = -1;
    }

    cout << pass(N, 0, false) << endl;
    return 0;
}