#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> L;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    L.resize(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    int alphabet = 26;
    int underscores = 0;
    int res = 1;

    for (int i = 0; i < N; i++)
        if (L[i] != '_')
            alphabet--;
        else
            underscores++;

    for (int i = 0; i < underscores; i++)
    {
        res *= alphabet;
        alphabet--;
    }

    cout << res << endl;

    return 0;
}