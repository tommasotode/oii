#include <bits/stdc++.h>
using namespace std;

#define MAXL 100010

char S1[MAXL], S2[MAXL], S3[MAXL];

int main() {
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%s", S1));
    assert(1 == scanf("%s", S2));
    assert(1 == scanf("%s", S3));

    int i1 = 0, i2 = 0, i3 = 0;
    vector<char> cs;
    vector<int> r1, r2, r3;

    while (S1[i1] != '\0' && S2[i2] != '\0' && S3[i3] != '\0')
    {
        char c = S1[i1];
        if (S2[i2] != c || S3[i3] != c)
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }

        cs.push_back(c);

        int n;
        for (n = 1; S1[++i1] == c; n++);
        r1.push_back(n);
        for (n = 1; S2[++i2] == c; n++);
        r2.push_back(n);
        for (n = 1; S3[++i3] == c; n++);
        r3.push_back(n);
    }

    if (S1[i1] != '\0' || S2[i2] != '\0' || S3[i3] != '\0')
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    for (int i = 0; i < r1.size(); i++)
    {
        int media = round((float) (r1[i] + r2[i] + r3[i]) / 3);
        for (int j = 0; j < media; j++)
            putchar(cs[i]);
    }
    putchar('\n');

    return 0;
}