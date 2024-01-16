#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L)
{
    int j = 0;
    int piccolo = INT_MAX;
    bool result = true;

    vector<int> newarra;
    vector<int> tmp;
    for (int i = 0; i <= N; i++)
    {
        piccolo = min(V[i], piccolo);
        if (V[i] > piccolo || i == N)
        {
            L.push_back(i - j);
            piccolo = V[i];

            for (int x = j; x < i; x++)
            {
                tmp.push_back(V[x]);
            }
            reverse(tmp.begin(), tmp.end());
            for (int n : tmp)
            {
                newarra.push_back(n);
            }
            tmp.clear();
            j = i;
        }
    }

    result = is_sorted(newarra.begin(), newarra.end());
    return result;
}
