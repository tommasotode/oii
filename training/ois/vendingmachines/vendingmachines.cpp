#include <bits/stdc++.h>
using namespace std;

bool hacker(vector<int>& P, vector<int>& L, int N, int Q)
{
    int sum = 0;
    for (int i = 0; i < Q; i++)
    {
        if (L[i] >= 0)
            sum += L[i];
        else
            sum -= P[abs(L[i])-1];
        if (sum < 0)
            return true;
    }
    return false;
}

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, Q;
        cin >> N >> Q;
        vector<int> P(N), L(Q);
        for (int i = 0; i < N; i++)
            cin >> P[i];
        for (int i = 0; i < Q; i++)
            cin >> L[i];

        bool h = hacker(P, L, N, Q);
        if (h) {
            cout << "HACKER" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}
