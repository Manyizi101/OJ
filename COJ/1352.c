#include   <stdio.h>

int main()
{
    int n, i, a[100], ans = 0, ans1 = 1;
    while(scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)         scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
        {
        if ((a[i]%2) == 1)      ans1 *= a[i];
        if ((a[i]%2) == 0)      ans += a[i];
        }
        ans = ans + ans1;
        printf("%d\n", ans);
    }
    return 0;
}
