#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M, R, G, B;
    cin >> N >> M >> R >> G >> B;
    
    if (R > G + 1 || G > R + 1) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (((i + j) % 2 == 0) ^ (R < G) ? 'R' : 'G');
        }
        cout << endl;
    }

    return 0;
}
