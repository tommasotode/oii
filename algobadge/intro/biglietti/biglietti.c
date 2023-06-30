#include <stdio.h>
#include <assert.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int compra(int N, int M, int A, int B)
{
	int result = -1;
	if (N <= M)
	{
		if (B > N*A)
			result = N*A;
		else
			result = B;
	}
	if (N % M == 0)
		result = ( (N/M)*B ); 
	else
		result = MIN( ((N/M)*B) + B, ((N/M)*B) + ((N%M)*A) );
	
	return MIN(result, A*N);
}

int main()
{
	FILE *fr, *fw;
	int N, M, A, B;

	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

	fprintf(fw, "%d\n", compra(N, M, A, B));
	fclose(fr);
	fclose(fw);
	return 0;
}