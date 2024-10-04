#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int N, vector<int> T)
{
    vector<int> res;
    vector<pair<int,int>> S(N);
    for (int i = 0; i < N; i++)
    {
        S[i].first = T[i];
        S[i].second = i;
    }
    sort(S.begin(), S.end());

    int l = S[0].second;
    int r = S[0].second;
    res.push_back(S[0].second);
    int anno = 0;
    for (int i = 1; i < N; i++)
    {
        while (S[i].second < l)
        {
            l--;
            anno++;
            res.push_back(S[i].second);
        }
        while (S[i].second > r)
        {
            r++;
            anno++;
            res.push_back(S[i].second);
        }
        if (anno > S[i].first) 
        {
            return {};
        }
    }
    return res;
}

int main() {
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