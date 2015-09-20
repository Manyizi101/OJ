#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define inf (1<<30)
#define eps 1e-8
#define pb push_back
using namespace std;
const int maxn=110005;
struct Node
{
    int d[8];
    int step;
};
bool ok(Node& u,int p,int a,int w)
{
    for(int i=0;i<a;i++) {
        if(u.d[i]==p)
            return false;
    }
    return true;
}
bool vis[maxn*10];
int ans[8][1000000+5];
int Num(Node& u,int w)
{
    int ans=0;
    for(int i=0;i<w;i++) {
        ans=ans*w+u.d[i];
    }
    return ans;
}
int Min(Node& u,int p,int w)
{
    int me=10;
    for(int i=0;i<w;i++) {
        if(u.d[i]==p)
            me=min(me,i);
    }
    return me;
}
void gao(int w)
{
    memset(vis,0,sizeof(vis));
    Node u;
    for(int i=0;i<w;i++)
        u.d[i]=i;
    u.step=0;
    queue<Node>que;
    que.push(u);
    while(!que.empty()) {
        Node v=que.front();
        que.pop();
        int aa=Num(v,w);
        if(vis[aa])
            continue;
        ans[w][aa]=v.step;
        vis[aa]=1;
        for(int i=0;i<w;i++) {
            int pos=v.d[i];
            if(!ok(v,pos,i,w))
                continue;
            if(pos-1>=0) {
                int a=Min(v,pos-1,w);
                if(a>i) {
                    Node p;
                    for(int j=0;j<w;j++)
                        p.d[j]=v.d[j];
                    p.d[i]=pos-1;
                    p.step=v.step+1;
                    if(vis[Num(p,w)]==0)
                        que.push(p);
                }
            }
            if(pos+1<w) {
                int a=Min(v,pos+1,w);
                if(a>i) {
                    Node p;
                    for(int j=0;j<w;j++)
                        p.d[j]=v.d[j];
                    p.d[i]=pos+1;
                    p.step=v.step+1;
                    if(vis[Num(p,w)]==0)
                        que.push(p);
                }
            }
        }
    }
}
int main()
{
    memset(ans,-1,sizeof(ans));
    int a;
    for(int i=1;i<=7;i++) {
        gao(i);
        //cout<<1<<endl;
    }
    int t;
    int n;
    int d[10];
    int dis[10];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        if(n<=0) {
            printf("0\n");
            continue;
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&d[i]);
            dis[i]=d[i];
        }
        sort(dis,dis+n);
        int u=0;
        for(int i=0;i<n;i++) {
            d[i]=lower_bound(dis,dis+n,d[i])-dis;
        }
        int pp[10];
        for(int i=0;i<n;i++) {
            pp[d[i]]=i;
        }
        for(int i=0;i<n;i++) {
            u=u*n+pp[i];
        }
        printf("%d\n",ans[n][u]);
    }
    return 0;
}



