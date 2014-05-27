#include  <stdio.h>
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
        printf("%d\n", key);
    }
    return 0;
}
