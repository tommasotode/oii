#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int N, vector<int> T)
{
    vector<int> res(N);

    vector<pair<int, int>> S(N);
    for (int i = 0; i < N; i++)
        S[i] = {T[i], i};
    sort(S.begin(), S.end());

    int l = S[0].second;
    int r = S[0].second;
    int anno = 0;
    res[0] = l;
    for (int i = 1; i < N; i++)
    {
        if (l == S[0].second && r == S[N - 1].second)
            break;

        while (S[i].second < l)
        {
            l--;
            anno++;
            res[anno] = l;
        }
        while (S[i].second > r)
        {
            r++;
            anno++;
            res[anno] = r;
        }

        if (anno > S[i].first)
            return {};
    }
    return res;
}

int main()
{
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    vector<int> P = verifica(N, T);

    cout << P.size() << '\n';
    for (int i = 0; i < P.size(); i++)
        cout << P[i] << ' ';
    cout << '\n';
}