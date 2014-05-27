#include  <stdio.h>
#include  <stdlib.h>

int main()
{
    int n,m[500],i;
    while(scanf("%d", &n)&&n!=0)
    {
        int average=0,sum=0,ans=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &m[i]);
            sum+=m[i];
        }
        if(sum%n!=0)
        {
            printf("Impossible\n");
            continue;
        }
        average = sum / n;
        for(i=0;i<n;i++)
        {
            ans += abs(average-m[i]);
        }
        printf("%d\n", ans/2);
    }
    return 0;
}
