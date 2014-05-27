#include  <cstdio>
#include  <iostream>

int c[100000], w[100000];

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int x)
{
    while(i<=n)
    {
        c[i]+=c[i]+x;
        i+=lowbit(i);
    }
}

int sum(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=c[i];
        i-=lowbit[i];
    }
    return ans;
}

int main()
{
    int t,n,i,key=1;
    int a,b;
    char com[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0;i<n;i++)    scanf("%d", w[i]);
        while(sacnf("%s", com)&&com[0]!='E')
        {
            scanf("%d%d", &a,&b);
            if(com[0]=='A')
            {

            }
        }


        key++;
        printf("Case %d:\n", key);
    }
}
