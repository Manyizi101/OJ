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

const int MAXN = 4;
int p[MAXN], a, b;
int v[32000];

bool cal(int x)
{
    //cout << x << endl;
    if (((((x % p[0]) % p[1]) % p[2]) % p[3]) == x)    return true;
    else return false;
}

int main()
{
    while (~scanf("%d%d%d%d%d%d", &p[0], &p[1], &p[2], &p[3], &a, &b))
    {
        memset(v, 0, sizeof(v));
        int ans = 0;
        do
        {
            for (int i = a; i <= b; i++)
            {
                if (cal(i) && v[i] == 0)
                {
                    v[i] = 1;
                    ans++;
                }
            }
            //cout << p[0] << endl;
        }
        while (next_permutation(p, p + 3));
        cout << ans << endl;
    }
    return 0;
}