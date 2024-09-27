#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    int count = C;
    while (count < N)
    {
        int i = 0;
        while (i < N-count)
        {
            set<int> s;
            for (int j = i; j < i+count; j++)
                s.insert(L[j]);

            if (s.size() == C){
                cout << count << endl;
                return 0;
            }
            i++;
        }
        count++;
    }

    cout << count << endl;
}
