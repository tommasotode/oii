#include <bits/stdc++.h>

using namespace std;

int N, i;
vector<int> D;

int main()
{
    //  ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    D.resize(N);
    for (int i = 0; i < N; i++)
        cin >> D[i];

    sort(D.begin(), D.end());
    int prev = INT_MIN;
    for (auto i : D)
    {
        if (i == prev)
        {
            cout << "Impossible";
            return 0;
        }
        prev = i;
    }

    cout << "Ok";
    return 0;
}
