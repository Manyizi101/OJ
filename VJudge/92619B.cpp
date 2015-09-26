#include <cstdio>
#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
using namespace std;
const int N = 305;
typedef long long LL;

const int maxn = 50;

int t;
int n,m,k;

struct node
{
    int id,c;
}a[maxn];

bool cmp(node a,node b)
{
    return a.c>b.c;
}

int mp[6][6];
int b[maxn*maxn];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n,&m,&k);
        for(int i=0;i<k;++i)
        {
            a[i].id = i+1;
            scanf("%d", &a[i].c);
        }
        sort(a,a+k,cmp);
        int cnt=0;
        for(int i=0;i<k;++i)
        {
            while(a[i].c)
            {
                b[cnt++]=a[i].id;
                a[i].c--;
            }
        }
        for(int i=0;i<cnt;++i)  cout<<b[i];
        cout<<endl;
    }
    return 0;
}
