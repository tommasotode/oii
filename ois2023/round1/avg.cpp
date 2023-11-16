#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    uint64_t sum = 0;
    uint64_t prod = N * K;
    for (int i = 0; i < N; i++) sum += P[i];

    int ans = 0;
    if (sum < prod) ans = 1;
    else if (sum > prod)
    {
        sort(P.begin(), P.end());
        uint64_t to_remove = sum - prod;

        int i = 0;
        for (i; i < N; i++)
        {
            if (to_remove <= P[i] - 1)
                break;
            else
                to_remove -= P[i] - 1;
        }
        ans = i + 1;
    }

    cout << ans << endl;
    return 0;
}
