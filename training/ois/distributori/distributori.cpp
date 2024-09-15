#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int rifornisci(int N, int M, int K, int D[])
{
    int km = M, c = 0;
    for (int i = 0; i < N-1; i++)
    {
        if ( (km-D[i]) < (D[i+1]-D[i]) )
        {
            c++;
            km = D[i] + M;
        }
    }
    if (km < K)
    {
        c++;
    }

    return c;
}

int D[MAXN];

int main()
{
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));

    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", rifornisci(N, M, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
