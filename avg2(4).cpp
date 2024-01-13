#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    uint64_t N;
    uint64_t K;
    cin >> N >> K;

    vector<uint64_t> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];


    uint64_t media = N * K;
    uint64_t somma = 0;
    for (int i = 0; i < N; i++) somma += P[i];

    uint64_t C = 0;

    if (somma < media)
    {
        C = (uint64_t)ceil(((double)media - (double)somma) / (double)N);
    }
    
    while (somma > media)
    {
        for (int i = 0; i < N; i++)
        {
            if (somma == media)
                break;

            if (P[i] > 1)
            {
                P[i]--;
                somma--;
            }
        }
        C++;
    }

    
    cout << C << endl;

    return 0;
}