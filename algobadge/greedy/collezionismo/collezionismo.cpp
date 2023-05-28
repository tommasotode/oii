#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

void solve(int t)
{
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i=0; i<N; i++)
	{
        cin >> C[i];
    }
	int occupati = 0;
	int somma = 0;

	// devo guardare quanto posso spingermi prima che non convenga più

	/*	esempio:
		4 2
		7 9 3 1
	
	-> 9 7 3 1

	posso spingermi da 9 fino a 7 e la differenza sarà 2
	però, se mi spingo fino a 3 la differenza sarà 4, che è minore dalla differenza fra 3 e quello dopo
	
	appena finisco di spingere aumento gli occupati

	quando gli occupati sono al massimo vado avanti, ho già preso i più grossi e gli altri saranno più vicini fra loro immagino


		6 3
		4 42 23 0 21 2

		-> 42 23 21 4 2 0

		da 42 provo a spingermi a 23
		42 - 23 < 23 - 21? no -> occupati++ -> somma += distanza fra 42 e 42

		
	*/

	// se occupati raggiunge K, tutti quelli da li in poi li sommo
	sort(C.begin(), C.end(), greater<int>());
	for(int i=0; i<N-2; i=i+2)
	{
		if(occupati == K)
		{
			somma = somma + abs(C[i] - C[i+2]);
		}
		else
		{
			if(abs(C[i] - C[i+1]) <= abs(C[i+1] - C[i+2]))
			{
				somma = somma + abs(C[i] - C[i+1]);
			}
			else
			{
				somma = somma + abs(C[i+1] - C[i+2]);
				occupati++;
			}
		}
	}

    cout << "Case #" << t << ": " << somma << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
	{
        solve(t);
    }

    return 0;
}