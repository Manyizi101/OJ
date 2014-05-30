#include  <cstdio>
#include  <string.h>
#include  <algorithm>

using namespace std;

int a[10010],b[10010],c[20010];

int main()
{
    int n,m;
    while(scanf("%d%d", &n, &m)==2)
    {
        int i,j,s;
        for(i=0; i<n; i++)    scanf("%d", &a[i]);
        for(i=0; i<m; i++)    scanf("%d", &b[i]);
        i=j=s=0;
        while(i<n&&j<m)
        {
            if(a[i]<b[j])
            {
                c[s]=a[i];
                s++;
                i++;
            }
            else if(a[i]>b[j])
            {
                c[s]=b[j];
                s++;
                j++;
            }
            else
            {
                c[s]=a[i];
                i++;
                j++;
                s++;
            }
        }
        if(i>=n)
        {
            for(; j<m; j++)
            {
                c[s]=b[j];
                s++;
            }
        }
        else
        {
            for(; i<n; i++)
            {
                c[s]=a[i];
                s++;
            }
        }
        for(i=0;i<s;i++)    printf("%d " ,c[s]);
        printf("\n");
    }
    return 0;
}
