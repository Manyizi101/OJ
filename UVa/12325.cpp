#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long int n,s1,s2,v1,v2;
int t,ti=1;
long long int ans;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",ti++);
        scanf("%lld%lld%lld%lld%lld",&n,&s1,&v1,&s2,&v2);
        if(s1>s2) swap(s1,s2),swap(v1,v2);
        if(s2>50000)
        {
            ans=0;
            for(int i=0; i*s2<=n; i++)
                ans=max(ans,(n-i*s2)/s1*v1+i*v2);
            printf("%lld\n",ans);
        }
        else
        {
            if(v1*s2>v2*s1) swap(v1,v2),swap(s1,s2);
            long long ans=0;
            for(int i=0; i<=s2 && n-i*s1>=0; i++)
                ans=max(ans,(n-i*s1)/s2*v2+i*v1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
