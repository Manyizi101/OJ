#include   <stdio.h>


int main()
{
    int n, i, ans= 0 , a[100];
    while(scanf("%d", &n) && n != 0)
    {
        ans = 0;
        for (i = 0; i < n; i++)
        {
                scanf("%x", &a[i]);
                ans += a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
