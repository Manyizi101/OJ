#include  <stdio.h>

int main()
{
    int n,k,i,j,a[100],tmp;
    scanf("%d%d", &n,&k);
    for(i=0;i<n;i++)    scanf("%d", &a[i]);
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[i]<a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(i=0;i<k;i++)    printf("%d\n", a[i]);
    return 0;
}
