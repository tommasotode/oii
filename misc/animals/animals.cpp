#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N;
vector<int> S;

int main()
{
	ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	cin >> N;
	S.resize(N);
	for (int i = 0; i < N; i++) cin >> S[i];


	int animals = N;
	vector<bool> removed(N, false);
	for (int i = 0; i < N; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (S[i] > S[j] && !removed[j])
			{
				animals--;
				removed[j] = true;
			}
		}
	}

	cout << animals << endl;
	return 0;
}
