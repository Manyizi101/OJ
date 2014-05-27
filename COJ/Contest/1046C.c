#include  <stdio.h>
#include  <math.h>

int main()
{
    int T, n[10000];
    int i,k;
    scanf("%d",&T);
    for(i=0; i<T; i++)    scanf("%d", &n[i]);
    for(i=0; i<T; i++)
    {
        for(k=0; k<1000; k++)
        {
            if(n[i]>=pow(2,k)&&n[i]<pow(2,k+1))
            {
                printf("%d\n", k+1);
            }
        }
    }
    return 0;
}
