#include  <cstdio>
using namespace std;

int main()
{
    int n,i,ans=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        if(i%10!=7&&i/10!=7&&i%7!=0)    ans+=i*i;
    }
    printf("%d", ans);
    return 0;
}
