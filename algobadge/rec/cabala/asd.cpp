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


// caso base: arrivo alla fine
void prova(int num, int N, int M, int end, int add, vector<long long> solutions)
{
	if (isValid(num))
		solutions.push_back(N%M);
	
	if (end >= N)
		return;

	//aggiungo 3 6 o 9 a destra del numero
	num = num*10+add;

	prova(num, N, M, end+1, 3, solutions);
	prova(num, N, M, end+1, 6, solutions);
	prova(num, N, M, end+1, 9, solutions);
}

// poi chiamerò prova(3) come num

long long occulta(int N, int M)
{
	// il massimo possibile che posso avere è 9696969696969...N
	
	vector<long long> solutions;

	prova(3, N, M, 0, 3, solutions);


	unsigned long long max = 0, min = 0, result = 0;
	for (int i = 0; i < N; i++)
	{
		if (i%2 == 0)
		{
			max = max*10+9;
			min = min*10+3;
		}
		else
		{
			max = max*10+6;
			min = min*10+6;
		}
	}
	result = max;
	int i = 0;
	while (result > 0)
	{		
		// per ogni numero fra 3 6 e 9, devo provare tutti i numeri dopo
		// il caso base è quando non ci sono numeri dopo e l'ultimo numero è 3
		// nel caso in cui l'ultimo numero non sia 3, scendo di 3 finché non lo diventa
		
		// il numero è 3?
		// 		no -> sottrai 3
		//		si -> 
		// ce n'è un altro dopo?
		// 		si -> finito
		//		no -> vai a quello dopo e fai la stessa cosaa
		
		if (result%10 == 6 || result%10 == 9)
		{
			result -= 3;
		}


		result -= 3;
	}

    return *max_element(solutions.begin(), solutions.end());
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