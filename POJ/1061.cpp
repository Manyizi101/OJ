/*
#include  <cstdio>
#include  <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b?gcd(b, a%b):a;
}


int main()
{
    long long int x,y,m,n,l;
    scanf("%I64d%I64d%I64d%I64d%I64d", &x,&y,&m,&n,&l);
    for(int i=0; i<m*n/gcd(m,n)*l; i++)
    {
        if((x+m*i)%l==(y+n*i)%l)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}
**/

/*
#include  <cstdio>
#include  <iostream>
using namespace std;

long long int exGcd(long long int a,long long int b, long long int x, long long int y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long int r=exGcd(b,a%b,x,y);
    long long int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}


int main()
{
    long long int x,y,m,n,l;
    long long int c=0,i=0;
    scanf("%I64d%I64d%I64d%I64d%I64d", &x,&y,&m,&n,&l);
    printf("%I64d", exGcd(l,n-m,c,i));
    return 0;
}
**/

#include  <cstdio>
#include  <iostream>
using namespace std;

void gcdEx(const long long int a, const long long int b, long long int &x,long long int &y)
{
    if(b)
    {
        gcdEx(b,a%b,y,x);
        y-=(long long int)(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
}

int main()
{
    long long int x,y,m,n,l;
    long long int i=4,a;
    scanf("%I64d%I64d%I64d%I64d%I64d", &x,&y,&m,&n,&l);
    gcdEx(m+n,1,i,a);
    printf("%I64d",i);
    return 0;
}
