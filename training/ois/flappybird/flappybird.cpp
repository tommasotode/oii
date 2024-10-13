#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];


    for (int i = 0; i < N-1; i++)
    {
        if (max(A[i], A[i+1]) > min(B[i], B[i+1]))
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}