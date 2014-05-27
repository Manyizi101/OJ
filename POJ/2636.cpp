#include  <cstdio>
using namespace std;

int main()
{
    int N,K,O,ans;
    int i;
    scanf("%d", &N);
    while(N--)
    {
        ans=0;
        scanf("%d", &K);
        for(i=0;i<K;i++)
        {
            scanf("%d", &O);
            ans+=O;
        }
        printf("%d\n", ans-K+1);
    }
    return 0;
}
