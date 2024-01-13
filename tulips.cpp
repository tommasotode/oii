#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

#define MAX_K 100000
#define MAX_T 1000000000 
#define INF MAX_T + 10


6 2
4 2 6 1 3 5

int N, K;
vector<int> T;

int solve(int i, int curr_K, int curr_min)
{
    if (i == N)
    {
        return curr_min;
    }

    int inclusione = solve(i+1, K, min(curr_min, T[i]));

    int nuovo = 0;

    if (curr_min < INF)
        nuovo = curr_min + solve(i+1, K+1, INF);

    return max(inclusione, nuovo);
}

int main()
{
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    cin >> N >> K;
    
    T = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    
    long long M = 0;
    
    M = solve(0, 0, INF);
    
    
    cout << M << endl;

    return 0;
}
