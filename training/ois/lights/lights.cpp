#include <bits/stdc++.h>
using namespace std;

int sliding(int N, int C, const vector<int> &L)
{
    int res = INT_MAX;

    unordered_map<int, int> colors;
    int count = 0;
    int l = 0;
    for (int r = 0; r < N; ++r)
    {
        if (colors[L[r]] == 0)
            count++;
        colors[L[r]]++;

        while (count == C)
        {
            res = min(res, r - l + 1);
            colors[L[l]]--;
            if (colors[L[l]] == 0)
                count--;
            l++;
        }
    }

    return res;
}

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i];

    cout << shortestSegmentWithAllColors(N, C, L) << endl;
    return 0;
}