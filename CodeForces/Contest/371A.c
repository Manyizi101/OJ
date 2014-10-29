#include  <stdio.h>
#include  <stdlib.h>

int main()
{
    int n,k,a[100];
    int i=0,t=0,s=0,z=0,x=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i]==1)  z++;
        if(a[i]==2)  x++;
    }
    if(z>x)     s=x;
    if(x>=z)    s=z;
    for(i=0;i<n-k;i++)
    {
        if(a[i]!=a[i+k])
        {
            t++;
            a[i+k]=a[i];
        }
    }
    if(s>t) printf("%d", t);
    if(t>=s)    printf("%d", s);
    return 0;
}
