#include  <cstdio>
#include  <iostream>

using namespace std;

int main()
{
    int t,i;
    long long int n,b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&b);
        for(i=0;i<9973;i++)
        {
            if(i*b%9973==n)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
