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

const int MAXN = 7;

int t, a[MAXN];
int ansa, ansb;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 6; i++)    scanf("%d", &a[i]);
        sort(a, a + 6);
        ansa = a[5] + a[4];
        ansb = a[1] + a[2] + a[3];
        if (ansa <= ansb)   printf("What a sad story!\n");
        else    printf("Grandpa Shawn is the Winner!\n");
    }
    return 0;
}