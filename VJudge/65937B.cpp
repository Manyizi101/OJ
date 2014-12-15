/*
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？
*/
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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 26

struct node
{
    int x, y;
    int w;
} e[MAXN *MAXN];
int rank[MAXN];
int father[MAXN];
int sum;
int i, j, k, m, n, t;
char ch;

bool cmp(const node a, const node b)
{
    return a.w < b.w;
}

void Make_Set(int x)
{
    father[x] = x;
    rank[x] = 0;
}

int Find_Set(int x)
{
    if (x != father[x])
    {
        father[x] = Find_Set(father[x]);
    }
    return father[x];
}

void Union(int x, int y, int w)
{
    if (x == y) return;
    if (rank[x] > rank[y])
    {
        father[y] = x;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
        father[x] = y;
    }
    sum += w;
}

int main(int argc, char const *argv[])
{

    while (cin >> m && m != 0)
    {
        k = 0;
        for (i = 0; i < m; i++)
            Make_Set(i);
        for (i = 0; i < m - 1; i++)
        {
            cin >> ch >> n;
            for (j = 0; j < n; j++)
            {
                cin >> ch >> e[k].w;
                e[k].x = i;
                e[k].y = ch - 'A';
                k++;
            }
        }
        sort(e, e + k, cmp);
        sum = 0;
        for (i = 0; i < k; i++)
        {
            Union(Find_Set(e[i].x), Find_Set(e[i].y), e[i].w);
        }
        cout << sum << endl;
    }
    return 0;
}
