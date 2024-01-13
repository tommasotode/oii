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

    int ans = 0;
    long long int sum = reduce(P.begin(), P.end());
    
    if (sum < N*K)
        ans = 1;

    else if (sum > N*K)
    {
        long long int sottrarre = sum - N*K;

        int cont = 0;
        while (sottrarre > 0)
        {
            cont++;
            auto m = max_element(P.begin(), P.end());
            int indexMax = m - P.begin();
            int max = *m;

            if (sottrarre <= max - 1)
                break;
            else
            {
                sottrarre -= max - 1;
                P[indexMax] = 0;
            }
        }
        ans = cont;
    }

    cout << ans << endl;
    return 0;
}