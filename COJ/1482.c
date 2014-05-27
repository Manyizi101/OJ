#include  <stdio.h>

int main()
{
    double n,i;
    while(scanf("%lf", &n))
    {
        double ans=0;
        for(i=1;i<n+1;i++)
        {
            ans+=1/i;
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}
