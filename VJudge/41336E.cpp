#include  <stdio.h>
#include  <algorithm>
#include  <string.h>
#include  <iostream>
using namespace std;

int ans[250000];

int main()
{

    int l,n,m,s=0;
    int a[500],b[500],c[500],x[1000];
    int i,j;
    int t=0;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        int d=1;
        int found=0;
        t++;
        for(i=0; i<l; i++)    scanf("%d", &a[i]);
        for(i=0; i<n; i++)    scanf("%d", &b[i]);
        for(i=0; i<m; i++)    scanf("%d", &c[i]);
        memset(ans,0,sizeof(ans));
        scanf("%d", &s);
        for(i=0; i<s; i++)    scanf("%d", &x[i]);
        ans[0]=a[0]+b[0];
        for(i=0; i<l; i++)
        {
            for(j=0; j<n; j++)
            {
                ans[d] = a[i] + b[j];
                d++;
            }
        }
        sort(ans,ans+d);
        printf("Case %d:\n", t);
        for(i=0; i<s; i++)
        {
            found=0;
            for(j=0; j<m; j++)
            {
                int low=0,high=d,mid;
                while (low<=high)
                {
                    mid=(low+high)/2;
                    if ((x[i]-c[j])==ans[mid])
                    {
                        found=1;
                        break;
                    }
                    else if ((x[i]-c[j])<ans[mid]) high=mid-1;
                    else low=mid+1;
                }
            }
            if(found==1)    printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
