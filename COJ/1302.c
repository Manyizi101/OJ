#include   <stdio.h>

int main()
{
    long long int m,n,a;
    while(scanf("%lld%lld%lld", &m,&n,&a)!=EOF)
    {
        if(a==0)
        {
            if(m>n) printf("%lld %lld\n", n, m);
            if(n>m) printf("%lld %lld\n", m, n);
        }
        if(a==1)
        {
            if(m>n) printf("%lld %lld\n", m, n);
            if(n>m) printf("%lld %lld\n", n ,m);
        }
    }
    return 0;
}
