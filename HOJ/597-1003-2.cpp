#include<iostream>
#include<algorithm>
#include<cstdio>

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 1010;
const int size = 1000;
int n;
int father[size];
int rk[size];

//把每条边成为一个结构体，包括起点、终点和权值
struct node
{
    int val;
    int start;
    int end;
} edge[size * size / 2];

//把每个元素初始化为一个集合
void make_set()
{
    for(int i = 0; i < n; i ++)
    {
        father[i] = i;
        rk[i] = 1;
    }
    return ;
}

//查找一个元素所在的集合,即找到祖先
int find_set(int x)
{
    if(x != father[x])
    {
        father[x] = find_set(father[x]);
    }
    return father[x];
}

//合并x,y所在的两个集合：利用Find_Set找到其中两个
//集合的祖先，将一个集合的祖先指向另一个集合的祖先。
void Union(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)
    {
        return ;
    }
    if(rk[x] < rk[y])
    {
        father[x] = find_set(y);
    }
    else
    {
        if(rk[x] == rk[y])
        {
            rk[x] ++;
        }
        father[y] = find_set(x);
    }
    return ;
}

bool cmp(node a, node b)
{
    return a.val > b.val;
}

int kruskal(int n) //n为边的数量
{
    int sum = 0;
    make_set();
    for(int i = 0; i < n; i ++)    //从权最小的边开始加进图中
    {
        if(find_set(edge[i].start) != find_set(edge[i].end))
        {
            Union(edge[i].start, edge[i].end);
            sum += edge[i].val;
        }
    }
    return sum;
}

ll euler[maxn];
ll ans[maxn]= {0};
void Init()
{
    euler[1]=1;
    for(int i=2; i<maxn; i++)
        euler[i]=i;
    for(int i=2; i<maxn; i++)
        if(euler[i]==i)
            for(int j=i; j<maxn; j+=i)
                euler[j]=euler[j]/i*(i-1);
    for(int i=1; i<=maxn; ++i)
    {
        ans[i]+=ans[i-1]-euler[i]+i;
    }
}


int main()
{
    freopen("2.out","w",stdout);
    Init();
    for(n=1; n<=100; ++n)
    {
        int cnt = 0;
        for(int i = 1; i < n ; i ++)
        {
            for(int j = i+1; j <= n; j ++)
            {
                //scanf("%c %d", &y, &weight);
                //printf("%c %d ", y, weight);
                edge[cnt].start = i;
                edge[cnt].end = j;
                /*
                if(__gcd(i,j)>1)
                    edge[cnt].val = __gcd(i,j);
                else
                    continue;
                **/
                edge[cnt].val = __gcd(i,j);
                cnt ++;
            }
        }
        sort(edge, edge + cnt, cmp);
        cout << ans[n]-kruskal(cnt) << endl;
    }
}
