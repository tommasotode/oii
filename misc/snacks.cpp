#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, X;
    cin >> N >> X;

    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    sort(L.rbegin(), L.rend());

    int minuti = 0;
    for (int i = 0; i < N; i++)
    {   
        if ( (L[i] + L[i+1]) > X)
        {
            minuti++;
        }
        else
        {
            minuti++;
            i++;
        }
    }

    cout << minuti << endl;
    return 0;
}
