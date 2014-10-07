#include  <stdio.h>

int main()
{
    int a[10010], op[102], ed[102], L, M, i, j, s = 0;
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