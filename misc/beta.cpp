// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> V;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];

    // insert your code here

    cout << "YES" << endl; // print the result
    return 0;
}