#include  <stdio.h>

int main()
{
    double a,ans=0;
    int n=12;
    while(n--)
    {
        scanf("%lf", &a);
        ans+=a;
    }
    printf("$%.2lf\n", ans/12);
    return 0;
}
