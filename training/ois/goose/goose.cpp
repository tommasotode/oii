#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> salti;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    salti.resize(N);
    for (int i = 0; i < N; i++)
        cin >> salti[i];

    for (int dado = 1; dado <= 6; dado++)
    {
        int tiri = 0, cella = 0;

        while (cella < N)
        {
            if (salti[cella] != 0)
            {
                cella += salti[cella];
                continue;
            }

            cella += dado;
            cella += salti[cella];
            tiri++;
        }

        cout << tiri << " ";
    }

    cout << endl;
    return 0;
}