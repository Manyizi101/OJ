/*
#include  <cstdio>
#include  <iostream>
#include  <string.h>
using namespace std;

int main()
{
    int p;
    scanf("%d", &p);
    flag1:while(p--)
    {
        int m,n;
        scanf("%d%d", &m,&n);
        int visited[n];
        int i=0;
        memset(visited,0,sizeof(visited));
        while(visited[i]!=1)
        {
            visited[i]=1;
            i+=m;
            i=i%n;
        }
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                printf("YES\n");
                goto flag1;
            }
        }
        printf("NO\n");
    }
    return 0;
}
**/

#include  <cstdio>
#include  <iostream>
#include  <string.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    if(b==0)    return a;
    else    return gcd(b,a%b);
}


int main()
{
    int p;
    scanf("%d", &p);
    while(p--)
    {
        long long int m,n;
        scanf("%I64d%I64d", &m,&n);
        if(gcd(m,n)==1) printf("NO\n");
        else    printf("YES\n");
    }
    return 0;
}
