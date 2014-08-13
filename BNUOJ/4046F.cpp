#include  <cstdio>

using namespace std;

int main()
{
    int k,i,sum;
    while(scanf("%d", &k))
    {
        if(k==0)
        {
            printf("0 0 0");
            return 0;
        }
        sum=0;
        int st=1,ed=1,Mx=-9999,p=1,tmp;
        for(int i=1; i<=k; i++)
        {
            scanf("%d", &tmp);
            sum+=tmp;
            if(sum>Mx)
            {
                Mx=sum;
                st=p;
                ed=i;
            }
            if(sum<0)
            {
                p=i+1;
                sum=0;
            }
        }
        printf("%d %d %d\n", Mx, st, ed);
    }
    return 0;
}
