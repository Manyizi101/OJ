#include <stdio.h>
using namespace std;

int main()
{
    int m,n,i,ans=0;
    scanf("%d%d", &m,&n);
    if(m%2==0)
    {
        for(i=m+1;i<=n;i+=2)
        {
            ans+=i;
        }
    }
    else
    {
        for(i=m;i<=n;i+=2)
        {
            ans+=i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
