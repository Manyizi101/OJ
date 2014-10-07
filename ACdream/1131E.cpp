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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

#define LOCAL
#define MAXN 2010

int n, ans, area = 6;
char tmp;

struct node
{
    char name[110];
    int t, region;
} movie[MAXN];

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int j = 1;
        getchar();
        scanf("%c", &movie[i].name[0]);
        while (scanf("%c[^\n]", &tmp) && tmp != '"')
        {
            movie[i].name[j++] = tmp;
        }
        movie[i].name[j] = '"';
        movie[i].name[j + 1] = '\0';
        scanf("%d%d", &movie[i].t, &movie[i].region);
    }
}

bool cmp(node x, node y)
{
    if (x.t < y.t) return true;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("1131E.in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    init();
    sort(movie, movie + n, cmp);
    ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (movie[i].region != movie[i - 1].region)
        {
            area--;
            ans++;
        }
        else
        {
            ans++;
        }
        //if(area)  break;
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        cout << movie[i].name << endl;

    for (int i = 0; i < ans; i++)
    {
        cout << movie[i].t << endl;
    }
    for (int i = 0; i < ans; i++)
    {
        cout << movie[i].region << endl;
    }
    return 0;
}