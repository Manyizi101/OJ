#include  <stdio.h>
#include  <math.h>

int main()
{
    int n,i,j,count=0,tmp;
    int a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++)    scanf("%d", &a[i]);
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                count ++;
            }
        }
    printf("%d", count);
    return 0;
}
