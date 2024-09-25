#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<pair<int,int>> rects(N);
    for (int i = 0; i < N; ++i)
        cin >> rects[i].first;
    for (int i = 0; i < N; ++i)
        cin >> rects[i].second;

    sort(rects.begin(), rects.end());

    cout << 0 << endl;


    return 0;
}
