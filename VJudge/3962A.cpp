#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int x[110],y[110];

int main()
{
    int t,n,m;
    int i,j,key,temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&m);
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for(i=0;i<n;i++)    scanf("%d%d", &x[i],&y[i]);
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>i;j--)
            {
                if(y[i]>y[j])
                {
                    temp=y[i];
                    y[i]=y[j];
                    y[j]=temp;
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }
            }
        }
        key=0;
        for(i=n-1;i>0;i--)
        {
            if(x[i]>x[i-1]) key++;
        }
        if(key*400+x[0]>m)   printf("NO\n");
        else    printf("YES\n");
    }
    return 0;
}
