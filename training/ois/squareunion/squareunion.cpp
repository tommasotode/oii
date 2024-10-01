#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    uint64_t N;
    cin >> N;
    vector<pair<uint64_t, uint64_t>> rects(N);
    for (int i = 0; i < N; ++i)
        cin >> rects[i].second;
    for (int i = 0; i < N; ++i)
        cin >> rects[i].first;
    
    // first : raggio
    // second : centro

    unordered_map<uint64_t, uint64_t> m;
    for (auto &r : rects)
    {
        for (int j = r.second - r.first; j < r.second + r.first; j++)
        {
            if (m[j] < r.first)
                m[j] = r.first;
        }
    }

    uint64_t sum = 0;
    for (const auto &[k, v] : m)
        sum += v;

    cout << sum * 2 << endl;
    return 0;
}