#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }

    bool ok = true;
    for (auto &x : m)
    {
        if (x.second > 1)
        {
            if (!ok)
            {
                cout << "YES" << endl;
                return 0;
            }

            ok = false;
        }
    }

    cout << "NO" << endl;
    return 0;
}
