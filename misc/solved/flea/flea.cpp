#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
string S;

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

	cin >> N;
	cin >> S;

	int r = 0;

	for (int i = 0; i < N; i++)
	{
		if (S[i] == 'R') r++;
		else r--;
	}
	// insert your code here

	cout << abs(r) << endl;
	return 0;
}
