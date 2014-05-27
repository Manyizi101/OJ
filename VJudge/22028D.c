/*#include  <stdio.h>
#define  MAX  1000000

int a[MAX];

int main()
{
    int n=0;
    while(scanf("%d", &n)!=EOF)
    {
        int i=0,time=0,key;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(time == 0)
            {
                key = a[i];
                time = 1;
            }
            else if(key == a[i])
            {
                ++time;
            }
            else
            {
                --time;
            }
        }
        printf("%d", key);
    }
    return 0;
}
**/

#include  <stdio.h>
#define  MAX  1000000

int a[MAX], b[1000],c[1000];

int main()
{
    int n=0,big=1;
    while(scanf("%d", &n)!=EOF)
    {
        int i,j;
        for(i=0;i<1000;i++)
        {
            b[i]=c[i]=0;
        }
        scanf("%d", &a[0]);
        b[0] = a[0];
        c[0] = 1;
        for(i=1; i<n; i++)
        {
            scanf("%d", &a[i]);
            for(j=0; j<big; j++)
            {
                if(a[i]!=b[j])
                {
                    b[j] = a[i];
                    c[j]++;
                    big++;
                }
                if(a[i]==b[j])
                {
                    c[j]++;
                }
            }
        }
        for(i=0;i<big;i++)
        {
            if(c[i]>=(n+1)/2)
            {
                printf("%d\n", b[i]);
                break;
            }
        }
    }
    return 0;
}
