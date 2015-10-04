#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
#define bug(x) cout<<#x<<'='<<x<<endl;
#define Min 1e-7
const int maxn = 1e4+4;
const int maxe = 1e5+5;

struct Ponds
{
    double cap,now;
};

typedef Ponds Pants;

Pants P[maxn];
int N,K;

vector<int> son[maxn];

int St,Tar,Amount;
int in[maxn];
queue<int> q;

void topo()
{
    P[St].now += Amount;
    q.push(St);
    for(int i = 1; i <= N; i++) if(!in[i] && i!= St) q.push(i);

    while(q.size())
    {
        int u = q.front();
        q.pop();
        Pants &p = P[u];
        if(p.now - p.cap > 0)
        {
            if(son[u].size())
            {
                double each = (p.now-p.cap)/son[u].size();
                p.now = p.cap;
                for(int i = 0; i < son[u].size(); i++)
                {
                    int v = son[u][i];
                    P[v].now += each;
                    if(--in[v] == 0 ) q.push(v);
                }
            }
            else
            {
                p.now = p.cap;
            }
        }

    }

}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i = 1; i <= N; i++)
    {
        scanf("%lf%lf",&P[i].cap,&P[i].now);
    }
    for(int i = 0; i < K; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        son[u].push_back(v);
        in[v]++;
    }

    scanf("%d%d%d",&St,&Amount,&Tar);

    topo();
    printf("%lf",P[Tar].now);
    return 0;
}
