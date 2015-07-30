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

struct node
{
    int w, h;
    void read()
    {
        scanf("%d%d", &w, &h);
    }
} a[6];

bool cmp(node a, node b)
{
    if (a.w == b.w)    return a.w < b.w;
    else return a.h < b.h;
}

int main()
{
    for (int i = 0; i < 6; i++)   a[i].read();
    sort(a, a + 6, cmp);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i].w << " " << a[i].h << endl;
    }
    return 0;

}