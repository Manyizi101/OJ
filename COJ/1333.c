#include       <stdio.h>

int main()
{
    int t,n,i,j,ans;
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
        {
            ans+=j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
