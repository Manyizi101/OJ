#include  <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n)&&n!=0)
    {
        int i,j,a[100],b[100],key1,key2;
        for(i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i]<0)  b[i]=-a[i];
            else b[i]=a[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>i;j--)
            {
                if(b[i]<b[j])
                {
                    key1 = a[i];
                    a[i] = a[j];
                    a[j] = key1;
                    key2 = b[i];
                    b[i] = b[j];
                    b[j] = key2;
                }
            }
        }
        for(i=0;i<n-1;i++)  printf("%d ", a[i]);
        printf("%d\n", a[n-1]);
    }
    return 0;
}
