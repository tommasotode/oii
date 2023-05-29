#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

bool isValid(unsigned long long num)
{
	short prev = -1;
	while(num > 0)
	{
		if (num % 10 == prev)
			return false;
		
		if (num%10 != 3 && num%10 != 6 && num%10 != 9)
			return false;

		prev = num % 10;
		num /= 10;
	}
	return true;	
}


long long occulta(int N, int M)
{
	// il massimo possibile che posso avere è 9696969696969...N
	
	unsigned long long max = 0, result = 0, m = 0;
	for (int i = 0; i < N; i++)
	{
		if (i%2 == 0)
			max = max*10+9;
		else
			max = max*10+6;
	}
	result = max;
	m = result % M;

	while (result > 0)
	{
		if(isValid(result) && result % M > m)
		{
			m = result % M;
		}
		result -= 3;
	}

    return m;
}


int main()
{
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++)
	{
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%d ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}