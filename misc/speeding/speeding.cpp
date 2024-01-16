#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPermutations(vector<int> &A, vector<int> &B, int N)
{
    int p = 0;
    sort(B.begin(), B.end());

    int doppioni = 0;
    
    do
    {
        bool valid = true;

        for (int i = 0; i < N; i++)
        {
            cout << B[i] << " ";
        }
        //for (int i = 0; i < N; i++)
        //{
        //    if (A[i] < B[i])
        //    {
        //        valid = false;
        //        break;
        //    }
        //}
        
        if (valid) p++;
        cout << "\n";
    } while (next_permutation(B.begin(), B.end()));

    return p;
}

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int r = findPermutations(A, B, N);

    cout << r << endl;
    return 0;
}
