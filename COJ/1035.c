#include    <stdio.h>
#include    <stdlib.h>

int cmp( const void *a , const void *b )
{
return *(double *)a > *(double *)b ? 1 : -1;
}


int main()
{
    int n,i;
    double t[50000],average,ans;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%lf", &t[i]);
        ans+=t[i];
    }
    average = ans / n;
    qsort(t,n,sizeof(t[0]),cmp);
    printf("%.3lf\n", average);
    for(i=0;i<n;i++)
    {
        printf("%.2lf\n", t[i]);
    }
    return 0;
}
