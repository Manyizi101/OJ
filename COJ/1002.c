#include  <stdio.h>

int main()
{
    int a[10000], op[100], ed[100], L, M, i, j, s = 0;
    scanf("%d%d", &L, &M);
    for (j = 0; j <= L; j++)
        a[j] = 1;
    for (i = 0; i < M; i++)
        scanf("%d%d", &op[i], &ed[i]);
    for (i = 0; i < M; i++)
        for (j = op[i]; j <= ed[i]; j++)
                a[j] = 0;
    for (j = 0; j <= L; j++)
        s = s + a[j];
    printf("%d", s);
    return 0;
}






    /*int a[10000], b[100], c[100], L, M, i, j, s = 0;
    scanf("%d%d", &L, &M);
    for(i = 0; i <= L; i++)     a[i] = 1;
    for(i = 0; i < M; i++)     scanf("%d%d", &b[i], &c[i]);
    for(i = 0; i < M; i++)
        for(j = b[i]; j <= c[i]; j++)
            a[j] = 0;
    for(i = 0; i <= L; i++)     s = s + a[i];
    printf("%d", s);
    return 0;**/
}
