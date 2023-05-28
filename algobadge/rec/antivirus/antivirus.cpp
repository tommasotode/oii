#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
string getPart(int i, string F, int length, int part)
{
	string result = "";
	if((i+part) > length)
	{
		return "000";
	}
	for(int j=i; j<i+part; j++)
	{
		result = result + F[j];
	}
	return result;
}

int findString(int i,  string F, int length, string toFind)
{
	if(getPart(i, F, length, toFind.length()) == "000")
	{
		return -1;
	}
	
	if(getPart(i, F, length, toFind.length()) == toFind)
	{
		return i;
	}
	
	return findString(i+1, F, length, toFind);
}

void solve(int t)
{
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;

    int M;
    cin >> M;

    string F1, F2, F3, F4;
    cin >> F1 >> F2 >> F3 >> F4;

    int p1, p2, p3, p4;
	
	// APPROCCIO DA MIGLIORARE PIU AVANTI
	for(int i=0; i<N1; i++)
	{
		string part = getPart(i, F1, N1, M);
		if(findString(0, F1, N1, part) >= 0 && findString(0, F2, N2, part) >= 0 &&
			findString(0, F3, N3, part) >= 0 && findString(0, F4, N4, part) >= 0)
		{
			p1 = findString(0, F1, N1, part);
			p2 = findString(0, F2, N2, part);
			p3 = findString(0, F3, N3, part);
			p4 = findString(0, F4, N4, part);
		}
	}
	
    cout << "Case #" << t << ": " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
	{
        solve(t);
    }
}