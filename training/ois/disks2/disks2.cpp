#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int hours = A[i + 1] + (24 - B[i]);
        if (hours >= T)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
