#include   <stdio.h>

int main()
{
    int T, i, n[100], m[100];
    float  ans = 0.0, sub = 0.0;
    scanf("%d", &T);
    for (i = 0; i < T; i++)     scanf("%d%d", &n[i], &m[i]);
    for (i = 0; i < T; i++)
    {
        ans += n[i]*m[i];
        sub += n[i];
    }
    printf("%.2f", ans/sub);
    return 0;
}
