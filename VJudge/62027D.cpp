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

#define MAXN 100000+10

int sum1[MAXN], sum2[MAXN], oc, tc, ans[MAXN];
int n, v, a, b, maxv, c1, c2;

struct node
{
    int id,val;
} one[MAXN], two[MAXN];

bool cmp(node x, node y)
{
    return x.val > y.val;
}

void init()
{
    scanf("%d%d", &n, &v);
    oc = tc = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &a, &b);
        if(a == 1)
            one[++oc].val = b, one[oc].id = i;
        else
            two[++tc].val = b, two[tc].id = i;
    }
    sort(one+1, one + oc + 1, cmp);
    sort(two+1, two + tc + 1, cmp);
}


int main(int argc, char const *argv[])
{
    init();
    sum2[0] = sum1[0] = 0;
    for(int i=1; i<=tc; i++) sum2[i] = sum2[i - 1] + two[i].val;
    for(int i=1; i<=oc; i++) sum1[i] = sum1[i - 1] + one[i].val;
    c1 = -1, c2 = -1, maxv = -1;
    for(int i=0; i<=oc; i++)
    {
        if(i > v)
            break;
        int d = sum1[i] + sum2[min((v - i) / 2, tc)];
        if(d > maxv)
        {
            maxv = d;
            c1 = i;
            c2 = min((v - i) / 2, tc);
        }
    }
    if(maxv == -1)
    {
        printf("0\n");
        return 0;
    }
    int cnt = 0;
    printf("%d\n", maxv);
    for(int i=1; i<=c1; i++) ans[++cnt] = one[i].id;
    for(int i=1; i<=c2; i++) ans[++cnt] = two[i].id;
    for(int i=1; i<=cnt; i++)
        printf("%d%c", ans[i], i == cnt? '\n' : ' ');
    return 0;
}


/*
5 3
1 9
2 9
1 9
2 10
1 6

24
3 1 5
**/
