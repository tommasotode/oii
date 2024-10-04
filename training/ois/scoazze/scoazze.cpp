#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> curr_c, C, T, Q;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N >> K;
    C.resize(N);
    curr_c.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        curr_c[i] = 0;
    }

    T.resize(K);
    Q.resize(K);
    for (int i = 0; i < K; i++)
        cin >> T[i] >> Q[i];

    uint64_t s = 0;
    for (int i = 0; i < K; i++)
    {
        if (curr_c[T[i]] + Q[i] > C[T[i]])
        {
            s += (C[T[i]] - curr_c[T[i]]);
            curr_c[T[i]] = 0;
        }
        curr_c[T[i]] = curr_c[T[i]] + Q[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (curr_c[i] > 0)
            s += (C[i] - curr_c[i]);
    }

    cout << s << endl;
    return 0;
}