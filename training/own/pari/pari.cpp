#include <iostream>
using namespace std;

int main()
{
	ushort a;
	cin >> a;
	if (a&1) cout << "dispari" << endl;
	else cout << "pari" << endl;

	return 0;
}