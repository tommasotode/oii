#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> V, S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //  ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    S.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        if (S[i] == 0)
            V[i] = 0;
    }

    int curr_streak = V[0], max_streak = V[0];
    int i = 1;
    while (i < N)
    {
        while (V[i] >= V[i - 1])
        {
            curr_streak += V[i];
            i++;
        }
        max_streak = max(max_streak, curr_streak);
        curr_streak = V[i];
        i++;
    }

    cout << max_streak << endl;
    return 0;
}