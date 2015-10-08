#include <cstdio>

int N;
const int NV=1e7+10;
int c[NV];

inline int lowbit(int t)
{
    return t&(-t);
}

void update(int x,int v)
{
    while(x<=N) {
        c[x]+=v;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int ans=0;
    while(x>0) {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}

int n,m;

int main()
{
    int tmp,x,y;
    int flag = 0;
    scanf("%d%d", &n,&m);
    N = 1e7+9;
    for(int i=0; i<n; ++i) {
        scanf("%d", &tmp);
        if(tmp)
            update(tmp,1);
        else
            flag = 1;
    }
    int tt = 0;
    for(int i=0; i<m; ++i) {
        scanf("%d%d", &x,&y);
        if(flag && x<=0&&y>=0)  tt=1;
        printf("%d\n", query(y)-query(x-1)+tt);
    }
}
