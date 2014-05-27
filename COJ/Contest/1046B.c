#include  <stdio.h>
#include  <math.h>

int main()
{
    int T,ans[21];
    int a[21],b[21],c[21];
    int i;
    scanf("%d", &T);
    for(i=0;i<T;i++)    scanf("%d%d%d", &a[i],&b[i],&c[i]);
    for(i=0;i<T;i++)
    {
        ans[i] = ceil(c[i]*(double)(a[i]-(a[i]+b[i])/3.0)/(double)((a[i]+b[i])/3.0));
        printf("%d\n", ans[i]);
    }
    return 0;
}
