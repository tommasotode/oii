#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int gioca(int N, int M, vector<vector<int>> G)
{
    // Mettete qui il codice della soluzione
    return 42;
}


int main()
{
    int N, M;
    cin >> N >> M;
    assert(cin.good());

    vector<vector<int>> G(N, vector<int>(M));
    for(auto& x : G)
        for(auto& y : x)
            cin >> y;
    assert(cin.good());

    cout << gioca(N, M, G) << endl;
}
