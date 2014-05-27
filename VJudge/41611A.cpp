/*
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
**/


#include  <stdio.h>
#include  <iostream>
using namespace std;

typedef long long BIG;

BIG egcd(BIG a, BIG b, BIG *x, BIG *y)
{
    BIG d, x1, y1;
    if(b==0)
    {
        d=a;
        *x=1;
        *y=0;
    }
    else
    {
        d = egcd(b, a%b, &x1, &y1);
        *x=y1;
        *y=x1-a/b*y1;
    }
    return d;
}

int main()
{
    BIG a, b, x, y, m, n, L, d;
    while(scanf("%I64d%I64d%I64d%I64d%I64d", &x,&y,&m,&n,&L)!=-1)
    {
        a=m<n?n-m:m-n;
        b=m<n?x-y:y-x;
        b=(L+b)%L;
        d=egcd(a,L,&x,&y);
        if(b%d)
        {
            printf("Impossible\n");
        }
        else
        {
            for(x*=b/d,L/=d;x<0;x+=L);
            printf("%I64d\n",x%L);

        }
    }
    return 0;
}
