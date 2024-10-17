#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;

    long long free_hours = (24 - B) + A;
    long long occupied_hours = 24 - free_hours;

    T -= free_hours;
    long long res = ((T / 24) * occupied_hours) + min(T % 24, occupied_hours);
    cout << res << endl;

    return 0;
}