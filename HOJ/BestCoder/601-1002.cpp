#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int MAXN = 1000+10;
int father[MAXN*MAXN];
int a[MAXN][MAXN];
int t, n, m;
int cnt;
int flag=0;

//把每条边成为一个结构体，包括起点、终点和权值
struct node
{
    int val;
    int start;
    int end;
} edge[MAXN * MAXN * 2];

//把每个元素初始化为一个集合
void make_set()
{
    for (int i = 0; i < cnt; i ++) {
        father[i] = i;
    }
    return ;
}

//查找一个元素所在的集合,即找到祖先
int find_set(int x)
{
    if (x != father[x]) {
        father[x] = find_set(father[x]);
    }
    return father[x];
}

//合并x,y所在的两个集合：利用Find_Set找到其中两个
//集合的祖先，将一个集合的祖先指向另一个集合的祖先。
void Union(int x, int y)
{
    int fx = find_set(x);
    int fy = find_set(y);
    if (fx == fy) {
        return ;
    }
    father[fx] = fy;
    return ;
}

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int kruskal(int n) //n为边的数量
{
    int sum = 0;
    make_set();
    for (int i = 0; i < n; i ++) { //从权最小的边开始加进图中
        if (find_set(edge[i].start) != find_set(edge[i].end)) {
            Union(edge[i].start, edge[i].end);
            sum += edge[i].val;
        }
    }
    return sum;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        cnt = 0;
        memset(edge, 0, sizeof(edge));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m - 1; j++)
            {
                edge[cnt].start = (i - 1) * m + j;
                edge[cnt].end = (i - 1) * m + j + 1;
                edge[cnt].val = abs(a[i][j] - a[i][j + 1]);
                //cout << edge[cnt].val << " ";
                cnt++;
            }
            //cout << endl;
        }
        //cout << cnt << endl;
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n - 1; i++)
            {
                edge[cnt].start = (i - 1) * m + j;
                edge[cnt].end = i * m + j;
                edge[cnt].val = abs(a[i + 1][j] - a[i][j]);
                //cout << edge[cnt].val << " ";
                cnt++;
            }
            //cout << endl;
        }
        //cout << cnt << endl;
        sort(edge, edge + cnt, cmp);
        printf("Case #%d:\n", ++flag);
        printf("%d\n", kruskal(cnt));
    }
    return 0;
}