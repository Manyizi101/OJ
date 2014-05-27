/*
include  <stdio.h>

using namespace std;

int bone[1002], value[1002];


int main()
{
    int t,n,v,i,j,tmp,sum;
    scanf("%d", &t);
    while(t--)
    {
        sum=0;
        scanf("%d%d", &n,&v);
        for(i=0;i<n;i++)    scanf("%d", &bone[i]);
        for(i=0;i<n;i++)    scanf("%d", &value[i]);
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>i;j--)
            {
                if(bone[i]<bone[j])
                {
                    tmp = bone[i];
                    bone[i] = bone[j];
                    bone[j] = tmp;
                    tmp = value[i];
                    value[i] = value[j];
                    value[j] = tmp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(v-bone[i]>=0)
            {
                v-=bone[i];
                sum+=value[i];
            }

            if(v-bone[i]<0)
                break;
        }
        printf("%d", sum);
    }
    return 0;
}
**/

/*
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int a[1001];
    int T,M,n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d",&M,&T);
        memset(a,0,sizeof(a));
        int i = 0;
        int t[1001],v[1001];
        for(i=0; i<M; i++)    scanf("%d", &t[i]);
        for(i=0; i<M; i++)    scanf("%d", &v[i]);
        int j;
        for(j=T-t[i]; j>0; j--)
            if(a[j])
                a[j+t[i]] = max(a[j+t[i]],a[j] + v[i]);
        a[t[i]] = max(a[t[i]],v[i]);

        int ans = 0;
        for( i=1; i<=T; i++)
            ans = max(ans,a[i]);
        printf("%d\n",ans);
    }
    return 0;
}
**/

#include  <stdio.h>

using namespace std;

int bone[1002], value[1002];
int f[1002][1002]

int main()
{
    int t,n,v,i,sum;
    scanf("%d", &t);
    while(t--)
    {
        sum=0;
        scanf("%d%d", &n,&v);
        for(i=0; i<n; i++)    scanf("%d", &bone[i]);
        for(i=0; i<n; i++)    scanf("%d", &value[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                f[i][j]=max(f[i-1][j])
            }
        }
        return 0;
    }
}
